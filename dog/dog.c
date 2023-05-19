//*************************************************************
// Dog: designed as a replacement to the combo of 'cat | grep'.
// that also has case sensitive searching (with highlighting)!
// This program will also print out any tabs, newlines and
// returns. This feature alone will help you troubleshoot any
// formatting issues, especially in Python programs!
//*************************************************************

//import base libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//include custom header and c files
#include "is_substring.h"
#include "print_line.h"
#include "dog.h"

//create struct to hold tab, return, newline counters
typedef struct
{
    int tabs;
    int newlines;
    int returns;
    int characters;
    int matches;
    int spaces;
} Count;
Count count={0,0,0,0,0,0};

//create function to determine length of ints
int int_len(int i)
{
    int count = 0;
    do
    {
        i /= 10;
        ++count;
    } while (i > 0);
    return count;
}


//main program loop
int main(int argc, char *argv[])
{
    //Open file from argv[1] command line parameter if file is found
    FILE *file;
    if (argv[1]!=NULL)
    {
        file=fopen(argv[1],FILEMODE);
    }
    else
    {
        printf("File %s not found!\n",argv[1]);
        exit(0);
    }

    //If user runs with no options present correct syntax for command
    if (argc <= 1)
    {
        printf("Usage: ./dog file \""RED"search string"RST"\"\n");
        exit(0);
    }

    //main program variables
    char line[MAXLINE];
    int line_number=1;
    if (argv[2]!=NULL)
    {
        printf("\nSearching for "RED"\"%s\"\n\n"RST,argv[2]);
    }

    //read from file until EOF
    while (fgets(line, MAXLINE, file) != NULL)
    {
        if (argv[2]!=NULL)
        {
            if (is_substring(line,argv[2]))
            {
                printf(RED"*"RST);
                for (int i = int_len(line_number); i < TABSIZE-1; i++)
                {
                    printf(" ");
                }
            }
            else
            {
                for (int i = int_len(line_number); i < TABSIZE; i++)
                {
                    printf(" ");
                }
            }
            printf("%i:",line_number);
            print_line(line,argv[2]);
        }
        else
        {
            for (int i = int_len(line_number); i < TABSIZE; i++)
            {
                printf(" ");
            }
            printf(" %i:",line_number);
            print_line(line,argv[2]);
        }
        line_number+=1;
    }

    //print final tabulations and close out file
    printf("\n\n""Lines:%d\n"BLU"Tabs:"RST"%d\n"GRN"NewLines:"RST"%d\n"MAG"Returns:"RST"%d\n"RED"Found Result:%d\n"YEL"Spaces:%d\n"RST"Characters:%d\n",line_number-1,count.tabs,count.newlines,count.returns,count.matches,count.spaces,count.characters);
    fclose(file);
    return 0;
}