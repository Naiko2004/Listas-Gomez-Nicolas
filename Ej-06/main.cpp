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
  lis.insertAfter2(1,5);
  lis.imprimir();

  return 0;
}
