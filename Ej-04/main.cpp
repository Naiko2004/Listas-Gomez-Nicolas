#include <iostream>

#include "../Lista/Lista.h"
#include "union.h"

int main() {
  std::cout << "Ejercicio 01/04\n" << std::endl;

  lista<int> *primeraLista = new lista<int>;
  lista<int> *segundaLista = new lista<int>;

    for (int i = 0; i < 5; ++i) {
        primeraLista->insertarUltimo(i);
        segundaLista->insertarPrimero(i);
    }

    lista<int> *unionLista = unir(primeraLista, segundaLista);
    primeraLista->imprimir();
    segundaLista->imprimir();
    unionLista->imprimir();


  return 0;
}
