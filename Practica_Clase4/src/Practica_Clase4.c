/*
 ============================================================================
 Name        : Practica_Clase4.c
 Author      : Damriel
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
	float flotante;
	char letra;
	int respuesta;

	respuesta = utn_getCharLimited(&letra, "Letra? \n", "Error, letra debe ser desde A a J\n", 'A', 'J', 1);
	if(respuesta == 0)
	{
		printf("\nLa letra es: %c\n",letra);
	}
	else
	{
		printf("ERROR.\n");
	}

	respuesta = utn_getIntLimited(&edad, "Edad? \n", "Error, la edad debe ser desde 0 a 199\n", 0, 199, 2);
	if(respuesta == 0)
	{
		printf("La edad es: %d\n",edad);
	}
	else
	{
		printf("ERROR.\n");
	}

	respuesta = utn_getFloatLimited(&flotante, "Flotante? \n", "Error, flotante debe ser desde -999 a 999\n", -999, 999, 4);
	if(respuesta == 0)
	{
		printf("El flotante es: %f\n",flotante);
	}
	else
	{
		printf("ERROR.\n");
	}

	return EXIT_SUCCESS;
}
