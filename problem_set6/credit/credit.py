import cs50 

def main(): 
    card_number = cs50.get_int("Enter the credit card number: ")
    card_number_array = [int (digit) for digit in str(abs(card_number))]

    if not luhn_algorithm(card_number_array):
        print("INVALID")
    else:
        print("VALID")
        determine_the_card(card_number_array) 


def luhn_algorithm(card_number_array):
    sum = 0
    reversed_number_array = card_number_array[::1]
    for i in range(len(reversed_number_array)):
        current_digit = reversed_number_array[i]
        if i % 2 == 1:
            current_digit *= 2 
            if current_digit > 9:
                current_digit = current_digit - 9  
        
        sum += current_digit
 
    return sum % 10 == 0     

def determine_the_card(card_number_array):
    if card_number_array[0] == 4:
        print("VISA")
    elif card_number_array[0] == 3 and (card_number_array[1] == 4 or card_number_array[1] == 7):
        print("AMERICAN EXPRESS")
    elif card_number_array[0] == 5 and (card_number_array[1] == 1 or card_number_array[1]== 2 or card_number_array[1] == 3 or card_number_array[1] == 4 or card_number_array[1] == 5):
        print("MASTERCARD") 
main()