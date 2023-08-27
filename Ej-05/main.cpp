#include <iostream>
#include "funciones.h"
#include "CircList.h"

int main() {
    std::cout << "Ejercicio 02/05\n" << std::endl;
    CircList<int> l;
    int dato, n, _dato;

    // Ingresar lista:

    ingresarLista(l);
    cout<<endl<<"Tamanio: "<<l.getTamanio()<<endl;
    l.imprimir();

    // Ingresar elementos:
    cout<<"Ingrese un dato para insertar"<<endl;
    cin>>dato;

    l.insertarPrimero(dato);
    l.insertarUltimo(dato);
    l.imprimir();

    cout<<endl<<"Ingrese una posicion para insertar nuevamente ese dato"<<endl;
    cin>>n;

    l.insertar(n,dato);
    l.imprimir();

    // Reemplazar elementos:

    cout<<"Ingrese un dato para reemplazar"<<endl;
    cin>>dato;
    cout<<"Ingrese la posicion donde reemplazar"<<endl;
    cin>>n;

    l.reemplazar(n, dato);
    l.imprimir();

    // Invertir lista:

    cout<<"Lista invertida"<<endl;
    l.fnInvertir();
    l.imprimir();
    l.fnInvertir();

    // Insertar AfterN:

    cout<<"Ingrese el newValue que desea insertar"<<endl;
    cin>>dato;
    cout<<"Ingrese el oldValue que desea contar"<<endl;
    cin>>_dato;
    cout<<"Ingrese cuantas veces se debe repetir oldValue antes de insertar newValue"<<endl;
    cin>>n;

    l.insertAfterN(_dato, dato, n);
    l.imprimir();

    // Eliminar:
    cout<<"Ingrese la posicion que desea eliminar"<<endl;
    cin>>n;

    l.eliminar(n);
    l.imprimir();

  return 0;
}
