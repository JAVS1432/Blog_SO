#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void manejador(int sig) {
    printf("Senal %d recibida. No morire tan facil.\n", sig);
}

int main() {
    if (signal(SIGINT, manejador) == SIG_ERR) exit(1);

    while (1) {
        printf("Esperando Ctrl+c...\n");
        sleep(2);
    }
    return 0;
}
