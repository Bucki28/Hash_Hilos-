# Buscador multihilo de combinaciones hash en C

Este programa realiza la busqueda de cadenas que cumplen una condicion especifica sobre el resultado de una funcion hash. Utiliza la biblioteca pthreads para dividir entre varios hilos el espacio de combinaciones posibles a partir de un patron con caracteres a reemplazar.

## Requisitos

- Compilador GCC
- Biblioteca pthreads
- Archivo de entrada: archivo.txt
- Sistema operativo: Windows, Linux, macOS

## Compilacion

Ejecutar el siguiente comando desde la terminal dentro de la carpeta del proyecto:
Compilar:
gcc main.c worker.c hash_utils.c -lpthread -o buscador_hash
Y ejecutar:
./buscador_hash 4

## Uso

Coloque el patron a buscar en el archivo archivo.txt, usando el caracter '?' para las posiciones variables. Cada '?' se reemplaza por una letra minuscula del alfabeto a-z.

Luego ejecute el programa indicando la cantidad de hilos a utilizar. Por ejemplo, para usar 4 hilos:

./buscador_hash 4

## Ejemplo de salida

Texto base: El codigo secreto es ?????? y debe generar el hash correcto.
Hash base: 1117337332
Fragmento de longitud: 6 (total combinaciones: 308915776)
Buscando hash que termine con 4 ceros...

Hilo 3 encontro coincidencia:
    Texto: El codigo secreto es kkkkue y debe generar el hash correcto.
    Hash: 2129320000

Busqueda finalizada.

## Detalles adicionales

- El numero de hilos se especifica como argumento. Es posible modificar la condicion de validacion en el codigo fuente.
- Para pruebas iniciales, se recomienda usar patrones cortos debido a la cantidad de combinaciones posibles.
- La funcion hash y la validacion pueden adaptarse segun los requerimientos especificos del ejercicio.

## Notas
Autor
Miguel Angel Monroy Martin  
Codigo 160004643
.
