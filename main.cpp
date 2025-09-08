#include <iostream>
#include "guloso.h"
#include "ler_entrada.h"

int main() {
    Instancia inst = lerInstancia("instanciaTeste.txt");

    std::cout << "Numero de estacoes: " << inst.n << std::endl;
    std::cout << "Numero de veiculos: " << inst.m << std::endl;
    std::cout << "Capacidade dos veiculos: " << inst.Q << std::endl;

    std::cout << "Demandas: ";
    for (std::size_t i = 0; i < inst.demandas.size(); i++) {
        std::cout << inst.demandas[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Matriz de custos: " << std::endl;
    for (std::size_t i = 0; i < inst.custos.size(); i++) {
        for (std::size_t j = 0; j < inst.custos[i].size(); j++) {
            std::cout << inst.custos[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}