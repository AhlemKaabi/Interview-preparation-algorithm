#!/usr/bin/node
const ID_movie = process.argv[2];
const url_movies = 'https://swapi-api.hbtn.io/api/films/' + ID_movie
const request = require('request');
request(url_movies, function (error, response, body) {
//   console.error('error:', error); // Print the error if one occurred
//   console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
//   console.log('body:', body); // Print the HTML for the Google homepage.
  const characters = JSON.parse(body).characters;
//   console.log(characters[0])
  for (const url_characters of characters) {
	request(url_characters, function (error, response, body) {
	  console.log(JSON.parse(body).name);
	});
  }
});
