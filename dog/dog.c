//import base libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//define color codes for printf beautification
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define RST "\x1B[0m"

//max length of line being read from file
#define MAXLINE 256
//size of line number indent
#define TABSIZE 5

//include custom header and c files
#include "open_file.h"
#include "is_substring.h"
#include "print_line.h"
#include "int_len.h"

//create struct to hold counters
typedef struct
{
    int tabs;
    int newlines;
    int returns;
    int characters;
    int matches;
} Count;

//set default values for struct
Count count={0,0,0,0,0};


//main program loop
int main(int argc, char *argv[])
{
    //If user runs with no options present correct syntax
    if (argc <= 1)
    {
        printf("Usage: ./dog file \""RED"search string"RST"\"\n");
        exit(0);
    }

    //main loop variables
    char line[MAXLINE];
    FILE *file = open_file(argv[1]);
    int line_number=1;

    if (argv[2]!=NULL)
    {
        printf("Searching for "RED"%s\n"RST,argv[2]);
    }

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
    printf("\n\n""Lines:%d\n"BLU"Tabs:"RST"%d\n"GRN"NewLines:"RST"%d\n"MAG"Returns:"RST"%d\n"RED"Found Result:"RST"%d\nCharacters:%d\n",line_number-1,count.tabs,count.newlines,count.returns,count.matches,count.characters);
    fclose(file);
    return 0;
}