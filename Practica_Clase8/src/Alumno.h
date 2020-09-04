/*
 * Alumno.h
 *
 *  Created on: 27 ago. 2020
 *      Author: BiT_SOLUCIONES_iT
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

typedef struct
{
	int legajo;
	char nombre[51];
	float altura;
	int isEmpty;
}Alumno; //Siempre con mayuscula al comienzo para determinar que no es nativo del sistema

/**
 * \brief Imprimo el array de Alumnos
 * \param pArray Puntero al array de alumnos.
 * \param longitud Define el tamaño del array.
 * \return Retorna 0 (EXITO) si ok y -1 (ERROR) si no.
 *
 */
int imprimirArrayAlumnos(Alumno* pArray, int limite);

/**
 * \brief Inicializo el array de Alumnos
 * \param pArray Puntero al array de alumnos.
 * \param longitud Define el tamaño del array.
 * \return Retorna 0 (EXITO) si ok y -1 (ERROR) si no.
 *
 */
int inicializarArrayAlumnos(Alumno* pArray, int limite);

#endif /* ALUMNO_H_ */
