#include <stdio.h>
#include <string.h>
#ifndef _H2BP_
#define _H2BP_

// HEX2BP
void hex2Bp(char* hexa,long int* ptr,char op[])
{    
    long int tmp = *ptr;

    while (hexa[tmp])
    {
        switch (hexa[tmp])
        {
        case '0':
            strcat(op,"0000"); break;
        case '1':
            strcat(op,"0001"); break;
        case '2':
            strcat(op,"0010"); break;
        case '3':
            strcat(op,"0011"); break;
        case '4':
            strcat(op,"0100"); break;
        case '5':
            strcat(op,"0101"); break;
        case '6':
            strcat(op,"0110"); break;
        case '7':
            strcat(op,"0111"); break;
        case '8':
            strcat(op,"1000"); break;
        case '9':
            strcat(op,"1001"); break;
        case 'A':
            strcat(op,"1010"); break;
        case 'B':
            strcat(op,"1011"); break;
        case 'C':
            strcat(op,"1100"); break;
        case 'D':
            strcat(op,"1101"); break;
        case 'E':
            strcat(op,"1110"); break;
        case 'F':
            strcat(op,"1111"); break;
        case 'a':
            strcat(op,"1010"); break;
        case 'b':
            strcat(op,"1011"); break;
        case 'c':
            strcat(op,"1100"); break;
        case 'd':
            strcat(op,"1101"); break;
        case 'e':
            strcat(op,"1110"); break;
        case 'f':
            strcat(op,"1111"); break; 
        default:
            break;
        }
        tmp++;                    
    }
    *ptr=tmp;
}
#endif