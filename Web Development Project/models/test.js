const mongoose = require('mongoose')

const testSchema = new mongoose.Schema({
  testid:{
    type: String,
    required: true
  },
  date:{
    type: Date,
    required: true,
    default: Date.now
  },
  time:{
    type: String,
    required: true,
  },
  capture:{
    type: Number,
    required: true
  },
  processing:{
    type: Number,
    required: true
  },
  visualize:{
    type: Number,
    required: true
  },
  amountofdata:{
    type: Number,
    required: true
  },
  project:{
    type: mongoose.Schema.Types.ObjectId,
    require: true,
    ref: 'Project'
  }

})

module.exports = mongoose.model('Test', testSchema)