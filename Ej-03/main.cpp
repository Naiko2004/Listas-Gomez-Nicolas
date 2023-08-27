#include <iostream>

#include "../Lista/Lista.h"
#include "../Ej-02/funciones.h"
using namespace std;

int main() {
  std::cout << "Ejercicio 02/03\n" << std::endl;

  lista<int> l;
  int n;

  // Ingresar lista

  ingresarLista(l);
  l.imprimir();

  // Eliminar elemento

  cout<<"Ingrese la posicion que quiere eliminar"<<endl;
  cin>>n;
  l.eliminar(n);
  l.imprimir();

  return 0;
}
