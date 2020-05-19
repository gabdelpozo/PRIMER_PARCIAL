/*
 * Informes.h
 *
 *  Created on: May 5, 2020
 *      Author: Gabriel
 */
#include "Cliente.h"
#include "Publicacion.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int info_imprimirClientesConMasAvisosActivos(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayClientes,int limiteClientes);
int info_imprimirClientesConMasAvisosPausados(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayClientes,int limiteClientes);
int info_imprimirClienteConMasAvisos(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayClientes,int limiteClientes);
#endif /* INFORMES_H_ */
