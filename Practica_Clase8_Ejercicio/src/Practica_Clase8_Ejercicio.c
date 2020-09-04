/*
 ============================================================================
 Name        : Practica_Clase8_Ejercicio.c
 Author      : Damriel
 Version     : Clase 8 - Ejercicio ABM (Altas-Bajas-Modificaciones)
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO ABM:
 1)Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:
     Nombre
     Apellido
     Legajo (NO SE PUEDE REPETIR)
 a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.
 b- Mostrar un listado ordenado por Apellido
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Persona.h"
#define QTY_PERSONAS 200

int main(void) {
	setbuf(stdout,NULL);
	Persona arrayPersonas[QTY_PERSONAS];
	int opcion;

	inicializarArrayPersonas(arrayPersonas,QTY_PERSONAS);

	do
		{
			if(!utn_getIntLimited(&opcion, "*** MENU PRINCIPAL ***\n1-Imprimir lista de personas\n2-Cargar nueva persona\n3-Baja de una persona\n4-Modificar datos de una persona cargada\n5-Ordenar listado\n6-Salir\nElija una opcion: ","La opcion ingresada no es valida.\n",1,6,10))
			{
				switch(opcion)
				{
					case 1:
						mostrarArrayPersonas(arrayPersonas, QTY_PERSONAS);
						break;
					case 2:
						cargarPersona(arrayPersonas, QTY_PERSONAS);
						break;
					case 3:
						if(!borrarPersona(arrayPersonas, QTY_PERSONAS))
						{
							printf("No se borro ninguna persona.\n\n");
						}
						break;
					case 4:
						modificarPersona(arrayPersonas, QTY_PERSONAS);
						break;
					case 5:
						if(ordenarArrayPersonas_apellido(arrayPersonas, QTY_PERSONAS))
						{
							printf("\nSe ordenaron las personas por apellido.\n");
						}
						break;
				}
			}
		}while(opcion!=6);
		printf("Ha salido del programa. Hasta la proxima!");

	return EXIT_SUCCESS;
}













