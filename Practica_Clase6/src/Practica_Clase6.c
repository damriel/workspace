/*
 ============================================================================
 Name        : Practica_Clase6.c
 Author      : Damriel
 Version     : FUNCIONES DE STRINGS
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/** LISTADO DE FUNCIONES DE string.h **/
/*
strncpy(auxiliar, nombre, sizeof(auxiliar); Recibe el array de "nombre" lo copia a "auxiliar" y el sizeof se utiliza para no desbordar la memoria.
strnlen(nombre,sizeof(nombre)); Devuelve el tamaño ocupado por el texto que tiene el array "nombre".
strncat(nombre, "LALALA", sizeof(nombre)); Concatena el texto "LALALA" con lo que hay en el array "nombre" sin pasarse del tamaño del array.
sprintf(buffer,"%d HOLA %f PROBANDO funciones Strings"); En lugar de imprimir por consola, guarda el texto ingresado en el segundo parametro en el array del primer parametro.
snprintf(auxiliar, sizeof(auxiliar), "OTRO TEXTO DE PRUEBA "); se guarda en "auxiliar" el texto/mascaras del tercer parametro, pudiendo concatenar mas de un string a la vez y el limite es el segundo parametro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL); //ESTO VA SIEMPRE EN WINDOWS
	int auxInt;
	/*
	char nombre[11]="JUAN"; // SOLO SE LE PUEDE ASIGNAR EN LA LINEA DE INICIALIZACION.
	char auxiliar[30]="";

	//strcpy(nombre, "MARIA"); // PARA ASIGNARLE UN VALOR EN OTRO LADO SE UTILIZA LA FUNCION STRCPY() PERO LA OPCION SEGURA DE LINEA 22
	//strcpy(auxiliar,nombre); // SON INSEGURAS, NO PREVEEN OVERFLOW DE MEMORIA

	strncpy(auxiliar,nombre,sizeof(auxiliar)); //TOMA COMO TERCER PARAMETRO EL LIMITE A COPIAR (como cada char ocupa 1 bit se puede usar el sizeof)

	strncat(nombre, " LALA", sizeof(nombre));

	sprintf(auxiliar,"MI SIZE OF ES %d ",sizeof(auxiliar));
	printf("\n%s\n",auxiliar);

	printf("SIZE Nombre mide %d ----- auxiliar mide %d", sizeof(nombre),sizeof(auxiliar));
	printf("\nSTRLEN Nombre mide %d ----- auxiliar mide %d", strnlen(nombre,sizeof(nombre)),strnlen(auxiliar,sizeof(auxiliar)));
	*/

	while(1)
	{
		if(utn_getNumero(&auxInt,"Numero?: ","ERROR\n",-2,10,2) == 0)
		{
			printf("El numero es: %d\n",auxInt);
		}
	}

	return EXIT_SUCCESS;
}
