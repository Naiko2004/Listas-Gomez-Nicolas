#include <iostream>
#include "../Ej-02/funciones.h"
#include "../Lista/Lista.h"

int main() {
  std::cout << "Ejercicio 02/05\n" << std::endl;

  lista<int> lis;
  int dato, _dato, n;

  // Ingresar lista:

  ingresarLista(lis);
  lis.imprimir();

  // AfterN:
  cout<<"Ingrese el oldValue a contar"<<endl;
  cin>>_dato;
  cout<<"Ingrese el newValue a insertar"<<endl;
  cin>>dato;
  cout<<"Ingrese la cantidad de veces que se debe repetir oldValue antes de insertar"<<endl;
  cin>>n;

  lis.insertAfterN(_dato,dato,n);
  lis.imprimir();

  return 0;
}
