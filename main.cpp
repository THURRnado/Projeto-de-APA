#include <iostream>
#include "guloso.h"
#include "ler_entrada.h"

int main() {
    Instancia inst = lerInstancia("instanciaTeste.txt");
    cout << "Capacidade: " << inst.Q << endl;
    return 0;
}