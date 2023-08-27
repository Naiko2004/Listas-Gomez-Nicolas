#include <iostream>

#include "../Lista/Lista.h"
#include "union.h"
#include "../Ej-02/funciones.h"

int main() {
  std::cout << "Ejercicio 02/04\n" << std::endl;

  lista<int> *primeraLista = new lista<int>;
  lista<int> *segundaLista = new lista<int>;

  // Ingresar primera lista
  cout<<"Primera lista:"<<endl;
  ingresarLista(*primeraLista);
  primeraLista->imprimir();

  // Ingresar segunda lista
  cout<<"Segunda lista:"<<endl;
  ingresarLista(*segundaLista);
  segundaLista->imprimir();


  // Union
  cout<<endl<<"Union: "<<endl;
  lista<int> *unionLista = unir(primeraLista, segundaLista);
  unionLista->imprimir();


  return 0;
}
