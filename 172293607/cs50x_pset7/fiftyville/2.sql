SELECT DISTINCT people.id, phone_calls.caller, phone_calls.duration, flights.destination_airport_id,
people.name, flights.month, flights.day, flights.hour, flights.minute
FROM phone_calls
JOIN people
ON phone_calls.caller = people.phone_number
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id


WHERE phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60
AND people.id IN( 467400 , 449774 , 686048
);




