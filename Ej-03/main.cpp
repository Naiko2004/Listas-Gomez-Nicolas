#include <iostream>

#include "../Lista/Lista.h"

using namespace std;

int main() {
  std::cout << "Ejercicio 01/03\n" << std::endl;

  lista<int> l;
  int n;

  for(int i = 0; i < 5; i++)
  {
      l.insertarUltimo(i);
  }

  l.imprimir();
  cout<<"Ingrese la posicion que quiere eliminar"<<endl;
  cin>>n;
  l.eliminar(n);
  l.imprimir();


  return 0;
}
