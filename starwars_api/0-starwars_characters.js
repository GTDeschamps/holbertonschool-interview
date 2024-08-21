#!/usr/bin/node

const request = require('request');

// Get the Movie ID from command line arguments
const movieId = process.argv[2];

// Function to fetch characters from the specified movie
function fetchCharacters(movieId) {
    // URL for the SWAPI films endpoint
    const url = `https://swapi.dev/api/films/${movieId}/`;

    request(url, { json: true }, (err, res, body) => {
        if (err) {
            return console.error('Error fetching data:', err);
        }

        // Check if the movie exists
        if (body && body.title) {
            body.characters.forEach(characterUrl => {
                // Fetch each character's details
                request(characterUrl, { json: true }, (err, res, characterBody) => {
                    if (err) {
                        return console.error('Error fetching character data:', err);
                    }

                    // Print each character's name
                    if (characterBody && characterBody.name) {
                        console.log(characterBody.name);
                    }
                });
            });
        } else {
            console.log('Movie not found or invalid Movie ID.');
        }
    });
}

// Check if a Movie ID was provided
if (!movieId) {
    console.log('Please provide a Movie ID as a positional argument.');
} else {
    fetchCharacters(movieId);
}
