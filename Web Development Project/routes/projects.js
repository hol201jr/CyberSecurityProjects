const express = require('express')
const { redirect } = require('express/lib/response')
const project = require('../models/project')
const router = express.Router()
const Project = require('../models/project')
const Test = require('../models/test')

//All projects route
router.get('/', async (req,res) => {
  let searchOptions = {}
  if(req.query.name != null && req.query.name !==''){
    searchOptions.name = new RegExp(req.query.name,'i')
  }
  try{
    const projects = await Project.find(searchOptions)
    res.render('projects/index', { 
      projects: projects,
      searchOptions: req.query
    })
  } catch {
    redirect('/')
  }
  
})

//new project route
router.get('/new', (req,res)=>{
  res.render('projects/new', {project: new project()})
})

//create project route
router.post('/', async (req,res)=>{
  const project = new Project({
    name: req.body.name
  })
  try{
    const newProject = await project.save()
    res.redirect(`projects/${newProject.id}`)
  } catch {
    res.render('projects/new', {
    project: project,
    errorMessage: 'Error creating project'
    })
  }
})

router.get('/:id', async (req,res)=> {
  try {
    const project = await Project.findById(req.params.id)
    const tests = await Test.find({ project: project.id}).limit(6).exec()
    res.render('projects/show', {
      project: project,
      testsByProject: tests
    })
  } catch {
    console.log(err)
    res.redirect('/')
  }
})

router.get('/:id/edit', async (req,res)=>{
  try {
    const project = await Project.findById(req.params.id)
    res.render('projects/edit', {project: project })
  } catch {
    res.redirect('/projects')
  }
  res.render('projects/edit', {project: new project()})
})

//update project
router.put('/:id', async (req,res)=>{
  let project
  try{
    project = await Project.findById(req.params.id)
    project.name = req.body.name
    await project.save()
    res.redirect(`/projects/${project.id}`)
  } catch {
    if (project == null){
      res.redirect('/')
    } else {
      res.render('projects/edit', {
      project: project,
      errorMessage: 'Error updating project'
    
      })
    }
  }
})

router.delete('/:id', async (req,res)=>{
  let project
  try{
    project = await Project.findById(req.params.id)
    await project.remove()
    res.redirect('/projects')
  } catch {
    if (project == null){
      res.redirect('/')
    } else {
      res.redirect(`projects/$(project.id)`)
    }
  }
})

module.exports = router