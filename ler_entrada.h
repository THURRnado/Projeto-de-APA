#ifndef LER_ENTRADA
#define LER_ENTRADA

#include <vector>
#include <string>
using namespace std;

// Estrutura de dados para armazenar a instância
struct Instancia {
    int n; // número de estações
    int m; // número de veículos
    int Q; // capacidade
    vector<int> demandas;
    vector<vector<int>> custos;
};

// Apenas a declaração da função (não a implementação)
Instancia lerInstancia(const string &nomeArquivo);

#endif
