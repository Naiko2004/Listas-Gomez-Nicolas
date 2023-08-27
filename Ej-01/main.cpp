#include <iostream>

#include "../Lista/Lista.h"
#include "../Ej-02/funciones.h"
#include "fnInvierte.h"

int main() {
  std::cout << "Ejercicio 02/01\n" << std::endl;
  lista<int> lis;

  // Ingresar lista:

  ingresarLista(lis);
  lis.imprimir();

  // Invertir lista:

  lis.fnInvertir();
  lis.imprimir();

  return 0;
}
