#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int scrabble(char *text);

int main(void)
{
    char *Player1_word = get_string("Player1: ");
    printf("\n");
    char *Player2_word = get_string("Player2: ");
    printf("\n");
    int points_of_Player1 = scrabble(Player1_word);
    int points_of_Player2 = scrabble(Player2_word);

    if (points_of_Player1 == points_of_Player2) {
        printf("Tie!\n");
    }else if (points_of_Player1 > points_of_Player2) {
        printf("Player 1 wins\n");
    }else if (points_of_Player1 < points_of_Player2) {
        printf("Player 2 wins\n");
    }

    return 0;
}

int scrabble(char *text)
{
    int points = 0;
    int length_of_word = strlen(text);

    for (int i = 0; i < length_of_word; i++)
    {
        text[i] = toupper(text[i]);
        switch (text[i])
        {
        case 'A':
            points += 1;
            break;
        case 'B':
            points += 3;
            break;
        case 'C':
            points += 3;
            break;
        case 'D':
            points += 2;
            break;
        case 'E':
            points += 1;
            break;
        case 'F':
            points += 4;
            break;
        case 'G':
            points += 2;
            break;
        case 'H':
            points += 4;
            break;
        case 'I':
            points += 1;
            break;
        case 'J':
            points += 8;
            break;
        case 'K':
            points += 5;
            break;
        case 'L':
            points += 1;
            break;
        case 'M':
            points += 3;
            break;
        case 'N':
            points += 1;
            break;
        case 'O':
            points += 1;
            break;
        case 'P':
            points += 3;
            break;
        case 'Q':
            points += 10;
            break;
        case 'R':
            points += 1;
            break;
        case 'S':
            points += 1;
            break;
        case 'T':
            points += 1;
            break;
        case 'U':
            points += 1;
            break;
        case 'V':
            points += 4;
            break;
        case 'W':
            points += 4;
            break;
        case 'X':
            points += 8;
            break;
        case 'Y':
            points += 4;
            break;
        case 'Z':
            points += 10;
            break;
        }
    }
    return points;
}
