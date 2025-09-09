#include "Veiculo.h"

Veiculo::Veiculo(int id_, int Q, int deposito) {
    id = id_;
    capacidade_max = Q;
    estoque = 0;
    posicao = deposito;
    custo_acumulado = 0;
    rota.push_back(deposito);
}

void Veiculo::mover_para(Estacao &e, int custo) {
    posicao = e.id;
    custo_acumulado += custo;
    rota.push_back(e.id);
}

void Veiculo::entregar(int qtd) {
    estoque -= qtd;
}

void Veiculo::coletar(int qtd) {
    estoque += qtd;
}