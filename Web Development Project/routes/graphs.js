const express = require('express')
const { redirect } = require('express/lib/response')
const project = require('../models/project')
const router = express.Router()
const Project = require('../models/project')
const Test = require('../models/test')

router.get('/', async(req, res) => {
  let tests
  try {
    tests = await Test.find({})
  } catch {
    console.log("err catching tests")
  }
    let xlabel = [];
    let xtest = [];
    tests.forEach(test=> {
      xtest.push(test.capture)
      xlabel.push(test.testid)
    })

    res.render('graphs/index', {
      xlabel: xlabel,
      xtest: xtest
    })
})

module.exports = router