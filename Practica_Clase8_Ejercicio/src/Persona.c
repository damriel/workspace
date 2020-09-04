/*
 * Persona.c
 *
 *  Created on: 27 ago. 2020
 *      Author: Damriel
 */
#include <string.h>
#include "utn.h"
#include "Persona.h"

int inicializarArrayPersonas(Persona* pArray, int limite)
{
	int retorno=-1;
	int i;

	if(pArray!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}

/*
 * brief Recibe un array e imprime todas las posiciones ocupadas.
 * param pArray
 * param limite
 * return Devuelve 0 si se imprimió al menos una posicion, 1 si no hay posiciones ocupadas y -1 si hay error en los parametros de la funcion.
 *
 */
int mostrarArrayPersonas(Persona* pArray, int limite)
{
	int retorno=-1;
	int i;
	int flagEmpty=1;

	if(pArray!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty==0)
			{
				printf("NOMBRE: %s - APELLIDO: %s - LEGAJO: %d\n", pArray[i].nombre, pArray[i].apellido, pArray[i].legajo);
				flagEmpty=0;
			}
		}
		printf("\n\n");
		retorno=0;
	}
	if(flagEmpty==1)
	{
		printf("Aun no se cargaron personas en la agenda.\n\n\n");
		retorno=1;
	}
	return retorno;
}


int cargarPersona(Persona* pArray, int limite)
{
	int retorno=-1;
	int legajo;
	int i;

	if(pArray!=NULL && limite>0)
	{
		printf("\n** Opcion 2 - Cargar persona **\n");
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty==1)
			{
				utn_getSoloLetras(pArray[i].nombre,sizeof(pArray[i].nombre),"Ingrese el nombre de la persona: ","Error. Solo puedes usar letras mayusculas y minusculas.\n",5);
				utn_getSoloLetras(pArray[i].apellido,sizeof(pArray[i].apellido),"Ingrese el apellido de la persona: ","Error. Solo puedes usar letras mayusculas y minusculas.\n",5);
				if(confirmarLegajo(pArray, limite, &legajo))
				{
					pArray[i].legajo=legajo;
				}
				pArray[i].isEmpty=0;
				printf("Se ha cargado exitosamente la siguiente persona:\nNOMBRE: %s - APELLIDO: %s - LEGAJO: %d\n\n\n", pArray[i].nombre, pArray[i].apellido, pArray[i].legajo);
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int confirmarLegajo(Persona* pArray, int limite, int* legajo)
{
	int retorno=0;
	int bufferLegajo;
	int i;
	int repetido;

	do
	{
		repetido=0;
		utn_getIntSimple(&bufferLegajo,"Ingrese el legajo de la persona: ","Error. El legajo solo puede contener numeros.\n");
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty==0 && pArray[i].legajo==bufferLegajo)
			{
				printf("El legajo ingresado ya existe.\n");
				repetido=1;
				break;
			}
		}
		if(!repetido)
		{
			*legajo=bufferLegajo;
			retorno=1;
		}
	}while(repetido);

	return retorno;
}


int buscarPersona(Persona* pArray, int limite, int* indice)
{
	int retorno=0;
	int i;
	int flagFound=0;
	int bufferLegajo;

	if(pArray!=NULL && limite>0 && indice!=NULL)
	{
		utn_getIntSimple(&bufferLegajo,"Ingrese el legajo de la persona que busca: ","Error. El legajo solo puede contener numeros.");
		for(i=0;i<limite;i++)
		{
			if(pArray[i].legajo==bufferLegajo && pArray[i].isEmpty==0)
			{
				printf("Persona:\nNOMBRE: %s - APELLIDO: %s - LEGAJO: %d\n", pArray[i].nombre, pArray[i].apellido, pArray[i].legajo);
				*indice=i;
				flagFound=1;
				break;
			}
		}
		retorno=1;
	}
	if(!flagFound)
	{
		printf("No se encontró persona con el legajo ingresado.\n\n\n");
		retorno=-1;
	}
	return retorno;
}


int borrarPersona(Persona* pArray, int limite)
{
	int retorno=0;
	int index;

	if(pArray!=NULL && limite>0)
	{
		printf("\n** Opcion 3 - Borrar persona **\n");
		if(buscarPersona(pArray, limite, &index))
		{
			pArray[index].isEmpty=1;
			printf("Se ha borrado exitosamente.\n\n");
			retorno=1;
		}
	}
	return retorno;
}



