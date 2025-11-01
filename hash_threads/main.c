#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para sleep()
#include "worker.h"

#define MAX_HILOS 16

char *patron_global;
int longitud_fragmento;
int cantidad_hilos;

void error_y_salida(const char *mensaje) {
    fprintf(stderr, "Error: %s\n", mensaje);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error_y_salida("Uso: ./buscador_hash <numero_de_hilos>");
    }

    cantidad_hilos = atoi(argv[1]);
    if (cantidad_hilos <= 0 || cantidad_hilos > MAX_HILOS) {
        error_y_salida("Cantidad de hilos invalida. Debe ser entre 1 y 16.");
    }

    FILE *archivo = fopen("entrada.txt", "r");
    if (archivo == NULL) {
        error_y_salida("No se pudo abrir el archivo entrada.txt");
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), archivo) == NULL) {
        fclose(archivo);
        error_y_salida("Archivo vacio o error leyendo");
    }
    fclose(archivo);

    // Eliminar salto de linea final si existe
    buffer[strcspn(buffer, "\n")] = 0;

    patron_global = strdup(buffer);

    longitud_fragmento = 0;
    for (int i = 0; patron_global[i] != '\0'; i++) {
        if (patron_global[i] == '?') {
            longitud_fragmento++;
        }
    }

    printf("Texto base leido: %s\n", patron_global);
    printf("Longitud del fragmento variable: %d\n", longitud_fragmento);

    iniciar_busqueda_parallel(patron_global, longitud_fragmento, cantidad_hilos);

    free(patron_global);

    return 0;
}
