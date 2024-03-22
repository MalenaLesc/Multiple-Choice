#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Juego.h"
#include "Jugador.h"
#include "Pregunta.h"
#include "JugadoresAnteriores.h"


JuegoP empezarJuego() {

    printf("=============================================\n");
    printf("==                                         ==\n");
    printf("==    BIENVENIDO A JUEGO MULTIPLE CHOICE   ==\n");
    printf("==                                         ==\n");
    printf("=============================================\n\n");

    JuegoP juego = malloc(sizeof(struct Juego));
    juego->jugadores = crearLista(sizeof(Jugadorp));
    juego->jugadores = crearLista(sizeof(JAntP));

    return juego;
}

void cargarJugadorLista(JuegoP juego, int t){

    for (int i = 0; i < t; i++){

            Jugadorp jugador = cargarJugadorTeclado();

            insertarFinal(juego->jugadores,&jugador);
    }
}

void mostrarJuego(JuegoP juego){

    system("cls");
    mostrarLista(juego->jugadores);

}

void mostrarPuntosJuego(JuegoP j){
    mostrarPuntosLista(j->jugadores);
}

void EmpiezaPartida (JuegoP juego){

    printf("=============================================\n");
    printf("==                                         ==\n");
    printf("==            EMPIEZA EL JUEGO!            ==\n");
    printf("==                                         ==\n");
    printf("=============================================\n\n");

    asignarPreguntaAListaDeJugadores(juego->jugadores);

};

void guardarDatos(JuegoP j){

    FILE *archivo  = fopen("PUNTOS.txt","a");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }


    for ( int i = 0; i < obtenerTamanio(j->jugadores); ++i) {

        Jugadorp jugador = *( (Jugadorp*) obtenerDato(j->jugadores, i) );

		fprintf(archivo, "%s,%d,%d\n", jugador->alias, jugador->dni, jugador->puntos->puntMax);

    }

    fclose(archivo);
}


void mostrarRank(JuegoP j){

    int t = cantPreguntas("PUNTOS.txt");
    j->jugAnteriores = inicializarJugAnt(t);
    ordenarJugAnt(j->jugAnteriores,t);
    mostrarJugAnt(j->jugAnteriores, t);

}



void liberarJuego(JuegoP juego) {

    liberarlista(juego->jugadores);

    int t = cantPreguntas("PUNTOS.txt");
    for(int i= 0; i<t; i++){
        free(juego->jugAnteriores[i]);
    }

    free(juego);
};












