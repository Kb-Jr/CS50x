-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports
WHERE day = "28" AND month = "7" AND street = "Chamberlin Street"

SELECT transcript FROM interviews
WHERE day = "28" AND month = "7" AND year = "2020" AND transcript like "%courthouse%"
-- retrieve transcript of the day the crime was committed

SELECT activity FROM courthouse_security_logs
SELECT name FROM people JOIN courthouse_security_logs ON
people.license_plate = courthouse_security_logs.license_plate WHERE
day = "28" AND month = "7" and year = "2020" AND hour = "10" and minute >= "15" AND minute < "25" AND activity = "exit"
--retrieve how the activity is described then get licence plates of vehicles leaving the courthouse at 10 and within a 10 minutes frame

SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day = "28" AND month = "7" and year = "2020" AND transaction_type = "withdraw" AND atm_location = "Fifer Street"
--retrieve names of people who made a withdrawal from the ATM at Fifer Street

SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2020"
ORDER by hour, minute LIMIT 1)
--reterieve names of people who boarded the first flight out on the day after the crime was commited

SELECT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = "28" AND month = "7" and year = "2020" AND duration < "60"
--retrieve names of people who made phone calls of less than 60 seconds on the day the crime was commited

SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" and year = "2020"
ORDER bY hour, minute LIMIT 1)

INTERSECT SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day = "28" AND month = "7" and year = "2020" AND transaction_type = "withdraw" AND atm_location = "FIfer street"

INTERSECT SELCT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.earlier
WHERE day = "28" AND month = "7" and year = "2020" AND duration < "60"

INTERSECT SELECT name FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE day = "28" AND month = "7" and year = "2020" AND hour = "10" AND minute >= "15" AND minute < "25" AND activity = "exit"
-- intersect all the above criteria to get the name of the perp

SELECT city FROM airports where id = (SELECT destination_airport_id FROM flights
WHERE day = "29" AND month = "7" and year = "2020" ORDER BY hour, minute LIMIT 1)
--Get the destination being fled to on the day after the crime

SELECT name FROM people JOIN phone_calls ON people>phone_number = phone_calls.receiver
WHERE day = "28" AND month = "7" and year = "2020" AND duration < "60" AND caller = (SELECT
phone_number FROM people WHERE name = "Ernest");
--Retieve the name of the accomplice by checking who the call of under a minute was made to on the day of the day crime