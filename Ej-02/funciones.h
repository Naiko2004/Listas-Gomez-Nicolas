
#ifndef LISTAS_GOMEZ_NICOLAS_FUNCIONES_H
#define LISTAS_GOMEZ_NICOLAS_FUNCIONES_H

#include "../Lista/Lista.h"
#include "iostream"
using namespace std;

template <class T>
void ingresarLista(lista<T> &l);

template <class T>
void ingresarElemento(lista<T> &l, int opcion);

void menu(int &opcion);




template <class T>
void ingresarLista(lista<T> &l)
{
    int contador = 0;
    T dato;
    char opcion;

    while(true)
    {
        cout<<"Ingrese el elemento "<<contador<<" de la lista"<<endl;
        cin>>dato;
        l.insertarUltimo(dato);

        contador++;
        cout<<"Desea seguir ingresando datos? [y/n]"<<endl;
        cin>>opcion;

        if(opcion == 'n')
        {
            break;
        }
    }
}

void menu(int &opcion)
{
    cout<<"Eliga donde desea insertar un elemento:"<<endl;
    cout<<"1) En el principio"<<endl;
    cout<<"2) En el medio"<<endl;
    cout<<"3) En el final"<<endl;
    cin>>opcion;
}

template <class T>
void ingresarElemento(lista<T> &l, int opcion){

    T dato;
    cout<<"Ingrese el dato a insertar"<<endl;
    cin>>dato;

    switch (opcion) {
        case 1:
            l.insertarPrimero(dato);
            break;
        case 2:
            int n;
            cout<<"Ingrese la posicion en la que insertar el dato"<<endl;
            cin>>n;
            l.insertar(n,dato);
            break;
        case 3:
            l.insertarUltimo(dato);
            break;
        default:
            throw runtime_error("404");
    }


}

#endif //LISTAS_GOMEZ_NICOLAS_FUNCIONES_H
