#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Instancia {
    int n; //Numero de estações/vertices
    int m; //Numero de veiculos
    int Q; //Capacidade dos veiculos
    vector<int> demandas; //Demanda de bicicletas de cada estação
    vector<vector<int>> custos; //Custos de viagem
};

Instancia lerInstancia(const string &nomeArquivo) {
    ifstream in(nomeArquivo);
    if (!in.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        exit(1);
    }

    Instancia inst;

    in >> inst.n;
    in >> inst.m;
    in >> inst.Q;

    string linha;
    getline(in, linha);
    getline(in, linha);

    inst.demandas.resize(inst.n);
    for (int i = 0; i < inst.n; i++) {
        in >> inst.demandas[i];
    }

    getline(in, linha);
    getline(in, linha);

    inst.custos.assign(inst.n + 1, vector<int>(inst.n + 1, 0));
    for (int i = 0; i <= inst.n; i++) {
        for (int j = 0; j <= inst.n; j++) {
            in >> inst.custos[i][j];
        }
    }

    in.close();
    return inst;
}