SELECT movies.title FROM movies
WHERE movies.id IN

(SELECT stars.movie_id FROM stars WHERE stars.person_id =
(SELECT people.id FROM people WHERE name = "Bradley Cooper"))

AND movies.id IN
(SELECT stars.movie_id FROM stars WHERE stars.person_id =
(SELECT people.id FROM people WHERE name = "Jennifer Lawrence"))
;

