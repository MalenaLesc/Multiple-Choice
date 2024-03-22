#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "lista.h"
#include "Jugador.h"
#include "Puntos.h"
#include "JugadoresAnteriores.h"

struct Juego{

   Lista jugadores;
   JAntP *jugAnteriores;
};

typedef struct Juego* JuegoP;


JuegoP empezarJuego();
void cargarJugadorLista(JuegoP juego, int t);
void mostrarJuego(JuegoP juego);
void mostrarPuntosJuego(JuegoP j);
void guardarDatos(JuegoP j);
void EmpiezaPartida (JuegoP juego);
void mostrarRank(JuegoP j);

void liberarJuego(JuegoP juego);

#endif // JUEGO_H_INCLUDED
