#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Instancia.h"


Instancia lerInstancia(const std::string &nomeArquivo) {
    std::ifstream in(nomeArquivo);
    if (!in.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        exit(1);
    }

    Instancia inst;

    in >> inst.n;
    in >> inst.m;
    in >> inst.Q;

    std::string linha;
    std::getline(in, linha); // consome resto da linha
    std::getline(in, linha); // pula linha em branco, se houver

    inst.demandas.resize(inst.n);
    for (int i = 0; i < inst.n; i++) {
        in >> inst.demandas[i];
    }

    std::getline(in, linha);
    std::getline(in, linha);

    inst.custos.assign(inst.n + 1, std::vector<int>(inst.n + 1, 0));
    for (std::size_t i = 0; i < inst.custos.size(); i++) {
        for (std::size_t j = 0; j < inst.custos[i].size(); j++) {
            in >> inst.custos[i][j];
        }
    }

    in.close();
    return inst;
}