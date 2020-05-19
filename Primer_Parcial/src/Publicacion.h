#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define TEXTO_LEN 64

#define ESTADO_PAUSADO	0
#define ESTADO_ACTIVO	1


typedef struct
{
	char texto[TEXTO_LEN];
	int isEmpty;
	int idPub;
	int idCliente;
	int rubro;
	int estado;
}Publicacion;

int pub_imprimir(Publicacion* auxAviso);
int pub_inicializarArray(Publicacion* array,int limite);
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPub, int idCliente);
int pub_getEmptyIndex(Publicacion* array,int limite);
int pub_imprimirArray(Publicacion* array,int limite);
int pub_buscarId(Publicacion array[], int limite, int valorBuscado);
int pub_activarArray(Publicacion* array,int limite, int indice);
int pub_bajaArray(Publicacion* array,int limite, int indice);
int pub_ordenarPorNombre(Publicacion* array,int limite);
int pub_pausarArray(Publicacion* array,int limite, int indice);
int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto,char* estado,int rubro);
int pub_obtenerCantidadActivosPorRubro(Publicacion* arrayPublicaciones, int limite, int rubro);
int pub_obtenerCantidadPorRubro(Publicacion* arrayPublicaciones, int limite, int rubro);
#endif /* PUBLICACION_H_ */
