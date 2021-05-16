#include "functions.h"
#include <stdlib.h>
#include <ctype.h>




char Cesare(char ch, int digit, int mode) {
    if(ch > 'z'){
        ch = tolower(ch);
    }
    if(ch == ' ')
        return ch;


    if(ch >= 'a' && ch <= 'z') {
            
            if(mode == 1) {
                if(ch < 'z' - digit) {
                ch = ch + digit;
                return ch;
                }


                else {
                    ch = 'a' + digit - ('z' - ch) - 1;
                    return ch;
                }


            }
            else if(mode == 2){
                if(ch < 'a' + digit) {
                    ch = 'z' - (digit -(ch - 'a') -1);
                    return ch;
                }

                else {
                    ch = ch-digit;
                    return ch;
                }

                    
            }
    }
}