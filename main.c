#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

void print_help()
{
    printf("Program <TEMPLATE>\n");
    printf(" -h - Help\n");
    printf("\nThanks for using.\n");
    printf("Created by Tim. Please visit https://github.com/timgold81/\n");

}


int main(int argc,char **argv)
{
    int h_flag=0;
    int unknown_option=0;
    int arg_c;
    char *string_value=NULL;

    if (argc==1)
    {
        printf("No options entered\n");
        print_help();
        return -1;
    }

    while ((arg_c=getopt(argc,argv,"hs:")) != -1)
    {
        switch(arg_c)
        {
        case 'h':
            h_flag=1;
            break; 
        case 's':
            //String_value will have the -s value
            string_value=optarg;
            break;
        case '?':
            if (optopt=='s')
                fprintf(stderr,"No arument at -%c\n",optopt);
            else if (isprint(optopt))
                fprintf(stderr,"Unknown option -%c\n",optopt);
            else   
                fprintf(stderr,"Unknow char %x\n",optopt);
            return 1;
        default:
            unknown_option=1;
            break;
        
        } 
    }

    if (h_flag)
    {
        print_help();
        return 1;
    }

    if(unknown_option)
    {
        print_help();
        return (-1);
    }

    //Programm comes here:

}
