#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define VALID 1
#define INVALID 0

int luhns_algorithm(int digits_of_card_number[], int length);
void determine_the_card(int digits_of_card_number[], int length);

int main(void)
{
    long credit_card_number = get_long("Enter the card number: ");
    char temp_string[40];
    int digits_of_card_number[40];

    // Convert the long variable to an int array
    sprintf(temp_string, "%ld", credit_card_number);
    int length = strlen(temp_string);
    for (int i = 0; i < length; i++)
    {
        digits_of_card_number[i] = temp_string[i] - '0';
    }

    if (luhns_algorithm(digits_of_card_number, length) == INVALID) {
        printf("INVALID\n");
    } else {
        determine_the_card(digits_of_card_number, length);
    }
    return 0;
}

int luhns_algorithm(int digits_of_card_number[], int length)
{
    int sum = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        int current_digit = digits_of_card_number[i];
        if ((length - i) % 2 == 0) {
            current_digit *= 2;
            if (current_digit > 9) {
                current_digit -= 9;
            }
        }
        sum += current_digit;
    }

    return (sum % 10 == 0) ? VALID : INVALID;
}

void determine_the_card(int digits_of_card_number[], int length)
{
    if (digits_of_card_number[0] == 4 && (length == 13 || length == 16)) {
        printf("VISA\n");
    }

    else if (digits_of_card_number[0] == 5 && (digits_of_card_number[1] >= 1 && digits_of_card_number[1] <= 5) && length == 16) {
        printf("MASTERCARD\n");
    }

    else if (digits_of_card_number[0] == 3 && (digits_of_card_number[1] == 4 || digits_of_card_number[1] == 7) && length == 15) {
        printf("AMEX\n");
    }
    else {
        printf("INVALID\n");
    }
}
