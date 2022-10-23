#include <stdio.h>
#include <string.h>

int slen(char *s)
{
    int n;
    for (n=0;*s!='\0';n++,s++);
    return n;
}

int main()
{
    char str[25];
    printf("input string: ");
    scanf("%s",str);
    printf("length of string %d",slen(str));
    return 0;
}
