
#ifndef LISTAS_NODO_H
#define LISTAS_NODO_H

template <class T>
class nodo {
private:
    T dato;
    nodo<T> *sig;
public:
    nodo();

    void setDato(T _d);
    T getDato();

    void setSig(nodo<T> *_sig);
    nodo<T> *getSig();
};

template<class T>
nodo<T> *nodo<T>::getSig() {
    return sig;
}

template<class T>
void nodo<T>::setSig(nodo<T> *_sig) {
    sig = _sig;
}


template<class T>
T nodo<T>::getDato() {
    return dato;
}

template<class T>
void nodo<T>::setDato(T _d) {
    dato = _d;
}

template<class T>
nodo<T>::nodo() {

}


#endif //LISTAS_NODO_H
