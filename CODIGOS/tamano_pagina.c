#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Tamano de pagina:%d \n\n", (int)sysconf(_SC_PAGESIZE));
    printf("Tamano de pagina:%d \n\n", (int)getpagesize());
    return EXIT_SUCCESS;
}
