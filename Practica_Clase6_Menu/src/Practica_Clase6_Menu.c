/*
 ============================================================================
 Name        : Practica_Clase6_Menu.c
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
	int opcion;

	do
	{
		if(!utn_getIntLimited(&opcion, "Elija una opcion:\n1-Leer\n2-Mostrar\n3-Salir","La opcion ingresada no es valida.\n",1,3,10))
		{
			switch(opcion)
			{
				case 1:
					printf("Estoy Leyendo.\n");
					break;
				case 2:
					printf("Estoy Mostrando.\n");
					break;
			}
		}
	}while(opcion!=3);
	printf("Hasta la proxima!");
	return EXIT_SUCCESS;
}
