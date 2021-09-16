//C Library Headers
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//Linux Library Headers
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>


int main (int argc, char *argv[]) {
    if ( argc != 2 )
        {
        printf("Please specify com port. Example: serial.exe COM1\n");
        exit(0);
        }
    int com_port=atoi(argv[1]);
    char unicode_char[]="ì";
    //temporary printf to verify arguments were being fed from command line and ASCII code 141 was printing correctly.
    printf("COM port is set to:%d\n",com_port);
    printf("Trailing ASCII set to: %s\n",unicode_char);
    int serial_port=open("/dev/ttyS4",O_RDWR);
    if (serial_port < 0) {
        printf("Error %i from open: %s\n",errno,strerror(errno));
    }
    return 0;
}
