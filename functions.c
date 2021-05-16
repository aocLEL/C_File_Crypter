#include "functions.h"
#include <string.h>


/*funzione per criptare i file!!  */

void encrypt_handler(FILE *enc_file, FILE *helper, int CFILE) {


    char file_name[30], ch;

    printf("Insert the name of a file to encrypt: ");

    scanf("%s", file_name);
    fseek(stdin,0,SEEK_SET);

    if(CFILE == 1) {
        char new_name[20];
        printf("Come vuoi rinominare il file .c? il nome deve finire con .txt!!!: ");
        scanf("%s", new_name);
        fseek(stdin,0,SEEK_SET);
        rename(file_name, new_name);
        strcpy(file_name, new_name);
    }

    int distance;

    printf("\nInsert a digit: ");
    scanf("%d", &distance);



    enc_file = fopen(file_name, "r");
    helper = fopen("temp.txt", "w");

    if(enc_file == NULL) {
        printf("\nErrore in apertura del file");
        exit(1);
    }

    if(helper == NULL) {
        printf("\nErrore nella creazione del file");
        exit(2);
    }

    
    
    for(;;) {
        ch = fgetc(enc_file);
        if(ch == EOF) {
            break;
        }
        else {
            ch = Cesare(ch, distance, 1);
            /*if(ch > 'z' || ch > 'Z') {
                ch = ch + 'A'+ distance - ('Z' - ch) - 1;
            }*/
            fputc(ch, helper);
        }
    
    }
    
    fclose(enc_file);
    fclose(helper);
    //remove("temp.txt");



    enc_file = fopen(file_name, "w");
    helper = fopen("temp.txt", "r");

    if(enc_file == NULL) {
        printf("\nErrore in apertura del file");
        exit(3);
    }

    if(helper == NULL) {
        printf("\nErrore in apertura del file");
        exit(4);
    }


    for(;;) {
        ch = fgetc(helper);
        if(ch == EOF) {
            break;
        }
        else {
            ch = Cesare(ch, distance, 1);
            /*if(ch > 'z' || ch > 'Z') {
                ch = ch + 'A'+ distance - ('Z' - ch) - 1;
            }*/
            fputc(ch, enc_file);
        }
    
    }


    fclose(enc_file);
    fclose(helper);
    remove("temp.txt");

    printf("\n\nIl tuo file e' stato criptato correttamente!!!");
}






/*funzione per decriptare i file!!  */


void decrypt_handler(FILE *enc_file, FILE *helper, int CFILE) {
    char file_name[30], ch;
    printf("Insert the name of a file to decrypt: ");

    scanf("%s", file_name);
    fseek(stdin,0,SEEK_SET);

    if(CFILE == 1) {
        char new_name[20];
        printf("Come vuoi rinominare il file .txt? il nome deve finire con .C!!!: ");
        scanf("%s", new_name);
        fseek(stdin,0,SEEK_SET);
        rename(file_name, new_name);
        strcpy(file_name, new_name);
    }

    int distance;

    printf("\nInsert a digit: ");
    scanf("%d", &distance);



    enc_file = fopen(file_name, "r");
    helper = fopen("temp.txt", "w");

    if(enc_file == NULL) {
        printf("\nErrore in apertura del file");
        exit(1);
    }

    if(helper == NULL) {
        printf("\nErrore nella creazione del file");
        exit(2);
    }



    for(;;) {
        ch = fgetc(enc_file);
        if(ch == EOF) {
            break;
        }
        else {
            ch = Cesare(ch, distance, 2);
            /*if(ch > 'z' || ch > 'Z') {
                ch = ch -  'A'+ distance - ('Z' - ch) - 1;
            }*/
            fputc(ch, helper);
        }
    
    }
    
    fclose(enc_file);
    fclose(helper);
    //remove("temp.txt");



    enc_file = fopen(file_name, "w");
    helper = fopen("temp.txt", "r");

    if(enc_file == NULL) {
        printf("\nErrore in apertura del file");
        exit(3);
    }

    if(helper == NULL) {
        printf("\nErrore in apertura del file");
        exit(4);
    }


    for(;;) {
        ch = fgetc(helper);
        if(ch == EOF) {
            break;
        }
        else {
            ch = Cesare(ch, distance, 2);
            if(Cesare(ch, distance, 2) == '`') {
                ch = 't';
            }
            /*if(ch > 'z' || ch > 'Z') {
                ch = ch - 'A'+ distance - ('Z' - ch) - 1;
            }*/
            fputc(ch, enc_file);
        }
    
    }


    fclose(enc_file);
    fclose(helper);
    remove("temp.txt");

    printf("\n\nIl tuo file è stato decriptato correttamente!!!");
}

