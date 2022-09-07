from cs50 import get_float

# Propmpt user for input of change owed
while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

# convert cent to dollar and round up to avoid excess values
cent = round(change * 100)

# initialize the counting of individual coins
count = 0

# subtract 25 from the change owed and continue subtracting 25 as long as its possible else move to the next denomination, count every 25 cents coin. Repeat same process for each denomination
while cent >= 25:
    cent = cent - 25
    count += 1

while cent >= 10:
    cent = cent - 10
    count += 1

while cent >= 5:
    cent = cent - 5
    count += 1

while cent >= 1:
    cent = cent - 1
    count += 1

# print the number of coins counted
print(count)
