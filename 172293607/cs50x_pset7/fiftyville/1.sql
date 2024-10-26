/*withdraw monyey and leave the street*/
/*find the suspect four id, leave the city*/
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
