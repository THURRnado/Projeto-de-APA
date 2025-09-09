#include "guloso.h"
#include <iostream>

std::vector<Veiculo> algoritmoGuloso(const Instancia &inst) {

    // Criar veículos
    std::vector<Veiculo> veiculos;
    for (int i = 0; i < inst.m; i++) {
        veiculos.push_back(Veiculo(i, inst.Q, 0)); // depósito = 0
    }

    std::cout << "Veiculos instanciados!"<<std::endl;

    // Criar estações
    std::vector<Estacao> estacoes;
    for (int i = 0; i < inst.n; i++) {
        estacoes.push_back(Estacao(i, inst.demandas[i]));
    }

    std::cout << "Estacoes instanciadas!"<<std::endl;

    // Distribuir estações por veículo (blocos)
    int max_por_veiculo = inst.n / inst.m;
    int resto = inst.n % inst.m;
    int indice = 0;

    for (int i = 0; i < inst.m; i++) {
        int tamanho_bloco = max_por_veiculo;
        if (resto > 0) {
            tamanho_bloco += 1;
            resto--;
        }
        for (int j = 0; j < tamanho_bloco; j++) {
            veiculos[i].estacoes_alocadas.push_back(&estacoes[indice]);
            indice++;
        }
    }

    std::cout << "Blocos de veiculos criados!\n"<<std::endl;

    // === Esqueleto guloso ===
    for (auto &v : veiculos) {
        while (true) {
            std::vector<Estacao*> candidatos;
            for (auto e : v.estacoes_alocadas) {
                if (!e->visitada)
                    candidatos.push_back(e);
            }
            if (candidatos.empty()) break;

            Estacao *proxima = candidatos[0]; // critério guloso simples

            // Atualizar estoque e demanda
            int qtd = std::min(v.estoque, proxima->demanda > 0 ? proxima->demanda : 0);
            if (proxima->demanda > 0) {
                v.entregar(qtd);
                proxima->demanda -= qtd;
            } else {
                qtd = std::min(v.capacidade_max - v.estoque, -proxima->demanda);
                v.coletar(qtd);
                proxima->demanda += qtd;
            }

            if (proxima->demanda == 0)
                proxima->visitada = true;

            // Mover veículo
            int custo = inst.custos[v.posicao][proxima->id];
            v.mover_para(*proxima, custo);
        }

        // Voltar ao depósito
        v.mover_para(estacoes[0], inst.custos[v.posicao][0]);
    }

    return veiculos;
}