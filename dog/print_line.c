//standard libraries
#include <stdio.h>
#include <string.h>
#include "print_line.h"

//define color codes for printf beautification
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define RST "\x1B[0m"

//create struct to hold counters
typedef struct
{
    int tabs;
    int newlines;
    int returns;
    int characters;
    int matches;
} Count;

extern Count count;

void print_line(char *line, char *find)
{
    int line_len=strlen(line);
    int find_len=strlen(find);
    for (int i = 0; i < line_len; i++)
    {
        char c = line[i];
        if (c=='\t')
        {
            printf(BLU"\\t"RST);
            count.tabs+=1;
        }
        if (c=='\n')
        {
            printf(GRN"\\n"RST);
            count.newlines+=1;
        }
        if (c=='\r')
        {
            printf(MAG"\\r"RST);
            count.returns+=1;
        }
        if (c !=' ')
        {
            printf("%c",c);
            count.characters+=1;
        }
        else
        {
            printf("%c",c);
        }
    }
}