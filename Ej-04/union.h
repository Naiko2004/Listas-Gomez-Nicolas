#include "../Lista/Lista.h"

#ifndef U02_LISTAS_EJ_04_UNION_H_
#define U02_LISTAS_EJ_04_UNION_H_

template <class T>
lista<T> *unir(lista<T> *lisA, lista<T> *lisB) {

    lista<T> *nueva = new lista<T>();

    nodo<T> *aux = lisA->getInicio();

    while(aux != nullptr)
    {
        nueva->insertarUltimo(aux->getDato());
        aux = aux->getSig();
    }

    aux = lisB->getInicio();

    while(aux != nullptr)
    {
        nueva->insertarUltimo(aux->getDato());
        aux = aux->getSig();
    }


  return nueva;
}

#endif // U02_LISTAS_EJ_04_UNION_H_
