#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pregunta.h"
#include "Respuesta.h"



PreguntaP inicializarPregunta(){

    PreguntaP p = malloc(sizeof(struct Pregunta));

    p->nroPreg= 0;
    p->puntosPregunta= 0;
    strcpy(p->pregunta, "VACIO");

    return p;

};

void mostrarPregunta(PreguntaP p){

        printf("\n=============================\n");

        printf("\n\tPREGUNTA %d : %s\n",p->nroPreg,p->pregunta);
        printf("\n\tPUNTOS : %d\n",p->puntosPregunta);

        printf("\n====================\n\n");
        printf(" RESPUESTAS POSIBLES\n\n");

        int t = cantResp(p->nroPreg);
        mostrarResp(p->posibles,t);

        printf("\n=============================\n");

};

void mostrarPreguntas(PreguntaP p[],int t){

    for (int i = 0; i < t; i++){
        mostrarPregunta(p[i]);
    }

}

int cantPreguntas(char *c) {

    FILE *archivo;
    archivo = fopen(c, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;
    char renglon[300];

    while (fgets(renglon, sizeof(renglon), archivo) != NULL) {
        if (strlen(renglon) > 1) {
            pos++;
        }
    }

    fclose(archivo);
    return pos;
}

PreguntaP * agregarPreguntaArchivo(int t) {

    PreguntaP *p = malloc(t*sizeof(struct Pregunta));

    FILE *archivo;
    archivo = fopen("PREGUNTAS.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;
    while (!feof(archivo)) {

        int nroPreg;
        char pregunta[100];
        int puntosPregunta;

            fscanf(archivo, "%d, %[^,], %d\n",&(nroPreg),pregunta,&(puntosPregunta));

            int tr = cantResp(nroPreg);

            p[pos]= cargartodo(nroPreg,pregunta,puntosPregunta,tr);

            pos++;

    }

    fclose(archivo);
    return p;
}

void cargarRespuestaArchivo (PreguntaP p){

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

        fscanf(archivo, "%d,%[^,],%d,%d\n",&numResp, resp,&nroPregAsociada,&correcta);

                    if (nroPregAsociada == p->nroPreg){
                            RespuestaP r = crearResp(numResp, resp,nroPregAsociada,correcta);

                            p->posibles[pos] = r;
                            pos++;
                    }
    }

     fclose(archivo);


};

PreguntaP cargartodo(int nroPreg,char pregunta[100],int puntosPregunta,int t){

    PreguntaP p = malloc(sizeof(struct Pregunta));

    p->nroPreg= nroPreg;
    p->puntosPregunta= puntosPregunta;
    strcpy(p->pregunta, pregunta);
    p->posibles = malloc((t* sizeof(struct Respuesta)));

    cargarRespuestaArchivo(p);

    return p;

}

void liberarPregunta(PreguntaP pregunta) {

    int t = cantResp(pregunta->nroPreg);

    for (int i = 0; i < t; i++) {
        liberarRespuesta(pregunta->posibles[i]);
    }

    free(pregunta);
}

