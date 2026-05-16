#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h> 
int main(int argc, char *argv[])
{
 struct stat sb;
 if (argc != 2) {
 fprintf(stderr, "Uso: %s <ruta_dispositivo>\n", argv[0]);
 exit(EXIT_FAILURE);
 }
 // stat obtiene información sobre el archivo de dispositivo
 if (stat(argv[1], &sb) == -1) {
 perror("stat");
 exit(EXIT_FAILURE);
 }
 // Verificar si es un dispositivo de bloques o caracteres
 printf("Archivo: %s\n", argv[1]);
 if (S_ISCHR(sb.st_mode)) {
 printf("Tipo: Dispositivo de caracteres (Char)\n");
 } else if (S_ISBLK(sb.st_mode)) {
 printf("Tipo: Dispositivo de bloques (Block)\n");
 } else {
 printf("Tipo: No es un dispositivo de bloques o caracteres\n");
 exit(EXIT_FAILURE);
 }
 // major() y minor() extraen los números correspondientes
 printf("Número Mayor (Major): %u\n", major(sb.st_rdev));
 printf("Número Menor (Minor): %u\n", minor(sb.st_rdev));
 return EXIT_SUCCESS;
}
