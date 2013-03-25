var express = require('express');
var app = express();




app.get('/', function(req, res){
	res.send('call /q/QUERYID or /q/ for list');
});

function get_queries(cb) {
  var sys = require('sys');
  var exec = require('child_process').exec
  child = exec('/opt/local/bin/perl /Users/merne/dev/perl/docsearch/backend/scripts/dirreader.pl', function(error, stdout, stderr) {
    cb(stdout);
  });
}

function get_query(query, cb) {
	var sys = require('sys');
	var exec = require('child_process').exec
	child = exec('echo '+query, function(error, stdout, stderr) {
		cb(stdout);
	});
}

app.get('/q/', function(req, res) {
	console.log('sending all queries')
	get_queries(function(out){
		res.send(out);
	});
});

app.get('/q/:query', function (req, res) {
	console.log('query string: ' + req.params.query)
	
	get_query(req.params.query, function(out){
		res.send(out);
	});
});


app.listen(3000);
console.log('Listening on port 3000');

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.send(500, 'Something broke!');
});