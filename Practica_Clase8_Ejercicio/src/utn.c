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
static int esFlotante(char* cadena, int limite);
static int getFloat(float* pResultado);
/*** CHAR ***/
static int myGetsForChar(char* cadena, int longitud);
static int esCaracter(char* cadena);
static int getChar(char* pResultado);
/*** STRING ***/
static int esLetras(char* cadena, int limite);

/**
 * \brief Lee de stdin hasta que encuentra un '\n'o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 * \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida.
 * \param longitud Define el tamaño de la cadena.
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
 * \param limite Define el tamaño de la cadena.
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
 * \brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado
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
 * \brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado. Itera hasta que se ingrese un numero valido.
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
			if(!getInt(&buffer))
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

/**
 * \brief Verifica si la cadena ingresada es un numero flotante.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tamaño de la cadena.
 * \return Retorna 1 (Verdadero) si la cadena es un numero flotante, 0 (Falso) si no lo es y -1 (Error) en caso de error
 *
 */
static int esFlotante(char* cadena, int limite)
{
	int retorno=1;
	int i=0;
	int contadorComa=0;

	for(i=0; i<limite && cadena[i]!='\0'; i++)
	{
		if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
		{
			continue;
		}
		if((cadena[i]>'9' || cadena[i]<'0') && cadena[i]!='.')
		{
			retorno=0;
			break;
		}
		else if(cadena[i]=='.')
		{
			contadorComa++;
			if(contadorComa>1)
			{
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtiene un numero flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no.
 *
 */
static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(pResultado!=NULL && !myGets(buffer, sizeof(buffer)) && esFlotante(buffer,sizeof(buffer)))
	{
		*pResultado = atof(buffer);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es el numero minimo a ser aceptado.
 * \param maximo Es el numero maximo a ser aceptado.
 * \param reintentos Es la cantidad de reintentos que tiene el usuario.
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no.
 *
 */
int utn_getFloatLimited(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(!getFloat(&buffer) && buffer>=minimo && buffer<=maximo)
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

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado. Itera hasta que se ingrese un numero valido.
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no.
 *
 */
int utn_getFloatSimple(float* pResultado, char* mensaje, char* mensajeError)
{
	int retorno = -1;
	float buffer;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(!getFloat(&buffer))
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

/*
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
 */

static int myGetsForChar(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))==1)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
			else
			{
				retorno=-2;
			}
		}
	}

	return retorno;
}

static int esCaracter(char* cadena)
{
	int retorno=1;

	if(cadena==NULL || cadena[0]<' ' || cadena[0]>'~') //SOLO CARACTERES ASCII IMPRIMIBLES (NO EXTENDIDOS)
	{
		retorno=0;
	}
	return retorno;
}

static int getChar(char* pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(!myGetsForChar(buffer, sizeof(buffer)) && esCaracter(buffer))
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
			if(!getChar(&buffer) && buffer>=minimo && buffer<=maximo)
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
			if(!getChar(&buffer))
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

/**********************************************************************************************************************************************************************************/

/**
 * \brief Verifica si la cadena ingresada esta compuesta solo de letras 'a-z' y 'A-Z'.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tamaño de la cadena.
 * \return Retorna 1 (Verdadero) si la cadena solo de letras, 0 (Falso) si no lo es y -1 (Error) en caso de error
 *
 */
static int esLetras(char* cadena, int limite)
{
	int retorno=-1;
	int i;

	if(cadena!=NULL && limite>0)
	{
		retorno=1;
		for(i=0; i<limite && cadena[i]!='\0'; i++)
		{
			if((cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A' || cadena[i]>'Z'))
			{
				retorno=0;
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
static int getString(char* pResultado, int limite)
{
	int retorno=-1;
	char bufferString[50];
	if(pResultado!=NULL && !myGets(bufferString,sizeof(bufferString)) && esLetras(bufferString,sizeof(bufferString)))
	{
		strncpy(pResultado,bufferString,limite);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Solicita una palabra, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param reintentos Es la cantidad de reintentos que tiene el usuario.
 * \return Retorna 0 si se obtuvo una palabra y -1 si no.
 *
 */
int utn_getSoloLetras(char* pResultado, int limite, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			if(!getString(bufferString, limite))
			{
				strncpy(pResultado,bufferString,limite);
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

int ordenarArrayInt(int* pArray, int limite)
{
	int retorno=-1;
	int flagSwap;
	int i;
	int contador=0;
	int buffer;
	int nuevoLimite;

	if(pArray!=NULL && limite>=0)
	{
		nuevoLimite=limite-1;
		do
		{
			flagSwap=0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(pArray[i]<pArray[i+1])
				{
					flagSwap=1;
					buffer=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=buffer;
				}
				contador++;
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno=contador;
	}
	return retorno;
}
