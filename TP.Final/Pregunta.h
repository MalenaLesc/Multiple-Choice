#ifndef PREGUNTA_H_INCLUDED
#define PREGUNTA_H_INCLUDED
#include "Respuesta.h"
#include "lista.h"

struct Pregunta{

    int nroPreg;
    char pregunta[100];
    int puntosPregunta;
    RespuestaP *posibles;

};

typedef struct Pregunta* PreguntaP;

PreguntaP inicializarPregunta();
void mostrarLista(Lista lista);
void mostrarPregunta(PreguntaP p);
void mostrarPreguntas(PreguntaP p[],int t);
PreguntaP * agregarPreguntaArchivo(int t);
PreguntaP cargartodo(int nroPreg,char pregunta[100],int puntosPregunta,int t);
int cantPreguntas(char * c);

void liberarPregunta(PreguntaP pregunta);

#endif // PREGUNTA_H_INCLUDED
