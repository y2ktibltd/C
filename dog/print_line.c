//standard libraries
#include <stdio.h>
#include <string.h>
#include "print_line.h"

//create struct to hold counters
typedef struct
{
    int tabs;
    int newlines;
    int returns;
    int characters;
    int matches;
    int spaces;
} Count;
extern Count count;


void print_line(char *line, char *find)
{
    int line_len=strlen(line);
    for (int i = 0; i < line_len; i++)
    {
        //highlight individual search terms inside each line
        if (find!=NULL)
        {
            int find_len = strlen(find);
            char check[line_len + find_len];
            strncpy(check,line + i,find_len+1);
            check[strlen(check)-1] = '\0';
            if(!strcmp(find,check))
            {
                printf(RED"%s"RST,check);
                i+=find_len;
            }
        }

        char c = line[i];
        //found tab and change count
        if (c=='\t')
        {
            printf(BLU"\\t"RST);
            count.tabs+=1;
        }

        //found newline and change count
        if (c=='\n')
        {
            printf(GRN"\\n"RST);
            count.newlines+=1;
        }

        //found return and change count
        if (c=='\r')
        {
            printf(MAG"\\r"RST);
            count.returns+=1;
        }

        //found space and change count
        if (c==' ')
        {
            printf(YEL"."RST);
            count.spaces+=1;
        }

        //found characters and change count
        else
        {
            printf("%c",c);
            count.characters+=1;
        }
    }
    return;
}