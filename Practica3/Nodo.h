//
// Created by Nitropc on 05/10/2026.
//

#ifndef PRACTICA2_NODO_H
#define PRACTICA2_NODO_H
template <class T>
class ListaDEnlazada;
template <class T>
class Nodo{
public:
    T dato;
    Nodo<T> *sig;
    Nodo<T> *ant;
private:
    friend class ListaDEnlazada<T>;
    Nodo(const T &dato, Nodo<T> *sig=nullptr,Nodo<T>*ant=nullptr);
    Nodo<T>& operator=(const T &nodo);
    ~Nodo();
};
template<class T>
    Nodo<T>::Nodo(const T &dato, Nodo<T> *sig,Nodo<T>*ant){
    this->dato=dato;
    this->sig=sig;
    this->ant=ant;
}
template<class T>
Nodo<T>& Nodo<T>::operator=(const T &nodo){
    this->dato=nodo.dato;
    this->sig=nodo.sig;
    this->ant=nodo.ant;
    return *this;
}
template <class T>
    Nodo<T>::~Nodo(){}
#endif //PRACTICA2_NODO_H