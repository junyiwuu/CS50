-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT bank_accounts.person_id
FROM bank_accounts
JOIN atm_transactions
ON atm_transactions.account_number = bank_accounts.account_number

WHERE atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_transactions.transaction_type = "withdraw"


AND bank_accounts.person_id IN(
    SELECT people.id
    FROM people
    JOIN bakery_security_logs
    ON bakery_security_logs.license_plate = people.license_plate
    WHERE month = 7 AND day = 28 AND hour = 10
)

AND bank_accounts.person_id
IN(
    SELECT people.id FROM people
    WHERE people.passport_number
    IN
    (
        SELECT passengers.passport_number FROM passengers
        JOIN flights ON passengers.flight_id = flights.id
        WHERE flights.origin_airport_id = 8
        AND flights.month = 7 AND flights.day = 29
        AND hour < 12
    )
)
;


submit50 cs50/problems/2024/x/fiftyville
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




