#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define RST "\x1B[0m"

int main(int argc, char *argv[])
{
    FILE *fp;                                           //create file pointer
    if (fopen(argv[1],"r")!=NULL)                       //test if file exists 
        {
        fp=fopen(argv[1],"r");                          //assign file pointer to argv[1] since file is valid
        }
        else
        {
        printf("File %s not found!\n",argv[1]);
        exit(0);
        }
    int nl=0,tb=0,ch=0;                                 //assigns variables for newline,tab and character then set counts to 0
    char c;                                             //create c char to get char input from file
    if (argv[2]!=NULL)                                  //if search string was given determine length and assign pointer
    {
        char *s=argv[2];                                //assign second variable from command line as searchable string
        int slen=strlen(argv[2]);
        printf("Searching for string "MAG"%s"RST" of size "MAG"%d\n"RST,s,slen);
    }
    while ((c=getc(fp))!=EOF)                           //while c isnt the endof file character keep reading from file
    {
        if (c=='\t')
        {
            printf(BLU"/t"RST);
            ++tb;                                       //iterate when tab is detected
        }                            
        if (c=='\n')
        {
            printf(GRN"/n"RST);
            ++nl;                                       //iterate when newline is detected
        }
        if (c!=' '&&c!='\n'&&c!='\t')
            ++ch;                                       //iterate when a char is detected
        printf("%c",c);                                 //print out the character read from file
    }
    printf(RED"Chars=%d "GRN"Lines=%d "BLU"Tabs=%d\n"RST,ch,nl,tb);  //print tally for nl,tb and ch
    fclose(fp);
    return 0;
}
