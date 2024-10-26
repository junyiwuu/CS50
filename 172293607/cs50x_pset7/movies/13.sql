SELECT DISTINCT people.name
FROM people
JOIN stars AS stars_kb ON people.id = stars_kb.person_id
JOIN movies ON stars_kb.movie_id = movies.id
WHERE movies.id IN
(
    SELECT movies.id FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE people.name = "Kevin Bacon" AND people.birth = 1958
)
AND people.name != "Kevin Bacon";
