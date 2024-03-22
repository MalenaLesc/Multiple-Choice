#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "lista.h"
#include "Jugador.h"
#include "Pregunta.h"
#include "Respuesta.h"

int cantJugadores(){

    int jugadores = 0;
    printf("\n");

    do{
    printf("Ingrese la cantidad de jugadores (Entre 2 y 4) ---> ");
    scanf("%d",&jugadores);
    }while(jugadores >4 || jugadores <2);

    return jugadores;

};


int verificarDNIExistente(const char *archivo, int dni) {

    FILE *archivoJugadores = fopen(archivo, "r");
    if (archivoJugadores == NULL) {
        perror("Error al abrir el archivo de jugadores");
        return 0;
    }

    int dniExistente = 0;
    int dniLeido;

    while (fscanf(archivoJugadores, "%d", &dniLeido) == 1) {
        if (dniLeido == dni) {
            dniExistente = 1;
            break;
        }
    }

    fclose(archivoJugadores);

    return dniExistente;
}




Jugadorp cargarJugadorTeclado() {
    Jugadorp j = malloc(sizeof(struct Jugador));


        printf("\nINGRESE EL JUGADOR --->\n");

        printf("\nCARGAR ALIAS\n");
        fflush(stdin);
        gets(j->alias);

        printf("\nCARGAR DNI\n");
        scanf("%d", &j->dni);

        j->puntos= inicializarPuntos();

        int tp = cantPreguntas("PREGUNTAS.txt");
        j->preguntasJuego = agregarPreguntaArchivo(tp);


    return j;
}


void mostrarJugador(Jugadorp j){

        printf("====================\n");
        printf("       JUGADOR      \n");
        printf("--------------------\n");
        printf("\n     ALIAS: %s  \n", j->alias);
        printf("\n     DNI: %d    \n", j->dni);
        printf("====================\n");

};

void mostrarLista(Lista lista){

    for ( int i = 0 ; i<obtenerTamanio(lista); i++){

        Jugadorp j = *( (Jugadorp*) obtenerDato(lista, i) );

        mostrarJugador(j);

    }


};

void mostrarPuntosLista(Lista lista){

    for ( int i = 0 ; i<obtenerTamanio(lista); i++){

        Jugadorp j = *( (Jugadorp*) obtenerDato(lista, i) );

        mostrarPuntos(j->puntos,j->alias);

    }


};


int generarAleatorio(int min,int max){
    int num = (rand() % (max - min +1)) + min;

    return num;
};

void seleccionarGanadorLista(Lista lista) {

    Jugadorp ganador = NULL;
    int puntMaxGanador = 0;

    for (int i = 0; i < obtenerTamanio(lista); i++) {
        Jugadorp jug = *((Jugadorp*)obtenerDato(lista, i));

        mostrarPuntos(jug->puntos,jug->alias);

        if (ganador == NULL || jug->puntos->puntMax > puntMaxGanador) {

            ganador = jug;
            puntMaxGanador = jug->puntos->puntMax;

        }
    }

    int empate = 0;
    Lista jugadoresEmpate = crearLista(sizeof(Jugadorp));

    for (int i = 0; i < obtenerTamanio(lista); i++) {
        Jugadorp jug = *((Jugadorp*)obtenerDato(lista, i));

        if (jug->puntos->puntMax == puntMaxGanador) {
            insertarFinal(jugadoresEmpate, &jug);
        }
    }

    if (obtenerTamanio(jugadoresEmpate) > 1) {
        empate = 1;
    }

    if (empate) {

         int ganadorIndice = responderPreguntaDesempate(jugadoresEmpate);
         Jugadorp jugGanadorEmpate = *((Jugadorp*)obtenerDato(jugadoresEmpate, ganadorIndice));
         mostrarGanador(jugGanadorEmpate->alias);

    } else {

        mostrarGanador(ganador->alias);
    }

}



