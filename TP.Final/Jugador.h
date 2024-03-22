#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "lista.h"
#include "Pregunta.h"
#include "Puntos.h"


struct Jugador{

    char alias[30];
    int dni;
    PreguntaP * preguntasJuego;
    PuntosP puntos;
};

typedef struct Jugador* Jugadorp;


Jugadorp cargarJugadorTeclado();

int cantJugadores();

void mostrarJugador(Jugadorp j);

void mostrarLista(Lista lista);

void agregarPreguntaALista(PreguntaP pregunta, Jugadorp jugador);

void mostrarPuntosLista(Lista lista);

void mostrarGanador(char *alias);

void asignarPreguntaAListaDeJugadores(Lista lista);

int responderPreguntaDesempate();

void seleccionarGanadorLista(Lista lista);


void liberarJugador(Jugadorp jugador);


#endif // JUGADOR_H_INCLUDED
