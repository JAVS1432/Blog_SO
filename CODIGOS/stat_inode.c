#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat sb;
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }
    
    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        return 1;
    }

    printf("I-nodo: %ld\n", (long) sb.st_ino);
    printf("Tamaño: %lld bytes\n", (long long) sb.st_size);
    printf("Ultimo cambio: %s", ctime(&sb.st_ctime));
    return 0;
}
