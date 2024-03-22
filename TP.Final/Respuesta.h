#ifndef RESPUESTA_H_INCLUDED
#define RESPUESTA_H_INCLUDED

struct Respuesta{

    int numResp;
    char resp[100];
    int nroPregAsociada;
    int correcta; // 0 o 1, boolean

};

typedef struct Respuesta* RespuestaP;

RespuestaP *inicializarResp(int t);
void mostrarResp(RespuestaP r[],int t);
int cantResp(int cod);
RespuestaP crearResp(int numResp, char resp[100],int nroPregAsociada,int correcta);


void liberarRespuesta(RespuestaP respuesta);

#endif // RESPUESTA_H_INCLUDED
