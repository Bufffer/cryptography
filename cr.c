#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main() {

    int values[] = {
        0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9,
        0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13,
        0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d,
        0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
        0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31,
        0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
        0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
        0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f
    };

    char message[] = "the word or phrase you want to encrypt";

    size_t len = strlen(message);

    int random_index;
    srand(time(NULL));  
    random_index = rand() % 50;  
    char key = values[random_index];
    char storage_key = key;

    printf("First value: %s\n", message);


    /*Şifrele*/
    for (size_t i = 0; i < len; i++) {
        message[i] ^= key; 
        key = (key >> 1) | (key << 7); 
    }
    
    printf("Encrypted value: %s\n", message);

    for (size_t i = 0; i < len; i++) {
        message[i] ^= storage_key; 
        storage_key = (storage_key >> 1) | (storage_key << 7); 
    }

    printf("Decrypted version: %s\n", message);
    return 0;
}
