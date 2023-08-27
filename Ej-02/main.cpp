#include <iostream>
#include "funciones.h"
#include "../Lista/Lista.h"
using namespace std;

int main() {
  std::cout << "Ejercicio 02/02\n" << std::endl;

  lista<float> l;
  int opcion;

  // Ingresar lista:

  ingresarLista(l);
  l.imprimir();

  // Menu:

  menu(opcion);

  // Ingresar elemento

  ingresarElemento(l, opcion);
  l.imprimir();

  return 0;
}
