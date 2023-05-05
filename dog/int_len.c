#include "int_len.h"

//Macro for determining length of int
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