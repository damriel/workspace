/*
 ============================================================================
 Name        : Practica_Clase3.c
 Author      : Damriel
 Version     : Clase 3 - Funciones
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumarConLimite(int operador1, int operador2);

int main(void) {
	setbuf(stdout,NULL); //ESTO VA SIEMPRE EN WINDOWS

	int num1;
	int num2;
	int suma;

	printf("Ingrese un numero: \n");
	scanf("%d",&num1);
	printf("Ingrese otro numero: \n");
	scanf("%d",&num2);

	suma = sumarConLimite (num1,num2);
	printf("La suma es %d",suma);

	return EXIT_SUCCESS;
}

//Funciones auxiliares de mi programa

//definicion de la funcion sumarConLimite

int sumarConLimite(int operador1, int operador2)
{
	int resultado; //variable local de la funcion.

	resultado = operador1+operador2;

	if(resultado>100)
	{
		resultado=100;
	}
	return resultado;
}