int modificarPersona(Persona* pArray, int limite)
{
	int retorno=-1;
	int index;
	int opcion;
	char bufferNombre[51];
	char bufferApellido[51];
	int bufferLegajo;
	int confirmacion;
	int cambioNombre=0;
	int cambioApellido=0;
	int cambioLegajo=0;

	if(pArray!=NULL && limite>0)
	{
		printf("\n** Opcion 4 - Modificar persona **\n");
		if(buscarPersona(pArray, limite, &index))
		{
			do
			{
				utn_getIntLimited(&opcion,"\n** Menu de Modificacion **\n\n"
												"Que desea modificar?\n"
												"1-Nombre\n"
												"2-Apellido\n"
												"3-Legajo\n"
												"4-Guardar cambios\n"
												"5-Volver al menu principal\n"
												"Ingrese una opcion: ","Error. La opcion ingresada es incorrecta.\n",1,5,5);
				switch(opcion)
				{
				case 1:
					if(utn_getSoloLetras(bufferNombre,sizeof(bufferNombre),"Ingrese el nuevo nombre: ","Error. Solo se aceptan letras.\n",5)==0)
					{
						printf("NUEVO NOMBRE: %s\n", bufferNombre);
						cambioNombre=1;
						break;
					}
					printf("Se acabaron los reintentos. Volviendo al menu de modificacion...\n\n");
					break;
				case 2:
					if(utn_getSoloLetras(bufferApellido,sizeof(bufferApellido),"Ingrese el nuevo apellido: ","Error. Solo se aceptan letras.\n",5)==0)
					{
						printf("NUEVO APELLIDO: %s\n", bufferApellido);
						cambioApellido=1;
						break;
					}
					printf("Se acabaron los reintentos. Volviendo al menu de modificacion...\n\n");
					break;
				case 3:
					if(confirmarLegajo(pArray, limite, &bufferLegajo))
					{
						printf("NUEVO LEGAJO: %d\n", bufferLegajo);
						cambioLegajo=1;
					}
					else
					{
						printf("Ha ocurrido un error en el codigo.\n");
					}
					break;
				case 4:
					if(cambioNombre || cambioApellido || cambioLegajo)
					{
						if(cambioNombre)
						{
							strncpy(pArray[index].nombre, bufferNombre, sizeof(pArray[index].nombre));
							cambioNombre=0;
						}
						if(cambioApellido)
						{
							strncpy(pArray[index].apellido, bufferApellido, sizeof(pArray[index].apellido));
							cambioApellido=0;
						}
						if(cambioLegajo)
						{
							pArray[index].legajo=bufferLegajo;
							cambioLegajo=0;
						}
						printf("Se guardaron las modificaciones.\n");
					}
					else
					{
						printf("No hay modificaciones sin guardar.\n");
					}
					break;
				case 5:
					if(cambioNombre || cambioApellido || cambioLegajo)//((avisoNombre && seGuardoNombre==0) || (avisoApellido && seGuardoApellido==0) || (avisoLegajo && seGuardoLegajo==0))
					{
						printf("Hay cambios sin guardar en esta persona.\n");
						if(utn_getIntLimited(&confirmacion,"Esta seguro que desea salir y perder los cambios?\nElija una opcion (1-Si / 2-No): ","La opcion ingresada no es valida.\n",1,2,5)==0 && confirmacion==1)
						{
							printf("Se descartaron los cambios. Volviendo al menu principal...\n\n");
							opcion=6;
							break;
						}
						else
						{
							printf("Cancelado. Volviendo al menu de modificaciones...\n");
							opcion=5;
							break;
						}
					}
					opcion=6;
					break;
				}

			}while(opcion!=6);
			retorno=0;
		}
	}
	return retorno;
}

int ordenarArrayPersonas_apellido(Persona* pArray, int limite)
{
	int retorno=0;
	int flagSwap;
	int i;
	int nuevoLimite;
	char bufferChar[51];
	int bufferInt;

	if(pArray!=NULL && limite>=0)
	{
		nuevoLimite=limite-1;
		do
		{
			flagSwap=0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(pArray[i].isEmpty==0 && pArray[i+1].isEmpty==0 && strcmp(pArray[i].apellido, pArray[i+1].apellido)>0)
				{
					flagSwap=1;
					strncpy(bufferChar, pArray[i].nombre, sizeof(bufferChar));
					strncpy(pArray[i].nombre, pArray[i+1].nombre, sizeof(pArray[i].nombre));
					strncpy(pArray[i+1].nombre, bufferChar, sizeof(pArray[i+1].nombre));

					strncpy(bufferChar, pArray[i].apellido, sizeof(bufferChar));
					strncpy(pArray[i].apellido, pArray[i+1].apellido, sizeof(pArray[i].apellido));
					strncpy(pArray[i+1].apellido, bufferChar, sizeof(pArray[i+1].apellido));

					bufferInt=pArray[i].legajo;
					pArray[i].legajo=pArray[i+1].legajo;
					pArray[i+1].legajo=bufferInt;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno=1;
	}
	return retorno;
}








