// Algoritmo del Banquero - Basado en la subrutina de Dijkstra
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Datos de ejemplo
    int dinero = 100;      // Capital disponible
    int capital = 100;     // Capital total
    int N = 5;             // Número de procesos
    
    int demanda[] = {0, 60, 70, 60, 80, 90};    // Demanda de cada proceso (índice 0 no usado)
    int prestamo[] = {0, 50, 60, 50, 75, 85};   // Préstamo actual de cada proceso
    
    bool seguro, inseguro[N + 1];
    
    for(int i = 1; i <= N; i++) inseguro[i] = true;
    
    printf("=== Algoritmo del Banquero ===\n");
    printf("Capital inicial: %d\n", dinero);
    printf("\nEvaluando procesos:\n\n");
    
    for(int i = 1; i <= N; i++) {
        if (inseguro[i] && (demanda[i] <= dinero)) {
            inseguro[i] = false;
            printf("Proceso %d: demanda=%d, dinero=%d -> SEGURO\n", i, demanda[i], dinero);
            dinero = dinero + prestamo[i];
            printf("  Dinero recuperado: dinero ahora = %d\n\n", dinero);
        } else if (inseguro[i]) {
            printf("Proceso %d: demanda=%d > dinero=%d -> NO ASIGNABLE\n\n", i, demanda[i], dinero);
        }
    }
    
    printf("Dinero final: %d\n", dinero);
    if (dinero == capital) {
        seguro = true;
        printf("Estado: SEGURO\n");
    } else {
        seguro = false;
        printf("Estado: INSEGURO\n");
    }
    
    return 0;
}
