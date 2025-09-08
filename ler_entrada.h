#ifndef LER_ENTRADA
#define LER_ENTRADA

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

Instancia lerInstancia(const string &nomeArquivo);

#endif