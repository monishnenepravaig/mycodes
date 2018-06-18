from File_operations import *
print("Scramble word score calculator")
condition = True
points_for = dict_from_file("letter_score")
while(condition):
    word = input("Enter next word ")
    lower_word = word.lower()
    if word.isalpha()== False:
        print("Invalid Input")
        continue
    score = 0
    for letter in lower_word:
        score += int(points_for[letter])
    print("Score for the word ",word,"is ",score)
print("Scramble word score calculator Code Ended")

