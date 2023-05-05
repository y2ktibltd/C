#include <stdlib.h>
#include <stdio.h>
#include "open_file.h"

#define FILEMODE "r"

//check if file name is valid and can be read
FILE *open_file(char *filename)
{
    FILE *f;
    if (fopen(filename,FILEMODE)!=NULL)
    {
        f=fopen(filename,FILEMODE);
        return f;
    }
    else
    {
        printf("File %s not found!\n",filename);
        exit(0);
    }
}
