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

typedef struct
{
	int legajo;
	char nombre[51];
	float altura;
}Alumno;

int main(void) {
	setbuf(stdout,NULL);
	Alumno auxiliar;
	auxiliar.altura = 2.04;
	auxiliar.legajo = 25;
	strcpy(auxiliar.nombre,"Juan");

	printf("Nombre: %s - Legajo: %d - Altura: %f", auxiliar.nombre,auxiliar.legajo,auxiliar.altura);
	return EXIT_SUCCESS;
}
