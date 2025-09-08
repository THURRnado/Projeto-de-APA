#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Instancia {
    int n;
    int m;
    int Q;
    vector<int> demandas;
    vector<vector<int>> custos;
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
    getline(in, linha); // descartar resto da linha 3
    getline(in, linha); // descartar linha em branco (linha 4)

    // leitura das demandas (n valores)
    inst.demandas.resize(inst.n);
    for (int i = 0; i < inst.n; i++) {
        in >> inst.demandas[i];
    }

    getline(in, linha); // descartar resto da linha das demandas
    getline(in, linha); // descartar linha em branco (linha 6)

    // leitura da matriz de custos (n+1 x n+1)
    inst.custos.assign(inst.n + 1, vector<int>(inst.n + 1, 0));
    for (int i = 0; i <= inst.n; i++) {
        for (int j = 0; j <= inst.n; j++) {
            in >> inst.custos[i][j];
        }
    }

    in.close();
    return inst;
}