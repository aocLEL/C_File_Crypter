#include <stdio.h>
#include <stdlib.h>


#ifndef Encrypt
    void encrypt_handler(FILE *enc_file, FILE *helper, int CFILE);
    #define Encrypt
#endif


#ifndef Decrypt
    void decrypt_handler(FILE *enc_file, FILE *helper, int CFILE);
    #define Decrypt
#endif

#ifndef Cesar
    char Cesare(char ch, int digit, int mode);
    #define Cesar
#endif

