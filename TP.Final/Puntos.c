#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Puntos.h"

PuntosP inicializarPuntos(){

    PuntosP puntos = malloc(sizeof(struct Puntos));

    puntos->actuales= 0;
    puntos->codPuntuacion= 0;
    puntos->puntMax= 0;


    return puntos;

};

void mostrarPuntos(PuntosP pun, char *alias) {
    printf("======================================\n");
    printf("      PUNTUACION DEL JUGADOR %s      \n",alias);
    printf("------------------------------------\n");
    printf("   Puntos Actuales: %d\n", pun->actuales);
    printf("   Puntaje Maximo: %d\n", pun->puntMax);
    printf("   DNI del Jugador: %d\n", pun->codPuntuacion);
    printf("======================================\n");
};

void liberarPuntos(PuntosP puntos) {
    free(puntos);
};
