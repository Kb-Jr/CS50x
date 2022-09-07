import csv
import re
from sys import argv, exit

# if the argument vector len is not equal to 3, print usage message and exit
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# open and close argv[1} as csv file with "with open" and set "," as delimiter to identify seperate strings or sequences and quotechar as "|"
with open(argv[1], newline="") as csvfile:
    database_reader = csv.reader(csvfile, delimiter=",", quotechar="|")
    for i, row in enumerate(database_reader):
        if i == 0:

            # open and close argv[2] as text file with "with open" in read mode, create a new variable "longest_strs"
            with open(argv[2], "r") as txtfile:
                line = next(txtfile)
                longest_strs = []

# loop through the rows to identify patterns of dna sequences
                for i in range(1, len(row)):
                    pattern = row[i]
                    matches = (
                        match[0] for match in re.finditer(fr"(?:{pattern})+", line)
                    )
# identify the longest sequences
                    try:
                        longest = int(len(max(matches, key=len)) / len(pattern))
                        longest_strs.append(longest)
                    except ValueError:
                        longest_strs.append(0)
        else:
            list_database_strs = list(map(int, row[1:]))
            if list_database_strs == longest_strs:
                print(row[0])
                break
    else:
        print("No match")


# credits: snippets and consultation from @mayconpm @github and stackoverflow.com