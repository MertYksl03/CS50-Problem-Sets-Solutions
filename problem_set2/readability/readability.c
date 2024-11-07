#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    char *text = get_string("Text: ");
    
    int length = strlen(text);
    int letter_counter = 0;
    int sentence_counter = 0; 
    int word_counter = 0;
    double L = 0;
    double S = 0;
    double index = 0;

    for (int i = 0; i < length; i++) 
    {
        text[i] = toupper(text[i]);

        if (text[i] > 64 && text[i] < 91) {
            letter_counter++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentence_counter++;
        }

        if (text[i] == ' '){
            word_counter++;
        }
    }

    //ussually there is no space after last word
    word_counter++;

    // printf("letter counter %i\n", letter_counter);
    // printf("sentencecounter %i\n",sentence_counter);
    // printf("word counter %i\n", word_counter);
    
    //Coleman-Liau index
    L = (double)letter_counter / word_counter * 100; 
    S = (double)sentence_counter / word_counter * 100;
    index =  0.0588 * L - 0.296 * S - 15.8;

    printf("Grade %0.f\n", round(index));

    return 0;
}