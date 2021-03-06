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
/***  INT  ***/
static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
/*** FLOAT ***/
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
/*** CHAR ***/
static int myGetsForChar(char* cadena, int longitud);
static int esCaracter(char* cadena);
static int getChar(char* pResultado);

/**
 * \brief Lee de stdin hasta que encuentra un '\n'o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 * \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida.
 * \param longitud Define el tama�o de la cadena.
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
static int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL) //fgets devuelve el puntero a bufferString si esta todo bien, sino devuelve NULL
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tama�o de la cadena.
 * \return Retorna 1 (Verdadero) si la cadena es numerica, 0 (Falso) si no lo es y -1 (Error) en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno=-1;
	int i;

	if(cadena!=NULL && limite>0)
	{
		retorno=1;
		for(i=0; i<limite && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno=-1;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no.
 *
 */
static int getInt(int* pResultado)
{
	int retorno=-1;
	char bufferString[50];
	if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumerica(bufferString,sizeof(bufferString)))
	{
		*pResultado=atoi(bufferString);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es el numero minimo a ser aceptado.
 * \param maximo Es el numero maximo a ser aceptado.
 * \param reintentos Es la cantidad de reintentos que tiene el usuario.
 * \return Retorna 0 si se obtuvo el numero entero y -1 si no.
 *
 */
int utn_getIntLimited(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(!getInt(&bufferInt) && bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado, itera hasta que se ingrese un numero valido
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \return Retorna 0 si se obtuvo el numero entero y -1 si no.
 *
 */
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
