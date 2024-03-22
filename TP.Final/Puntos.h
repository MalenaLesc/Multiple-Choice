#ifndef PUNTOS_H_INCLUDED
#define PUNTOS_H_INCLUDED

struct Puntos{
    int codPuntuacion;
    int actuales;
    int puntMax;
};


typedef struct Puntos* PuntosP;

PuntosP inicializarPuntos();
void mostrarPuntos(PuntosP pun, char *alias);


void liberarPuntos(PuntosP puntos);

#endif // PUNTOS_H_INCLUDED
