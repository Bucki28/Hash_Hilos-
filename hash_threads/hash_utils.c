#include "hash_utils.h"
#include <string.h>

unsigned long calcular_hash(const char *texto) {
    unsigned long hash = 5381;
    int c;

    while ((c = *texto++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}
