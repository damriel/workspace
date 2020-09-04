/*
 ============================================================================
 Name        : Practica_Clase8.c
 Author      : Damriel
 Version     : Clase 8 - ESTRUCTURAS
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Alumno.h"
#define QTY_ALUMNOS 1000

int main(void) {
	setbuf(stdout,NULL);
	Alumno auxiliar;
	Alumno arrayAlumnos[QTY_ALUMNOS];

	inicializarArrayAlumnos(arrayAlumnos, QTY_ALUMNOS);

	auxiliar.altura = 2.04;
	auxiliar.legajo = 25;
	strcpy(auxiliar.nombre,"Juan");
	auxiliar.isEmpty = 0;

	//printf("Nombre: %s - Legajo: %d - Altura: %f", auxiliar.nombre,auxiliar.legajo,auxiliar.altura);

	arrayAlumnos[2] = auxiliar; //Se copia todo el conjunto de datos dentro de auxiliar a la posicion 2 del array.

	imprimirArrayAlumnos(arrayAlumnos, QTY_ALUMNOS);

	return EXIT_SUCCESS;
}
