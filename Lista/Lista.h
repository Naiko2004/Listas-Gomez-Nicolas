//
// Created by nico on 15/08/23.
//

#ifndef LISTAS_LISTA_H
#define LISTAS_LISTA_H

#include <iostream>
#include "nodo.h"

template <class T>
class lista {
private:
    nodo<T> *inicio;
public:
    lista();
    ~lista();
    lista( lista<T> &li);

    void setInicio(nodo<T> *_inicio);
    nodo<T> *getInicio();

    bool esVacia();
    int getTamanio();

    void insertar(int pos, T dato);
    void insertarPrimero(T dato);
    void insertarUltimo(T dato);
    void insertAfter2(T oldValue, T newValue);
    void insertAfterN(T oldValue, T newValue, unsigned int n);
    void fnInvertir();

    void eliminar(int pos);
    void reemplazar(int pos, T dato);
    void vaciar();

    T getDato(int pos);

    void imprimir();
};

template<class T>
void lista<T>::insertAfterN(T oldValue, T newValue, unsigned int n) {

    if(inicio == nullptr)
    {
        throw std::runtime_error("500");
    }
    if(n == 0)
    {
        throw std::runtime_error("401");
    }

    nodo<T> *aux = inicio;
    int contOldValue = 0;

    while(aux != nullptr)
    {
        if(aux->getDato() == oldValue)
        {
            contOldValue++;
        }
        if(contOldValue == n)
        {
            break;
        }
        aux = aux->getSig();
    }

    if(aux == nullptr)
    {
        throw 404;
    }

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSig(aux->getSig());

    aux->setSig(nuevo);
}

template<class T>
nodo<T> *lista<T>::getInicio() {
    return inicio;
}

template<class T>
void lista<T>::setInicio(nodo<T> *_inicio) {
    inicio = _inicio;
}


template<class T>
void lista<T>::insertAfter2(T oldValue, T newValue) {

    if(inicio == nullptr)
    {
        return;
    }

    nodo<T> *aux = inicio;
    int contOldValue = 0;

    while(aux != nullptr)
    {
        if(aux->getDato() == oldValue)
        {
            contOldValue++;
        }
        if(contOldValue == 2)
        {
            break;
        }
        aux = aux->getSig();
    }

    if(aux == nullptr)
    {
        throw 404;
    }

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSig(aux->getSig());

    aux->setSig(nuevo);

}

template<class T>
void lista<T>::fnInvertir() {

    if(inicio == nullptr)
    {
        return;
    }

    nodo<T> *aux = inicio;
    nodo<T> *anterior = nullptr;
    nodo<T> *siguiente = inicio;

    siguiente = siguiente->getSig();

    while(siguiente != nullptr)
    {

        aux->setSig(anterior);

        anterior = aux;
        aux = siguiente;
        siguiente = siguiente->getSig();

    }
    aux->setSig(anterior);
    inicio = aux;
}

template<class T>
void lista<T>::imprimir() {
    nodo<T> *aux = inicio;
    while(aux != nullptr)
    {
        std::cout<< aux->getDato() << "->";
        aux = aux->getSig();
    }
    std::cout << "NULL"<<std::endl;
}

template<class T>
void lista<T>::vaciar() {
    nodo<T> *aux = inicio, *aBorrar;

    while(aux != nullptr)
    {
        aBorrar = aux;
        aux = aux->getSig();
        delete aBorrar;
    }

    inicio = nullptr;
}

template<class T>
void lista<T>::reemplazar(int pos, T dato) {

    nodo<T> *aux = inicio;
    int posActual = 0;


    while((aux != nullptr) && (posActual != pos))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == nullptr)
    {
        throw 400;
    }

    aux->setDato(dato);
}

template<class T>
T lista<T>::getDato(int pos) {

    nodo<T> *aux = inicio;
    int posActual = 0;


    while((aux != nullptr) && (posActual != pos))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == nullptr)
    {
        throw 400;
    }

    return aux->getDato();
}

template<class T>
void lista<T>::eliminar(int pos) {
    nodo<T> *aux = inicio,
            *aBorrar;
    int posActual = 0;

    if(pos == 0)
    {
        inicio = inicio->getSig();
        delete aux;
        return;
    }

    while( (aux != nullptr) && (posActual != pos-1))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == nullptr)
    {
        throw 400;
    }

    aBorrar = aux->getSig();

    aux->setSig(aBorrar->getSig());
    delete aBorrar;

}

template<class T>
void lista<T>::insertarUltimo(T dato) {

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);
    nodo<T> *aux = inicio;

    if(aux == nullptr)
    {
        nuevo->setSig(nullptr);
        inicio=nuevo;
        return;
    }

    while(aux->getSig() != nullptr)
    {
        aux = aux->getSig();
    }

    nuevo->setSig(nullptr);
    aux->setSig(nuevo);

}

template<class T>
void lista<T>::insertarPrimero(T dato) {

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);
    nuevo->setSig(inicio);
    inicio = nuevo;

}

template<class T>
void lista<T>::insertar(int pos, T dato) {

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);

    if(pos == 0)
    {
        nuevo->setSig(inicio);
        inicio = nuevo;
        return;
    }

    nodo<T> *aux = inicio;
    int posActual = 0;


    while( (aux != nullptr) && (posActual != pos-1))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == nullptr)
    {
        throw 400;
    }

    nuevo->setSig(aux->getSig());
    aux->setSig(nuevo);

}

template<class T>
int lista<T>::getTamanio() {
    nodo<T> *aux = inicio;
    int tam = 0;

    while(aux != nullptr)
    {
        tam++;
        aux = aux->getSig();
    }

    return tam;
}

template<class T>
bool lista<T>::esVacia() {
    return inicio == nullptr;
}

template<class T>
lista<T>::~lista() {
    vaciar();
    delete inicio;
}

template<class T>
lista<T>::lista( lista<T> &li) {
    inicio = li.getInicio();
}

template<class T>
lista<T>::lista() {
    inicio = nullptr;
}


#endif //LISTAS_LISTA_H
