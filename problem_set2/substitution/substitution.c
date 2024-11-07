#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

// PROTOTYPE
char *encrypt(char *key, char *plaintext);
bool is_valid_key(char *key);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        if (!is_valid_key(argv[1])) {
            printf("Key must contain 26 unique alphabetic characters.\n");
            return 1;
        }

        char *plaintext = get_string("Plaintext: ");
        char *ciphertext = encrypt(argv[1], plaintext);

        printf("ciphertext: %s\n", ciphertext);

        free(ciphertext); 
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

bool is_valid_key(char *key) {
    int length_of_key = strlen(key);
    if (length_of_key != 26) {
        return false;
    }

    int seen[26] = {0};
    for (int i = 0; i < length_of_key; i++) {
        if (!isalpha(key[i])) {
            return false;
        }
        int index = toupper(key[i]) - 'A';
        if (seen[index]++) {
            return false; 
        }
    }
    return true;
}

char *encrypt(char *key, char *plaintext) {
    int length_of_plaintext = strlen(plaintext);
    char *cipher = malloc(length_of_plaintext + 1); // +1 for null-terminator

    for (int i = 0; i < length_of_plaintext; i++) {
        char temp = plaintext[i];
        if (isupper(temp)) {
            cipher[i] = toupper(key[temp - 'A']); 
        } else if (islower(temp)) {
            cipher[i] = tolower(key[temp - 'a']); 
        } else {
            cipher[i] = temp; 
        }
    }
    cipher[length_of_plaintext] = '\0'; // Add the null-terminator
    return cipher;
}
