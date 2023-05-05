#include <string.h>
#include <stdbool.h>
#include "is_substring.h"
#include <stdio.h>

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

#define MAXLINE 256

//check for substring inside of string
bool is_substring(char *line, char *find)
{
    char line_copy[MAXLINE];
    strcpy(line_copy,line);
    int matches_copy = count.matches;
    for (int i = 0; i < strlen(line_copy); i++)
    {
        if (strstr(line_copy,find))
        {
            count.matches+=1;
            int find_len = strlen(find);
            char * find_location = strstr(line_copy,find);
            for (int i = 0; i < find_len; i++)
            {
                find_location[i]=' ';
            }
        }
    }
    if (count.matches > matches_copy)
    {
        return true;
    }
    else
    {
        return false;
    }
}