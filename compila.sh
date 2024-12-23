#!/bin/bash
# compila.sh

# Compila test.c
gcc -c test.c

# Compila libreria.c
gcc -c libreria.c

# Enlaza los archivos objeto para crear el ejecutable
gcc -o compilatl.sh test.o libreria.o

#He creado otro script para que no se reescriba a si mismo
