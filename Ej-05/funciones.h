

#ifndef LISTAS_GOMEZ_NICOLAS_FUNCIONES_H
#define LISTAS_GOMEZ_NICOLAS_FUNCIONES_H

#include "CircList.h"
#include "iostream"
using namespace std;

template <class T>
void ingresarLista(CircList<T> &l)
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



#endif //LISTAS_GOMEZ_NICOLAS_FUNCIONES_H
