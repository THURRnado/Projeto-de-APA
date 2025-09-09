#ifndef LER_ENTRADA
#define LER_ENTRADA

#include <vector>
#include <string>
using namespace std;

struct Instancia {
    int n; // Número de estações/vertices
    int m; // Número de veículos
    int Q; // Capacidade dos veículos
    std::vector<int> demandas; // Demanda de bicicletas de cada estação
    std::vector<std::vector<int>> custos; // Custos de viagem
};

Instancia lerInstancia(const string &nomeArquivo);

#endif