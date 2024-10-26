SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id

JOIN ratings ON movies.id = ratings.movie_id

WHERE people.name = "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;

--
--SELECT movies.title, ratings.rating FROM movies
--JOIN ratings ON movies.id = ratings.movie_id
--WHERE movies.id IN
--(SELECT stars.movie_id FROM stars WHERE stars.person_id =
--(SELECT people.id FROM people WHERE name = "Chadwick Boseman"))

--ORDER BY ratings.rating DESC
--LIMIT 5;

