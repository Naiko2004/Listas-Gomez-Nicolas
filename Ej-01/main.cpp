#include <iostream>

#include "../Lista/Lista.h"
#include "fnInvierte.h"

int main() {
  std::cout << "Ejercicio 02/01\n" << std::endl;
  lista<int> lis;

  for(int i = 0; i < 5; i++)
  {
      lis.insertarUltimo(i);
  }

  lis.imprimir();

  lis.fnInvertir();
  lis.imprimir();

  return 0;
}
