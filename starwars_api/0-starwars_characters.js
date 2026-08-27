#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const movieUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request({ url: movieUrl, json: true }, (movieError, response, movie) => {
  if (movieError || !response || response.statusCode !== 200) {
    return;
  }

  const characters = movie.characters || [];
  let characterIndex = 0;

  const printNextCharacter = () => {
    if (characterIndex === characters.length) {
      return;
    }

    request({ url: characters[characterIndex], json: true }, (error, result, character) => {
      if (!error && result && result.statusCode === 200 && character.name) {
        console.log(character.name);
      }
      characterIndex += 1;
      printNextCharacter();
    });
  };

  printNextCharacter();
});
