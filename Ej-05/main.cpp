#include <iostream>

#include "CircList.h"

int main() {
  CircList<int> l;

  for(int i = 0; i < 5; i++)
  {
      l.insertarUltimo(i);
  }
  l.insertar(0,5);
  l.insertar(1,2);

  l.reemplazar(0, 2);
  l.reemplazar(1,2);

  std::cout<<l.getDato(4)<<std::endl;

  l.imprimir();

  l.fnInvertir();
  l.imprimir();
  l.fnInvertir();
  l.insertAfterN(2,9, 1);
  l.imprimir();


  return 0;
}
