/*
 ============================================================================
 Name        : Practica_Clase4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL); //ESTO VA SIEMPRE EN WINDOWS

	int edad;
	int peso;
	char letra;
	int respuesta;

	respuesta = utn_getCharLimited(&letra, "Letra? \n", "Error, letra debe ser desde A a J\n", 'A', 'J', 1);
	if(respuesta == 0)
	{
		printf("\nLa letra es: %c",letra);
	}
	else
	{
		printf("ERROR.\n");
	}

	respuesta = utn_getIntLimited(&edad, "Edad? \n", "Error, la edad debe ser desde 0 a 199\n", 0, 199, 2);
	if(respuesta == 0)
	{
		printf("La edad es: %d",edad);
	}
	else
	{
		printf("ERROR.\n");
	}

	respuesta = utn_getIntLimited(&peso, "Peso? \n", "Error, peso debe ser desde 0 a 500\n", 0, 500, 3);
	if(respuesta == 0)
	{
		printf("El peso es: %d",peso);
	}
	else
	{
		printf("ERROR.\n");
	}

	return EXIT_SUCCESS;
}
