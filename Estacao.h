#ifndef ESTACAO
#define ESTACAO

struct Estacao {
    int id;        // índice da estação na matriz de custos
    int demanda;   // demanda de bicicletas (+ entrega / - coleta)
    bool visitada; // true se já foi atendida

    Estacao(int id_, int demanda_);
};

#endif