#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/statvfs.h>
int main()
{
 struct statvfs vfs;
 char *ruta="/";
 if (statvfs(ruta, &vfs) != 0) {
 perror ("llamado de statvfs");
 exit(EXIT_FAILURE);
 }
 printf("\tArchivo:%s",ruta);
 printf("\tTamaño de bloques: %ld\n", (long) vfs.f_bsize);
 printf("\tTamaño de fragmento: %ld\n", (long) vfs.f_frsize);
 printf("\tTamaño en unidades: %lu\n", (unsigned long) vfs.f_blocks);
 printf("\tBloques libres %lu\n", (unsigned long) vfs.f_bfree);
 printf("\tBloques Disponibles: %lu\n", (unsigned long) vfs.f_bavail);
 printf("\tNúmero de Inodos: %lu\n", (unsigned long) vfs.f_files);
 printf("\tNúmero de Inodos Libres: %lu\n", (unsigned long) vfs.f_ffree);
 printf("\tNúmero de Inodos Disponibles: %lu\n", (unsigned long) vfs.f_favail);
 printf("\tID del S.A.: %#lx\n", (unsigned long) vfs.f_fsid);
 printf("\tBandera: ");
 if (vfs.f_flag == 0) printf("(Ninguna)\n");
 else {
if ((vfs.f_flag & ST_RDONLY) != 0) printf("ST_RDONLY ");
if ((vfs.f_flag & ST_NOSUID) != 0) printf("ST_NOSUID");
printf("\n");
}
 printf("\tLongitud max para archivo: %ld\n", (long)vfs.f_namemax);
 return EXIT_SUCCESS;
}
