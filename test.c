#include <stdio.h>

int main () {
    double a=0, b=1, fibonacci=0;
    for (int loop=0;loop<100;loop++){
        printf("%f\n",fibonacci);
        a=b;
        b=fibonacci;
        fibonacci=a+b;
        }
    return 0;
}