int responderPreguntaDesempate(Lista lista) {

    int n1 = generarAleatorio(5, 1235);
    int n2 = generarAleatorio(1, 500);
    int n3 = generarAleatorio(100, 500);

    printf("\nLos jugadores empataron :O !\n");
    printf("\nSe procedera a hacer una pregunta matematica para desempatar,\n");
    printf("el jugador que introduzca el numero mas cercano a la respuesta correcta sera el ganador!\n");

    printf("\n============== PREGUNTA DESEMPATE ===============\n");
    printf("\n     Cuál es el resultado de: %d x %d + %d     \n", n1, n2, n3);

    int respuestas[obtenerTamanio(lista)];

    for (int i = 0; i < obtenerTamanio(lista); i++) {

        Jugadorp jug = *((Jugadorp*)obtenerDato(lista, i));


        printf("\nJugador %s, ingrese su respuesta para el desempate --->  ", jug->alias);
        scanf("%d", &respuestas[i]);
    }

    int respuestaCorrecta = n1 * n2 + n3;
    int diferenciaMinima = abs(respuestas[0] - respuestaCorrecta);
    int ganadorIndice = 0;

    for (int i = 1; i < obtenerTamanio(lista); i++) {
        int diferencia = abs(respuestas[i] - respuestaCorrecta);
        if (diferencia < diferenciaMinima) {
            diferenciaMinima = diferencia;
            ganadorIndice = i;

        }
    }



    return ganadorIndice;
}


void mostrarGanador(char *alias) {

        printf("\n========= FELICIDADES! ===========\n");
        printf("\n        EL GANADOR ES: %s\n", alias);
        printf("\n==================================\n");

}


void asignarPreguntaAListaDeJugadores(Lista lista) {

    srand((unsigned)time(0));
    int tp = cantPreguntas("PREGUNTAS.txt");
    int tamLista = obtenerTamanio(lista);

    int preguntasUsadas[tp];

    for (int usadas = 0; usadas < tp; usadas++) {

        preguntasUsadas[usadas] = -1;
    }

    for (int jugadorActual = 0; jugadorActual < tamLista; jugadorActual++) {

        Jugadorp j = *((Jugadorp*)obtenerDato(lista, jugadorActual));
        int p = 0;
        int numPregunta = 0;
        int fallo = 0;

        while (p < tp && fallo == 0) {
            int preguntaActual;
            do {
                preguntaActual = rand() % tp;
            } while (preguntasUsadas[preguntaActual] != -1);

            preguntasUsadas[preguntaActual] = jugadorActual;


            printf("\nPREGUNTA %d PARA JUGADOR %d: %s\n", numPregunta + 1, jugadorActual + 1, j->alias);
            mostrarPregunta(j->preguntasJuego[preguntaActual]);

            int resp;
            printf("\nINGRESE EL NUMERO DE LA RESPUESTA CORRECTA ---> ");
            scanf("%d", &resp);

            if (resp >= 1 && resp <= 4) {
                // Verifica si la respuesta es correcta
                if (j->preguntasJuego[preguntaActual]->posibles[resp - 1]->correcta == 1) {

                    printf("\nRespuesta correcta! Suma puntos y continua el juego\n");
                    j->puntos->actuales = j->puntos->actuales + j->preguntasJuego[preguntaActual]->puntosPregunta;
                    printf("\n==========================\n");
                    printf("\n    Puntos Actuales: %d\n",j->puntos->actuales);
                    printf("\n==========================\n");

                    j->puntos->puntMax = j->puntos->actuales;
                    j->puntos->codPuntuacion = j->dni;
                    printf("\n");
                    system("pause");
                    system("cls");

                    numPregunta++;
                    p++;

                } else {
                    printf("\nRespuesta incorrecta :( El jugador pierde su turno \n");
                    j->puntos->codPuntuacion = j->dni;
                    printf("\n==========================\n");
                    printf("\n    Puntos Actuales: %d\n",j->puntos->actuales);
                    printf("\n==========================\n");
                    printf("\n");
                    system("pause");
                    system("cls");

                    numPregunta = 0;
                    fallo = 1;
                }
            } else {
                printf("\nOpción de respuesta no válida. El jugador pierde su turno \n");
                j->puntos->codPuntuacion = j->dni;
                printf("\n==========================\n");
                printf("\n    Puntos Actuales: %d\n",j->puntos->actuales);
                printf("\n==========================\n");
                printf("\n");
                system("pause");
                system("cls");

                numPregunta = 0;
                fallo = 1;
            }
        }
    }

    seleccionarGanadorLista(lista);
}


void liberarJugador(Jugadorp jugador) {

    int t = cantPreguntas("PREGUNTAS.txt");

    for (int i = 0; i < t; i++) {
        liberarPregunta(jugador->preguntasJuego[i]);
    }

    liberarPuntos(jugador->puntos);

    free(jugador);
};


