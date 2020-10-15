#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <getopt.h>
#include "bs64Ind.h"
#include "bitPattern.h"
#include "bP2b64.h"
#include "aX.h"

#define MAX 300

int main(int argc,char **argv)
{

    int c;
    int iflag=0,oflag=0;

    FILE* fpo;
    FILE* fpi;

                // char B[MAX]={};

    while((c=getopt(argc,argv,"i:o:"))!=-1)
    {
        switch(c)
        {
            case 'i':
                printf("optarg=%s\n",optarg); 

                if((fpi=fopen(argv[2],"r"))==NULL)
                    return 1;

                // printf("%s",b64);
                // printf("%s",B);
                // fclose(fpi);
                break;
                // B[strlen(B)-1]='\0';
                // printf("%s\n",B);

            case 'o':
                printf("optarg=%s\n",optarg);
                fpo=fopen(optarg,"w");
                
                // fprintf(fpo,"%s\n",b64);
                
                // fclose(fpo);       
                
                break;

            case '?':
                if(optopt=='i'||optopt=='o')
                    fprintf(stderr,"Option -%c needs an argument\n",optopt);
                else
                    fprintf(stderr,"Unknown option -%c.\n",optopt); break;

            default:                
                    fprintf(stderr,"getopt"); 

        }
    }

    while((!feof(fpi)))
    {
        char b64[MAX]={};
        char hexa[MAX]={};
        char op[MAX]={};
        long int i = 0; // #of input
        
        fscanf(fpi,"%s",hexa);
        hex2Bp(hexa,&i,op);
        bP2B64(&i,op,b64);
        // strcat(b64,"\n");
        // strcat(B,b64);
        // strcat(B,"\n");
        fprintf(fpo,"%s\n",b64);

    }
    fclose(fpo);       
    fclose(fpi);       


    return 0;
}
