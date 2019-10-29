// Using Express:
var http = require('http');
var express = require('express');
var bodyParser = require('body-parser')

var urlencodedParser = bodyParser.urlencoded({ extended: false })

var app = express();

app.set('view engine', 'ejs');

app.use('/assets', express.static('assets'));

app.get('/', function(req, res){
    res.render('index');
});

app.get('/contact', function(req, res){
    res.render('contact')
});

app.get('/request', function (req, res) {
    res.render('request');
});

app.get('/thanks', function (req, res) {
    res.render('thanks');
});
  
app.post('/thanks', urlencodedParser, function (req, res) {
    console.log(req.body); 
    res.render('thanks', {data: req.body});
});

app.get('/profile/:name', function(req, res){
    var data = {age: 29, job: 'Student', hobbies: ['eating','walking']};
    res.render('profile', {person: req.params.name, data: data});
});

app.listen(3000);
console.log('Listening on localhost:3000');
