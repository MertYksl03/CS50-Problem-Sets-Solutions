# Enc
Enc is a basic message encyrption and decryption tool all written in C.

The program begins by prompting the user to choose between (E)ncryption or (D)ecryption.
If the user chooses encryption, firstly the program asks the user to input the message that wanted to encrypted and then a random encryption key is generated, and the message is encrypted using a simple algorithm.
If the user chooses decryption, they are asked to enter the encryption key used during the encryption process. The program then decrypts the message using the entered key and displays the decrypted message.

The encryption algorithm involves adding a random value to each character in the message, ensuring the result falls within the printable ASCII range (32 to 126). The decryption process involves subtracting the encryption key from each character and adjusting to keep the result within the printable ASCII range.
