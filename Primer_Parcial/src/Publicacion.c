#include "Publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char ESTADOS[2][8]={"PAUSADO","ACTIVO"};

#include "utn.h"

/**
 * \brief Imprime los datos de un publicacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(Publicacion* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID de la Publicacion: %d - Texto del aviso: %s - Numero de Rubro: %d -  Estado: %s - ID del Cliente: %d\n",pElemento->idPub,pElemento->texto,pElemento->rubro,ESTADOS[pElemento->estado],pElemento->idCliente);
	}
	return retorno;
}

/**
 * \brief Imprime el array de publicaciones
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un publicacion en una posicion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		if(	utn_getNumero(&bufferPublicacion.rubro,"\nEscriba numero de Rubro: ", "\nError",1,100,2) == 0 &&
			utn_getDescripcion(bufferPublicacion.texto,TEXTO_LEN,"\nEscriba Texto del aviso: ", "\nError",2)== 0)
		{
			respuesta = 0;
			bufferPublicacion.idCliente = idCliente;
			bufferPublicacion.idPub = *idPublicacion;
			bufferPublicacion.estado = 1;
			bufferPublicacion.isEmpty = 0;
			array[indice] = bufferPublicacion;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}

/**
 * \brief Pausa a una publicacion en una posicion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int pub_pausarArray(Publicacion* array,int limite, int indice)
{
	int respuesta = 0;
	int  estado = 0;
	printf("%d",indice);
	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		//if(	!utn_getNumero(&estado,"\nIngrese opcion[0:PAUSAR PUBLICACION]: ", "\nError",0,0,2))
		//{
			respuesta = 0;
			array[indice].estado;
			char respuestaChar;

			if(array[indice].estado == 1){
				printf("\nSeguro desea pausar la publicacion? s/n: ");
				scanf("%s",&respuestaChar);
				if(estado == 0 && respuestaChar == 's')
				{
					printf("\nLa publicacion fue pausada con exito\n");
					array[indice].estado = 0;
				}else if(estado == 0 && respuestaChar == 'n'){
					printf("\nLa publicacion seguira activa\n");
				}else{
					printf("\nIngrese una opcion valida\n");
				}
			}else
			{
				printf("\nNo se puede pausar la publicacion, ya esta inactiva\n");
			}
		}
	//}

	return respuesta;
}
/**
 * \brief Actualiza los datos de un publicacion en una posicion del array de pausado a activo
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_activarArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;
	int  estado = 0;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && estado == 0)
	{
		if(	!utn_getNumero(&estado,"\nIngrese opcion [1:REANUDAR PUBLICACION]: ", "\nError",0,1,2))
		{
			respuesta = 0;
			array[indice].estado;
			char respuestaChar;

			if(array[indice].estado == 0)
			{
			printf("\nSeguro desea reanudar la publicacion? s/n: ");
			scanf("%s",&respuestaChar);
			if(estado == 0 && respuestaChar == 's')
			{
				printf("\nLa publicacion fue reanudada con exito\n");
				array[indice].estado = 1;
			}
				else if(estado == 0 && respuestaChar == 'n')
				{
					printf("\nLa publicacion seguira activa\n");
				}
				else
				{
					printf("\nIngrese una opcion valida\n");
				}
			}
			else
			{
				printf("\nNo se puede reanudar, ya esta activa\n");
			}
		}
		}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array publicacion Array de publicacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pub_buscarId(Publicacion array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].idPub == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de publicaciones
 * \param limite Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/** \brief Informa la cantidad de publicaciones activas del rubro ingresado
* \param array publicacion Array de publicacion
* \param limite int Tamaño del array
* \param rubro int Numero de rubro
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int pub_obtenerCantidadPorRubro(Publicacion* arrayPublicaciones, int limite, int rubro) {
	int cantRubro = 0;
	for (int i = 0 ; i < limite ; i++) {
		if (arrayPublicaciones[i].isEmpty == 0) {
			if (rubro == arrayPublicaciones[i].rubro) {
				cantRubro++;
			}
		}
	}

	return cantRubro;
}

/** \brief Informa al rubro con mas publicaciones activas
* \param array publicacion Array de publicacion
* \param limite int Tamaño del array
* \param rubro int Numero de rubro
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int pub_obtenerCantidadActivosPorRubro(Publicacion* arrayPublicaciones, int limite, int rubro) {
	int cantActivos = 0;
	for (int i = 0 ; i < limite ; i ++) {
		if (arrayPublicaciones[i].isEmpty == 0){
			if (rubro == arrayPublicaciones[i].rubro && arrayPublicaciones[i].estado == 1) {
				cantActivos++;
			}
		}
	}

	return cantActivos;
}











