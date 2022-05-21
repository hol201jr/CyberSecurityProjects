const express = require('express')
const { redirect, render } = require('express/lib/response')
const router = express.Router()
const Test = require('../models/test')
const Projects = require('../models/project')

//All tests route
router.get('/', async (req,res) => {
  let searchOptions = {}
  if(req.query.testid != null && req.query.testid !==''){
    searchOptions.testid = new RegExp(req.query.testid,'i')
  }
  try{
    const tests = await Test.find(searchOptions)
    res.render('tests/index', {
      tests: tests,
      searchOptions: req.query
    })
  } catch {
    console.log("REDIRECT ERROR")
    redirect('/')
  }
  res.render('tests/index')
})

//new test route
router.get('/new', async (req,res)=>{
  try {
    const projects = await Projects.find({})
    const test = new Test()
    res.render('tests/new', {
      projects: projects,
      test: test
    })
  } catch {
    console.log("broken route tests/new")
    res.redirect('/tests')
  }
})

//create test route
router.post('/', async (req,res)=>{
  const test = new Test({
    project: req.body.project,
    testid: req.body.testid,
    date: new Date(req.body.date),
    time: req.body.time,
    capture: req.body.capture,
    processing: req.body.processing,
    visualize: req.body.visualize,
    amountofdata: req.body.amountofdata
    
  })

  try{
    const newTest = await test.save()
    res.redirect('tests')
  } catch {
    console.log("didn't save")
    res.render('tests', {
    test: test,
    errorMessage: 'Error creating test'
    })
  }
})

module.exports = router