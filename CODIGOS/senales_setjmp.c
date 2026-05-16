#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <unistd.h>

jmp_buf env;

void sigusr1_handler(int sig);

int main()
{
    int i;

    signal(SIGUSR1, sigusr1_handler);

    for (i = 0; i < 10; i++) {
        if (setjmp(env) == 0)
            printf("Punto a regresar en el estado %d\n", i);
        else
            printf("Regreso al punto del estado %d\n", i);

        fflush(stdout);
        sleep(10);
    }

    return EXIT_SUCCESS;
}

void sigusr1_handler(int sig)
{
    signal(SIGUSR1, sigusr1_handler);
    longjmp(env, 1);
}
