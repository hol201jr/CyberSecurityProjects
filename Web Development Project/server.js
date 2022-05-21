const express = require('express')
const app = express()
const expressLayouts = require('express-ejs-layouts')
const bodyParser = require('body-parser')
const { MongoClient } = require('mongodb');
const PORT = 4400
const url = 'mongodb://localhost:27017/telex'
const methodOverride = require('method-override')

const indexRouter = require('./routes/index')
const projectRouter = require('./routes/projects')
const testRouter = require('./routes/tests')
const graphRouter = require('./routes/graphs')

app.set('view engine', 'ejs')
app.set('views', __dirname + '/views')
app.set('layout', 'layouts/layout')
app.use(expressLayouts)
app.use(express.static('public'))
app.use(bodyParser.urlencoded({limit: '10mb', extended: false}))
app.use(methodOverride('_method'))
app.use(express.json())

const mongoose = require('mongoose')
mongoose.connect(url, {useNewUrlParser: true})
const db = mongoose.connection
db.on('error', error => console.error(error))
db.once('open', () => console.log("Connected to Mongoose"))

app.use('/', indexRouter)
app.use('/projects', projectRouter)
app.use('/tests', testRouter)
app.use('/graphs', graphRouter)



app.listen(process.env.PORT || PORT)

//course 3 @ 5:19