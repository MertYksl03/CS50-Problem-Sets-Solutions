#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int generateRandomKey(void);
int askOperation(void);
void getMessage(char *message);
void encrypt(char *message, int random);
void decrypt(char *message);

int main(void)
{   
    printf("Welcome to Enc-Encryption and Decryption tool.\n");
    printf("\n");
    while (1) 
    {
        int operation= askOperation();
        char message[100];
        if ( operation == 'Q')
        {
            printf("Procceding to exit...");
            break;
        }
        else if (operation=='E')
        {   
            printf("\n");
            printf("Enter the message you want to Encrypt(Max 100 charcters): ");
            getMessage(message);
            printf("\n");
            encrypt(message, generateRandomKey());
        }
        else if (operation=='D') 
        {
            printf("\n");
            printf("Enter the Encrypted message: ");
            getMessage(message);
            decrypt(message);
        }   
    }
        printf("The program ended. Have a nice day. :)\n");
    return 0; 
}

int generateRandomKey(void)
{
    int random=0;
    srand((unsigned int)time(NULL));
    while (random<999){
    random = rand()%10001;
    }
    printf("Here your Encryption Key: %i ", random);
    printf("***DO NOT FORGET THİS NUMBER***\n");
    return random;
}

int askOperation(void)
{
    char x;
    while (1)
    {   
        printf("Press Q to exit or \n");
        printf("Choose an operation: (E)ncryption or (D)ecryption:   ");
        if (scanf("%c", &x) == 1)
        {
            x= toupper(x);
            if (x == 'E' || x == 'D'|| x == 'Q')
            {
                // Consume any remaining characters in the input buffer, including newline
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            }
            
        }
        else
        {
            while (getchar() != '\n');
        }
        printf("\n");
    }
    return x;
}

void getMessage(char *message)
{
    if (fgets(message, 100, stdin) == NULL)
    {
        printf("Error reading input.\n");
        exit(EXIT_FAILURE);
    }

    size_t len = strlen(message);
    
    if (len > 0 && message[len - 1] == '\n') 
    {
        message[len - 1] = '\0';
    }
    else
    {
        while (getchar() != '\n');
    }
}

void encrypt(char *message, int random)
{
    
    printf("The Encrypted Message is between |");
    for (int i=0, n=strlen(message); i<n; i++)
    {
        message[i]= (message[i]+random)%94 + 32 ;
        printf("%c",message[i]);
    }
    printf("|\n");
}

void decrypt(char *message)
{
    int decryptionKey;
    while (1)
    {
        printf("Enter the Encryption key: ");
        if (scanf("%i", &decryptionKey) == 1 && decryptionKey >= 0 && decryptionKey <= 10000)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
        else
        {
            while (getchar() != '\n');
        }

        printf("\nINVALID CHOICE. Please enter a valid choice(0-10000)\n");
    }

    decryptionKey%=94;
    printf("The message decrypted: ");
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        message[i] = (message[i] -decryptionKey ) % 94 + 62 ;
        printf("%c", message[i]);
    }
    printf("\n");
}