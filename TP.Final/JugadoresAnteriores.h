#ifndef JUGADORESANTERIORES_H_INCLUDED
#define JUGADORESANTERIORES_H_INCLUDED
#include "lista.h"

struct JugAnterior{

   char alias[30];
   int dni;
   int puntMax;
};

typedef struct JugAnterior* JAntP;


JAntP *inicializarJugAnt(int t);
JAntP crearJugAnt(char a[30], int dni, int p);
void mostrarJugAnt(JAntP j[], int t);
void ordenarJugAnt(JAntP jA[], int t);


#endif // JUGADORESANTERIORES_H_INCLUDED
