#include <iostream>

#include "../Lista/Lista.h"

int main() {
  std::cout << "Ejercicio 01/05\n" << std::endl;

  lista<int> lis;

  for (int i = 0; i < 5; ++i) {
      lis.insertarUltimo(i);
  }

  lis.insertarUltimo(1);
  lis.insertarUltimo(7);
  lis.imprimir();
  lis.insertAfterN(3,5,1);
  lis.imprimir();

  return 0;
}
