#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h> // Para sleep()
#include "worker.h"
#include "hash_utils.h"

typedef struct {
    int hilo_id;
    char *patron;
    int longitud_fragmento;
    int total_hilos;
} datos_hilo_t;

void *worker_func(void *args) {
    datos_hilo_t *datos = (datos_hilo_t *)args;
    unsigned long hash_resultado;

    printf("Hilo %d iniciando busqueda en su rango\n", datos->hilo_id);

    // Simulacion de busqueda
    sleep(1);

    if (datos->hilo_id == 1) {
        printf("Hilo %d encontro resultado:\n", datos->hilo_id);
        printf("Fragmento: ejemplo\n");
        printf("Hash: 123450000\n");
    }

    pthread_exit(NULL);
}

void iniciar_busqueda_parallel(char *patron, int longitud, int num_hilos) {
    pthread_t *hilos = malloc(sizeof(pthread_t) * num_hilos);
    datos_hilo_t *datos = malloc(sizeof(datos_hilo_t) * num_hilos);

    for (int i = 0; i < num_hilos; i++) {
        datos[i].hilo_id = i + 1;
        datos[i].patron = patron;
        datos[i].longitud_fragmento = longitud;
        datos[i].total_hilos = num_hilos;
        pthread_create(&hilos[i], NULL, worker_func, &datos[i]);
    }

    for (int i = 0; i < num_hilos; i++) {
        pthread_join(hilos[i], NULL);
    }

    free(hilos);
    free(datos);

    printf("Busqueda completada por todos los hilos.\n");
}
