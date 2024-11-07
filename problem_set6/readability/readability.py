from cs50 import get_string 

text = get_string("Text: ")

a = {".", "!", "?", "..."}
letter_count = 0
word_count = 1 #start from 1 to account the last word
sentence_count = 0 

for char in text:
    if char.isalpha():
        letter_count += 1
    if char == " ":
        word_count +=1
    if char in a:
        sentence_count += 1 

average_number_of_letters = (letter_count / word_count) * 100
average_number_of_words = (sentence_count / word_count) * 100

#0.0588 * L - 0.296 * S - 15.8
index = round((0.0588 * average_number_of_letters) - (0.296 * average_number_of_words) - 15.8)
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else: 
    print(f"Grade {index}")