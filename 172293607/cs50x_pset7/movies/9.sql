SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth;



--SELECT name FROM people WHERE people.id IN
--(SELECT stars.person_id FROM stars WHERE stars.movie_id IN
--    (SELECT movies.id FROM movies WHERE movies.year=2004))
--ORDER BY people.birth DESC, name;
