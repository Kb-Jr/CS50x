from cs50 import get_string

# prompt user for text, remove white spaces, declare variables for number or words, sentences and letters and initialize to 0
s = get_string("text: ").strip()

number_words = 0
number_sentences = 0
number_letters = 0

for i in range(len(s)):
    # determine letters by checking if its an alphabet and increase letter count by 1 for every letter detected

    if s[i].isalpha():
        number_letters += 1

# determine words by checking for blank spaces. characters after blank spaces indicate the begining of a new word, hence word count will be increased by 1

    if (i == 0 and s[i] != ' ') or (i != len(s) - 1 and s[i] == ' ' and s[i + 1] != ' '):
        number_words += 1

# determine what are sentences by using ". ! and ?" as indicators of end of sentences. When a sentence is detected increment the sentence count by 1

    if s[i] == '.' or s[i] == '?' or s[i] == '!':
        number_sentences += 1

# solve for L, S and index respectively and round the result of index to a whole number

L = number_letters / number_words * 100
S = number_sentences / number_words * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

# if the result of index is less than 1 print Before grade 1, if greater than 16 print Grade 16+, for anything else, the value of index should be printed alongside "Grade"

if index < 1:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")

else:
    print(f"Grade {index}")

