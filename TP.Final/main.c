#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "Jugador.h"
#include "Juego.h"
#include "Pregunta.h"

void menu(JuegoP j);

int main()
{

    JuegoP j = empezarJuego();
    menu(j);

    liberarJuego(j);

    return 0;
}

void menu(JuegoP j) {

    int opcion = 0;
    int t = 0;

    do {
        printf("\n");
        printf("=============================================================\n");
        printf("==                          MENU                           ==\n");
        printf("=============================================================\n");
        printf("==                                                         ==\n");
        printf("==    1. Ingresar jugadores                                ==\n");
        printf("==    2. Mostrar jugadores                                 ==\n");
        printf("==    3. Iniciar juego (debe ingresar los jugadores antes) ==\n");
        printf("==    4. Ver puntuacion actual                             ==\n");
        printf("==    5. Ver ranking                                       ==\n");
        printf("==    6. Salir                                             ==\n");
        printf("==                                                         ==\n");
        printf("=============================================================\n");
        printf("\nElija una opcion del menu para comenzar --->  ");

        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 6);

    switch (opcion) {
        case 1:
            system("cls");
            t = cantJugadores();
            cargarJugadorLista(j, t);
            printf("\nJugadores cargados correctamente. En 5 segundos volvera al menu :)");
            sleep(5);
            system("cls");
            menu(j);
            break;

        case 2:
            mostrarJuego(j);
            printf("\n");
            system("pause");
            system("cls");
            menu(j);
            break;

        case 3:
            system("cls");
            EmpiezaPartida(j);
            guardarDatos(j);
            printf("\n");
            system("pause");
            system("cls");
            menu(j);
            break;

        case 4:
            system("cls");
            mostrarPuntosJuego(j);
            printf("\n");
            system("pause");
            system("cls");
            menu(j);
            break;

        case 5:
            system("cls");
            mostrarRank(j);
            printf("\n");
            system("pause");
            system("cls");
            menu(j);
            break;


        case 6:
            printf("\nGracias por jugar! Hasta pronto! :D\n");
            liberarJuego(j);
            exit(0);
    }
}


