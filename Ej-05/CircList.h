#ifndef U02_LISTAS_EJ_05_CIRCLIST_H_
#define U02_LISTAS_EJ_05_CIRCLIST_H_

#include "../Lista/nodo.h"


template <class T>
class CircList {
private:
    nodo<T> *inicio;
public:
    CircList();
    ~CircList();
    CircList(const CircList <T> &li);

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
void CircList<T>::insertAfterN(T oldValue, T newValue, unsigned int n) {

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

    do
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
    } while(aux != inicio);

    if(aux == inicio && contOldValue != n)
    {
        throw std::runtime_error("404");
    }

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSig(aux->getSig());

    aux->setSig(nuevo);

}

template<class T>
nodo<T> *CircList<T>::getInicio() {
    return inicio;
}

template<class T>
void CircList<T>::setInicio(nodo<T> *_inicio) {
    inicio = _inicio;
}


template<class T>
void CircList<T>::insertAfter2(T oldValue, T newValue) {

    if(inicio == nullptr)
    {
        throw std::runtime_error("500");
    }

    nodo<T> *aux = inicio;
    int contOldValue = 0;

    do
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
    } while(aux != inicio);

    if(aux == inicio && contOldValue != 2)
    {
        throw 404;
    }

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(newValue);
    nuevo->setSig(aux->getSig());

    aux->setSig(nuevo);

}

template<class T>
void CircList<T>::fnInvertir() {

    if(inicio == nullptr || inicio->getSig() == inicio)
    {
        return;
    }

    nodo<T> *aux = inicio;
    nodo<T> *anterior = inicio;

    while(anterior->getSig() != inicio)
    {
        anterior = anterior->getSig();
    }
    nodo<T> *siguiente = inicio;

    siguiente = siguiente->getSig();

    while(siguiente != inicio)
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
void CircList<T>::imprimir() {
    nodo<T> *aux = inicio;
    while(aux->getSig() != inicio)
    {
        std::cout<< aux->getDato() << "->";
        aux = aux->getSig();
    }
    std::cout<< aux->getDato() << "->";
    std::cout << "START"<<std::endl;
}

template<class T>
void CircList<T>::vaciar() {
    nodo<T> *aux = inicio, *aBorrar;

    while(aux->getSig() != inicio)
    {
        aBorrar = aux;
        aux = aux->getSig();
        delete aBorrar;
    }
    delete aux;
    inicio = nullptr;
}

template<class T>
void CircList<T>::reemplazar(int pos, T dato) {

    nodo<T> *aux = inicio;
    int posActual = 0;


    while((aux != inicio || posActual == 0) && (posActual != pos))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == inicio && posActual != 0)
    {
        throw 400;
    }

    aux->setDato(dato);
}

template<class T>
T CircList<T>::getDato(int pos) {

    nodo<T> *aux = inicio;
    int posActual = 0;


    while((aux != inicio || posActual == 0) && (posActual != pos))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == inicio && posActual != 0)
    {
        throw 400;
    }

    return aux->getDato();
}

template<class T>
void CircList<T>::eliminar(int pos) {
    nodo<T> *aux = inicio,
            *aBorrar;
    int posActual = 0;

    if(pos == 0)
    {
        aBorrar = aux;
        while( (aux->getSig() != inicio))
        {
            aux = aux->getSig();
        }
        inicio = inicio->getSig();
        aux->setSig(inicio);

        delete aBorrar;
        return;
    }

    while( (aux != inicio || posActual == 0) && (posActual != pos-1))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == inicio && posActual != 0 )
    {
        throw 400;
    }

    aBorrar = aux->getSig();

    aux->setSig(aBorrar->getSig());
    delete aBorrar;

}

template<class T>
void CircList<T>::insertarUltimo(T dato) {

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);
    nodo<T> *aux = inicio;

    if(aux == nullptr)
    {
        nuevo->setSig(nuevo);
        inicio=nuevo;
        return;
    }

    while(aux->getSig() != inicio)
    {
        aux = aux->getSig();
    }

    nuevo->setSig(inicio);
    aux->setSig(nuevo);

}

template<class T>
void CircList<T>::insertarPrimero(T dato) {

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);

    if(inicio == nullptr)
    {
        inicio = nuevo;
        nuevo->setSig(inicio);
        return;
    }else{
        nuevo->setSig(inicio);
        nodo<T> *aux = inicio;

        while( (aux->getSig() != inicio))
        {
            aux = aux->getSig();
        }
        aux->setSig(nuevo);
        inicio = nuevo;
        return;
    }


}

template<class T>
void CircList<T>::insertar(int pos, T dato) {

    nodo<T> *nuevo = new nodo<T>;
    nuevo->setDato(dato);

    if(pos == 0)
    {
        if(inicio == nullptr)
        {
            inicio = nuevo;
            nuevo->setSig(nuevo);
            return;
        } else{
            nuevo->setSig(inicio);
            nodo<T> *aux = inicio;

            while( (aux->getSig() != inicio))
            {
                aux = aux->getSig();
            }
            aux->setSig(nuevo);
            inicio = nuevo;
            return;
        }
    }

    nodo<T> *aux = inicio;
    int posActual = 0;

    while( (aux != inicio || posActual == 0) && (posActual != pos-1))
    {
        aux = aux->getSig();
        posActual++;
    }

    if(aux == inicio && posActual != 0)
    {
        throw 400;
    }

    nuevo->setSig(aux->getSig());
    aux->setSig(nuevo);

}

template<class T>
int CircList<T>::getTamanio() {
    if(inicio == nullptr)
    {
        throw 500;
    }


    nodo<T> *aux = inicio;
    int tam = 0;

    while(aux->getSig() != inicio)
    {
        tam++;
        aux = aux->getSig();
    }
    tam++;
    return tam;
}

template<class T>
bool CircList<T>::esVacia() {
    return inicio == nullptr;
}

template<class T>
CircList<T>::~CircList() {
    vaciar();
    delete inicio;
}

template<class T>
CircList<T>::CircList(const CircList<T> &li) {
    inicio = li.inicio;
}

template<class T>
CircList<T>::CircList() {
    inicio = nullptr;
}


#endif // U02_LISTAS_EJ_05_CIRCLIST_H_
