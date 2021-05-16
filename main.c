#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(void){

    FILE *ftenc, *helper;

    int choice;

    printf("!!Benvenuto nel programma di cripting targato aocLEL!!");
    printf("\n\nRICORDA:: INFORMATICAGE FA SCHIFO!!!!");

    while(1) {
    printf("\nScegliere :\n1 --> criptare un file\n2 --> decriptare un file\n3 --> criptare un file C\n4 --> decriptare un file C\n\n\n\n");

    printf("La tua scelta: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt_handler(ftenc, helper, 0);
            break;
        case 2:
            decrypt_handler(ftenc, helper, 0);
            break;
        case 3:
            encrypt_handler(ftenc, helper, 1);
            break;
        case 4:
            decrypt_handler(ftenc, helper, 1);
            break;

        default:
            printf("\nOption not valid!!\n\n");
    }
    }

    return 0;
}