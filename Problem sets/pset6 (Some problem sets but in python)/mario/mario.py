from cs50 import get_int

while True:
    h = get_int("height: ")
    if h >= 1 and h <= 8:
        break
# prompt user for input for height value of a positive integer between 1 and 8, break out of loop once conditions are met

for row in range(h):
    for col in range(h):
        if (row + col < h - 1):
            print(" ", end="")
        else:
            print("#", end="")
# print blank space for any position whose row and column sum is less than input height - 1, example row position 0 plus column position 1 is less than input height 4 - 1, so print space
# print # for any position whose row and column sum is not less than input height - 1, example row position 2 plus column position 2 is not less than input height 4 - 1, so print #

    print()

