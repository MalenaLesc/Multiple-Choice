#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JugadoresAnteriores.h"

JAntP crearJugAnt(char a[30], int dni, int p){

    JAntP jug = malloc(sizeof(struct JugAnterior));

    strcpy(jug->alias,a);
    jug->dni = dni;
    jug->puntMax = p;

    return jug;

};


JAntP *inicializarJugAnt(int t){

    JAntP *jug = malloc(t * sizeof(struct JugAnterior));

    FILE *archivo = fopen("PUNTOS.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;
    while (!feof(archivo)) {

        char alias[30];
        int dni;
        int puntMax;

        fscanf(archivo, "%[^,],%d,%d\n",alias, &dni, &puntMax);

        jug[pos]= crearJugAnt(alias,dni,puntMax);

        pos++;

    }

    fclose(archivo);
    return jug;

}

void mostrarJugAnt (JAntP j[], int t){

        printf("\n");
        printf("=============================================================\n");
        printf("==                         RANKING                         ==\n");
        printf("=============================================================\n");
        printf("==                                                         \n");

    for (int i = 0; i < t; i++){

        printf("==     %d : %s, %d, %d                                     \n", i+1, j[i]->alias, j[i]->dni, j[i]->puntMax);

    }
        printf("==                                                         \n");
        printf("=============================================================\n");
}

void ordenarJugAnt(JAntP jA[], int t){

    JAntP  aux;

    for ( int i = 0; i < t; i++){

        for ( int j = 0; j< t-1; j++){

            if ( jA[j]->puntMax <  jA[j+1]->puntMax ){

                aux = jA[j];
                jA[j] = jA[j+1];
                jA[j+1] = aux;


            }
        }
    }

};



