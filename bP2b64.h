#include <stdio.h>
#include <stdlib.h>
#include "bs64Ind.h"
#include <string.h>
#include "aX.h"
#define MAX1 300
#ifndef _B264_
#define _B264_

//bP2B64
void bP2B64(long int* i,char op[],char* b64)
{
    int numOfEqualSign=0;
    long int nb;
    nb=((*i)*4);
        if((4*(*i)%6)==4)
        {
            strcat(op,"00");
            nb=(4*(*i))+2;
            numOfEqualSign=1;
        }                
        else if((4*(*i)%6)==2)
        {
            strcat(op,"0000");
            nb=(4*(*i))+4;
            numOfEqualSign=2;
        }

    int NB=nb/6;
    // int ind[(NB)];
    // memset( ind, 0, (NB)*sizeof(int) );
    int ind[MAX1]={};
    for(int k=0;k<(NB);k++)
    {
        for(int j=0;j<6;++j)
        {
            ind[k]=ind[k]+(op[j+6*k]-48)*aX(2,5-j);
        }
    }
    
    for(int k=0;k<(NB);k++)
    {
        b64[k]=table[ind[k]];
    }
    b64[NB]='\0';
    // x: index of b64
    int xb=(NB);
    if(numOfEqualSign==1)
    {
        xb=(NB)+1;
        b64[xb-1]='=';
        b64[xb]='\0';
    }
    else if(numOfEqualSign==2)
    {
        xb=(NB)+2;
        b64[xb-2]='=';
        b64[xb-1]='=';
        b64[xb]='\0';
    }
}
#endif