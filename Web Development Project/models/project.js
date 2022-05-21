const mongoose = require('mongoose')
const Test = require('./test')

const projectSchema = new mongoose.Schema({
  name:{
    type: String,
    required: true
  }
})

projectSchema.pre('remove', function(next){
  Test.find({project: this.id}, (err,tests)=> {
    if (err) {
      next(err)
    } else if (tests.length > 0) {
      next(new Error('This project has tests sill'))
    } else {
      next()
    }
  })
})

module.exports = mongoose.model('Project', projectSchema)