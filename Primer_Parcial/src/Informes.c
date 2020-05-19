/*
 * Informes.c
 *
 *  Created on: May 5, 2020
 *      Author: Gabriel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Informes.h"
#include "Cliente.h"
#include "Publicacion.h"
static const char ESTADOS[2][8]={"PAUSADO","ACTIVO"};

/** \brief Imprime al cliente con mas avisos activos
* \param array publicaciones Array de publicacion
* \param limite publicaciones int Tamaño del array
* \param array clientes Array de clientes
* \param limite clientes int Tamaño del array
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int info_imprimirClientesConMasAvisosActivos(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayClientes,int limiteClientes)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int contadorAvisosActivos;
	int mayor = -1;
	int idCliente;
	if(arrayPublicaciones != NULL && limitePublicaciones > 0 && arrayClientes != NULL && limiteClientes > 0)
	{
		for(i=0;i<limiteClientes;i++)
		{
			if(arrayClientes[i].isEmpty == 0)
			{
				contadorAvisosActivos = 0;
				for(int j=0;j<limitePublicaciones;j++)
				{
					if(arrayPublicaciones[j].isEmpty == 0)
					{
						if(arrayClientes[i].idCliente == arrayPublicaciones[j].idCliente)
						{
							contadorAvisosActivos++;

						}
					}
				}

				if(contadorAvisosActivos > mayor)
				{
					idCliente = arrayClientes[i].idCliente;
					mayor = contadorAvisosActivos;
				}

			}
		}
		printf("\nEl Cliente con mas avisos activos es: \n");
		cli_imprimir(&arrayClientes[idCliente]);

		printf("\nCantidad de avisos: %d",mayor);

	}
	return retorno;
}

/** \brief Imprime al cliente con mas avisos pausados
* \param array publicaciones Array de publicacion
* \param limite publicaciones int Tamaño del array
* \param array clientes Array de clientes
* \param limite clientes int Tamaño del array
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int info_imprimirClientesConMasAvisosPausados(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayClientes,int limiteClientes)
{
	int retorno = -1;
	int pausados;
	int auxiliarId;
	int avisosPausados;
	if(arrayPublicaciones != NULL && limitePublicaciones > 0 && arrayClientes != NULL && limiteClientes > 0)
	{
		pausados = -1;
		for(int i = 0 ; i < limiteClientes ; i++){
			cli_imprimir(&arrayClientes[i]);
			if(arrayClientes[i].isEmpty == 0){
			avisosPausados= 0;
			for(int j = 0 ; j < limitePublicaciones ; j++){
				if (arrayPublicaciones[j].isEmpty == 0){
					if(arrayClientes[i].idCliente == arrayPublicaciones[j].idCliente && arrayPublicaciones[j].estado == 0){
						avisosPausados++;
					}
				}
			}
				if(avisosPausados > pausados){
					auxiliarId = arrayClientes[i].idCliente;
					pausados = avisosPausados;
				}
			}
		}
		printf("\nEl cliente con mas avisos pausados es: \n");
		cli_imprimir(&arrayClientes[auxiliarId]);
		printf("\nCantidad de avisos pausados: %d",pausados);
	}
	return retorno;
}

/** \brief Imprime al cliente con mas avisos
* \param array publicaciones Array de publicacion
* \param limite publicaciones int Tamaño del array
* \param array clientes Array de clientes
* \param limite clientes int Tamaño del array
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/

int info_imprimirClienteConMasAvisos(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayClientes,int limiteClientes)
{

	int retorno = -1;
	int contAvisos;
	int auxiliarId;
	int avisosPausados;
	int maxAvisos = -1;

	for(int i = 0 ; i < limiteClientes ; i++){
		if(arrayClientes[i].isEmpty == 0){
		contAvisos= 0;
		for(int j = 0 ; j < limitePublicaciones ; j++){
			if (arrayPublicaciones[j].isEmpty == 0){
				if(arrayClientes[i].idCliente == arrayPublicaciones[j].idCliente){
					contAvisos++;
				}
			}
		}
			if(avisosPausados > maxAvisos){
				auxiliarId = arrayClientes[i].idCliente;
				maxAvisos = contAvisos;
			}
		}
	}
	printf("\nCliente con mas avisos:");
	cli_imprimir(&arrayClientes[auxiliarId]);
	printf("\nCantidad de avisos: %d",maxAvisos);
	return retorno;
}
