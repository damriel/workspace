/*
 * utn.h
 *
 *  Created on: 20 ago. 2020
 *      Author: Damriel
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getIntLimited(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getIntSimple(int* pResultado, char* mensaje, char* mensajeError);

int utn_getFloatLimited(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getFloatSimple(float* pResultado, char* mensaje, char* mensajeError);

int utn_getCharLimited(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getCharSimple(char* pResultado, char* mensaje, char* mensajeError);

#endif /* UTN_H_ */
