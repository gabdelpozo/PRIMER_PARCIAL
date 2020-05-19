

#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"
#include "Publicacion.h"
#include "utn.h"
#include "Informes.h"
#define CANTIDAD_CLIENTES 		100
#define CANTIDAD_PUBLICACIONES 1000
static const char ESTADOS[2][8]={"PAUSADO","ACTIVO"};
int main(void) {

	Publicacion arrayPublicaciones[CANTIDAD_PUBLICACIONES];
	Cliente arrayClientes[CANTIDAD_CLIENTES];
	int subMenu1;
	int idClientes=0;
	int idPublicaciones=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarIdClientes;
	int auxiliarIdPublicacion;
	int auxiliarIndicePublicacion;
	int contadorPub = 0;
	int subMenu2;
	int rubro;
	int maxActivos;
	int cantActivos;
	int maxActivosRubro;


	if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf(" ");
	}

	if(pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES) == 0)
	{
		printf("\n");
	}

	printf("PRIMER PARCIAL PROGRAMACION 1");
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un cliente"
							"\n2.Modificar un cliente"
							"\n3.Eliminar un cliente"
							"\n4.Publicar una nueva publicacion"
							"\n5.Pausar publicaciones"
							"\n6.Reanudar publicacion"
							"\n7.Imprimir Clientes"
							"\n8.Imprimir Publicaciones"
							"\n9.Informar Clientes"
							"\n10.Informar Publicaciones"
							"\n11.Salir\n\n",

							"\nError opcion invalida",1,11,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);
				if(auxiliarIndice >= 0)
				{
					if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;

			case 2:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarIdClientes,"\nIndique el ID del cliente a modificar: ","\nID invalido",0,idClientes,0) == 0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarIdClientes);
					if(	auxiliarIndice >= 0 &&
							cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice) == 0)
					{
						printf("\nModificacion de cliente realizada con exito\n");
					}
				}
				break;

			case 3:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarIdClientes,"\nIndique el ID del Cliente a eliminar: ","\nID invalido",0,idClientes,0)==0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarIdClientes);
					if(	auxiliarIndice >= 0 &&
							cli_bajaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice)== 0)
					{
						printf("\nBaja de cliente realizada con exito\n");
					}
				}
				break;

			case 4:
				auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
				if(auxiliarIndicePublicacion >= 0)
				{
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					if(	utn_getNumero(&auxiliarIdClientes,"\nID del Cliente: ","\nError",0,10000,2) == 0 &&
						cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarIdClientes) != -1)
					{
						pub_altaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion,&idPublicaciones,auxiliarIdClientes);
					}
					else
					{
						printf("\nEL ID NO EXISTE");
					}
				}
				break;

			case 5:
				pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
				if(utn_getNumero(&auxiliarIdClientes,"\nIndique el ID de la Publicacion a Pausar: ","\nID invalido",0,idClientes,0)==0)
				{
					auxiliarIndicePublicacion = pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,idClientes-1);

					if(auxiliarIndicePublicacion != -1)
					{
						pub_pausarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion);
					}
				}
				else
				{
					printf("\nPUBLICACION NO ENCONTRADA");
				}
				break;

			case 6:
				pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
				if(utn_getNumero(&auxiliarIdClientes,"\nIndique el ID de la Publicacion a Reanudar: ","\nID invalido",0,idClientes,0)==0)
				{
					auxiliarIndicePublicacion = pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPublicacion);
					if(auxiliarIndicePublicacion != -1)
					{
						pub_activarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion);
					}
				}
				else
				{
					printf("\nPUBLICACION NO ENCONTRADA");
				}
				break;

			case 7:
				for(int i=0;i<CANTIDAD_CLIENTES;i++)
				{
				if(arrayClientes[i].isEmpty == 0)
				{
					cli_imprimir(&arrayClientes[i]);

					contadorPub = 0;

					for(int j=0;j<CANTIDAD_PUBLICACIONES;j++)
					{
						if(arrayPublicaciones[j].isEmpty == 0)
						{
							if(arrayClientes[i].idCliente == arrayPublicaciones[j].idCliente)
							{
								if(arrayPublicaciones[j].estado == 1)
								{
									contadorPub++;
								}
							}
						}
					}
					printf("\nCantidad de publicaciones activas del cliente: %d\n",contadorPub);
				}
				}
				break;

			case 8:
				for(int i=0; i<CANTIDAD_PUBLICACIONES;i++)
				{
					if(arrayPublicaciones[i].isEmpty == 0)
					{
					pub_imprimir(&arrayPublicaciones[i]);
					printf("\nEl CUIT del cliente es: %s - Estado de la publicacion: %s\n",&arrayClientes[arrayPublicaciones[i].idCliente].cuit,ESTADOS[arrayPublicaciones[i].estado]);
					}
				}
				break;

			case 9:

				printf("\n1- Imprimir cliente con mas avisos activos\n2- Imprimir cliente con menos avisos activos\n3- Imprirmir clientes con mas avisos : ");
				scanf("%d",&subMenu1);

				switch (subMenu1) {
					case 1:
						info_imprimirClientesConMasAvisosActivos(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES);
						break;
					case 2:
						info_imprimirClientesConMasAvisosPausados(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES);
						break;
					case 3:
						info_imprimirClienteConMasAvisos(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES);
						break;
				}break;

			case 10:
				printf("\n1- Cantidad de publicaciones por rubro\n2- Rubro con mas publicaciones Activas\n3- Rubro con menos publicaciones Activas : ");
				scanf("%d",&subMenu2);
				switch (subMenu2) {
					case 1:
						printf("\nPor favor ingrese un rubro: ");
						scanf("%d", &rubro);
						int cantidadRubro = pub_obtenerCantidadPorRubro(arrayPublicaciones, CANTIDAD_PUBLICACIONES, rubro);
						printf("\nCantidad de publicaciones del rubro %d: %d", rubro , cantidadRubro);
						break;

					case 2:
						maxActivos = -1;
						for (int i = 0 ; i < CANTIDAD_PUBLICACIONES ; i ++) {
							if (arrayPublicaciones[i].isEmpty == 0){
								cantActivos = pub_obtenerCantidadActivosPorRubro(arrayPublicaciones, CANTIDAD_PUBLICACIONES,
										arrayPublicaciones[i].rubro);
								if (cantActivos > maxActivos) {
									maxActivos = cantActivos;
									maxActivosRubro = arrayPublicaciones[i].rubro;
								}
							}
						}
						printf("\nRubro con mas publicaciones Activas: %d Cantidad: %d", maxActivosRubro , maxActivos);
						break;

					case 3:
						maxActivos = 10000;
						for (int i = 0 ; i < CANTIDAD_PUBLICACIONES ; i ++){
							if (arrayPublicaciones[i].isEmpty == 0){
								cantActivos = pub_obtenerCantidadActivosPorRubro(arrayPublicaciones, CANTIDAD_PUBLICACIONES,
											arrayPublicaciones[i].rubro);
								if (cantActivos < maxActivos) {
									maxActivos = cantActivos;
									maxActivosRubro = arrayPublicaciones[i].rubro;
								}
							}
						}
						printf("\nRubro con menos publicaciones Activas: %d Cantidad: %d", maxActivosRubro , maxActivos);
						break;
					}
						break;

					case 11:
					break;
				}

			}

	}while(opcion != 11);

	return EXIT_SUCCESS;
}




