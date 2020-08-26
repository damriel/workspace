/*
 * utn.c
 *
 *  Created on: 20 ago. 2020
 *      Author: Damriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********** DECLARACIONES **********/
static int myGets(char* cadena, int longitud);
/*** INT ***/
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
/*** FLOAT ***/
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
/*** CHAR ***/
static int myGetsForChar(char* cadena, int longitud);
static int esCaracter(char* cadena);
static int getChar(char* pResultado);

/********** FUNCIONES **********/

static int myGets(char* cadena, int longitud)
{
	int retorno=0;
	if(cadena!=NULL && longitud>0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		retorno=1;
	}
	return retorno;
}

static int esNumerica(char* cadena)
{
	int retorno=1;
	int i=0;

	if(cadena[0]=='-')
	{
		i=1;
	}
	for( ; cadena[i]!='\0'; i++)
	{
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(myGets(buffer, sizeof(buffer)) && esNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		retorno = 0;
	}
	return retorno;
}

int utn_getIntLimited(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getIntSimple(int* pResultado, char* mensaje, char* mensajeError)
{
	int retorno = -1;
	int buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&buffer)==0)
			{
				*pResultado=buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}while(retorno==-1);
	}
	return retorno;
}

/***********************************************************************************************************************************************************************************************************/
/***********************************************************************************************************************************************************************************************************/
/***********************************************************************************************************************************************************************************************************/
/***********************************************************************************************************************************************************************************************************/

static int esFlotante(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorComa=0;
	int flagNegativo=0;

	if(cadena[0]=='-')
	{
		i=1;
		flagNegativo=1;
	}
	for( ; cadena[i]!='\0'; i++)
	{
		if((cadena[i]>'9' || cadena[i]<'0') && cadena[i]!='.')
		{
			retorno=0;
			break;
		}
		else if(cadena[i]=='.' && flagNegativo==1)
		{
			if(i==1)
			{
				retorno=0;
				break;
			}
			else
			{
				contadorComa++;
			}
		}
		else if(cadena[i]=='.' && flagNegativo==0)
		{
			if(i==0)
			{
				retorno=0;
				break;
			}
			else
			{
				contadorComa++;
			}
		}
	}
	if(contadorComa>1)
	{
		retorno=0;
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(myGets(buffer, sizeof(buffer)) && esFlotante(buffer))
	{
		*pResultado = atof(buffer);
		retorno = 0;
	}
	return retorno;
}

int utn_getFloatLimited(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getFloatSimple(float* pResultado, char* mensaje, char* mensajeError)
{
	int retorno = -1;
	float buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&buffer)==0)
			{
				*pResultado=buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}while(retorno==-1);
	}
	return retorno;
}

/***********************************************************************************************************************************************************************************************************/
/***********************************************************************************************************************************************************************************************************/
/***********************************************************************************************************************************************************************************************************/
/***********************************************************************************************************************************************************************************************************/

static int myGetsForChar(char* cadena, int longitud)
{
	int retorno=0;
	if(cadena!=NULL && longitud>0 && fgets(cadena,longitud,stdin)==cadena && cadena[1]=='\n')
	{
		fflush(stdin);
		cadena[1]='\0';
		retorno=1;
	}

	return retorno;
}

static int esCaracter(char* cadena)
{
	int retorno=1;

	if(cadena[0]<' ' || cadena[0]>'~') //SOLO CARACTERES ASCII IMPRIMIBLES (NO EXTENDIDOS)
	{
		retorno=0;
	}
	return retorno;
}

static int getChar(char* pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(myGetsForChar(buffer, sizeof(buffer)) && esCaracter(buffer))
	{
		*pResultado = buffer[0];
		retorno = 0;
	}
	return retorno;
}

int utn_getCharLimited(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(getChar(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getCharSimple(char* pResultado, char* mensaje, char* mensajeError)
{
	int retorno = -1;
	char buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(getChar(&buffer)==0)
			{
				*pResultado=buffer;
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}while(retorno==-1);
	}
	return retorno;
}
