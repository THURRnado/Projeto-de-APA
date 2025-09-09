#ifndef VEICULO
#define VEICULO

#include <vector>
#include "Estacao.h"

struct Veiculo {
    int id;
    int capacidade_max;
    int estoque;
    int posicao;
    int custo_acumulado;
    std::vector<int> rota;
    std::vector<Estacao*> estacoes_alocadas;

    Veiculo(int id_, int Q, int deposito);

    void mover_para(Estacao &e, int custo);
    void entregar(int qtd);
    void coletar(int qtd);
};

#endif