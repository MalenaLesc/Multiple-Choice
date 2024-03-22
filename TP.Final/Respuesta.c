#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Respuesta.h"



RespuestaP *inicializarResp(int t){

    RespuestaP *r = malloc(t * sizeof(struct Respuesta));

    for (int i = 0; i < t; i++) {

        r[i] = malloc(sizeof(struct Respuesta));

        r[i]->numResp = 0;
        r[i]->nroPregAsociada = 0;
        r[i]->correcta = 0;
        strcpy(r[i]->resp, "VACIO");
    }

    return r;

};

void mostrarResp(RespuestaP r[], int t) {
    for (int i = 0; i < t; i++) {
        printf("\t%d: %s\n", r[i]->numResp, r[i]->resp);
    }
}

int cantResp(int cod){

    FILE *archivo;
    archivo = fopen("RESPUESTAS.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;

    while (!feof(archivo)){

        int numResp;
        char resp[30];
        int nroPregAsociada;
        int correcta;

        fscanf(archivo, "%d,%[^,],%d,%d\n",
                    &numResp, resp,&nroPregAsociada, &correcta);

                    if (cod == nroPregAsociada){
                        pos++;
                    }
    }

     fclose(archivo);

     return pos;

}

RespuestaP crearResp(int numResp, char resp[100],int nroPregAsociada,int correcta){

    RespuestaP r = malloc( sizeof(struct Respuesta));


        r->numResp = numResp;
        r->nroPregAsociada = nroPregAsociada;
        r->correcta = correcta;
        strcpy(r->resp, resp);

        return r;

}

void liberarRespuesta(RespuestaP respuesta) {
    free(respuesta);
};
