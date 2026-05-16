#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo si;
    sysinfo(&si);
    printf("Total RAM: %ld KB\n", si.totalram / 1024);
    printf("Libre RAM: %ld KB\n", si.freeram / 1024);
    printf("Swap Total: %ld KB\n", si.totalswap / 1024);
    return 0;
}
