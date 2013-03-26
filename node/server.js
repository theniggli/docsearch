var express = require('express');
var app = express();




app.get('/', function(req, res){
	res.send('call /q/QUERYID or /q/ for list');
});

function get_query(query, cb) {
	var sys = require('sys');
	var exec = require('child_process').exec;
	var child = exec('echo '+query, function(error, stdout, stderr) {
		cb(stdout);
	});
}


app.get('/q/', function(req, res) {
	console.log('sending all queries');
    var fs = require("fs");
    var JSON = require("JSON");
    var callback = function (err, queries) {
      queries=queries.map(function(x){
          return parseInt(x,10);
      }).sort(function(a, b){
          return a-b;
      });
      res.send(JSON.stringify(queries, null, 4));
    };
    fs.readdir('data/queries', callback);
});

app.get('/q/:query', function (req, res) {
	console.log('query string: ' + req.params.query);
	
	get_query(req.params.query, function(out){
		res.send(out);
	});
});


app.listen(process.env.PORT);
console.log('Listening on '+process.env.IP+':'+process.env.PORT);

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.send(500, 'Something broke!');
});