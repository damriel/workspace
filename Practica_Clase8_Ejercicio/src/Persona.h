/*
 * Persona.h
 *
 *  Created on: 27 ago. 2020
 *      Author: Damriel
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nombre[50];
	char apellido[50];
	int legajo;
	int isEmpty;
}Persona;

int inicializarArrayPersonas(Persona* pArray, int limite);

int mostrarArrayPersonas(Persona* pArray, int limite);

int cargarPersona(Persona* pArray, int limite);

int confirmarLegajo(Persona* pArray, int limite, int* legajo);

int buscarPersona(Persona* pArray, int limite, int* indice);

int borrarPersona(Persona* pArray, int limite);

int modificarPersona(Persona* pArray, int limite);

int ordenarArrayPersonas_apellido(Persona* pArray, int limite);

#endif /* PERSONA_H_ */
