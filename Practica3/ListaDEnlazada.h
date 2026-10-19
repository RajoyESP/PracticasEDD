//
// Created by Nitropc on 05/10/2026.
//

#ifndef PRACTICA2_LISTADENLAZADA_H
#define PRACTICA2_LISTADENLAZADA_H
#include "Nodo.h"

#include "Iterador.h"
template <class T>
class ListaDEnlazada;
template <class T>
class ListaDEnlazada{
private:
    Nodo<T>*cabecera;
    Nodo<T>*cola;
public:
    ListaDEnlazada();
    ListaDEnlazada(const ListaDEnlazada<T> &Lista);
    ListaDEnlazada<T> &operator = (ListaDEnlazada<T> &lista);
    T& inicio();
    T& fin();
    void insertaInicio(const T &dato);
    void insertaFin(const T &dato);
    void inserta(Iterador<T> &i,const T &dato);
    void borraInicio();
    void borraFin();
    void borra(Iterador<T> &i);
    int tam();
    ListaDEnlazada<T>& concatena(const ListaDEnlazada<T> lista);
    ~ListaDEnlazada();
    Iterador<T> iterador();
};

template <class T>
ListaDEnlazada<T>::ListaDEnlazada(){
    cabecera =nullptr;
    cola =nullptr;
}
template <class T>
ListaDEnlazada<T>::ListaDEnlazada(const ListaDEnlazada<T> &Lista){
    cabecera=nullptr;
    cola=nullptr;
    Nodo<T> *actual = Lista.cabecera;
    while(actual!=nullptr){
        this->insertaFin(actual->dato);
        actual = actual->sig;
    }
}
template <class T>
ListaDEnlazada<T>& ListaDEnlazada<T>::operator = (ListaDEnlazada<T> &lista){
    if (this == &lista) return *this;
    while (cabecera != nullptr) {
        borraInicio();
    }
    Nodo<T> *actual = lista.cabecera;
    while (actual != nullptr) {
        this->insertaFin(actual->dato);
        actual = actual->sig;
    }
    return *this;
}
template <class T>
T& ListaDEnlazada<T>::inicio(){
    return cabecera->dato;
}
template <class T>
T& ListaDEnlazada<T>::fin(){
    return cola->dato;
}
template <class T>
void ListaDEnlazada<T>::insertaInicio(const T& dato){
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, cabecera,nullptr);
    if (cola == nullptr)
        cola = nuevo;
    if (cabecera != nullptr)
        cabecera->ant = nuevo;
    cabecera = nuevo;
}

template <class T>
void ListaDEnlazada<T>::insertaFin(const T& dato) {
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, nullptr, cola);
    if (cabecera == nullptr)
        cabecera = nuevo;
    if (cola != nullptr)
        cola->sig = nuevo;
       cola = nuevo;
}

template <class T>
void ListaDEnlazada<T>::inserta(Iterador<T>& i,const T& dato) {
    Nodo<T> *p=i.nodo;
    if (p==0) {
        throw std::invalid_argument("ListaDEnlazada::inserta -> iterador no válido");
    }
    if (p==cabecera) {
        insertaInicio(dato);
    }
    else {
        Nodo<T> *nuevo;
        nuevo=new Nodo<T>(dato,p,p->ant);
        p->ant->sig=nuevo;
        p->ant=nuevo;
    }
}

template <class T>
void ListaDEnlazada<T>::borraInicio(){
    Nodo<T> *borrado = cabecera;
    cabecera = cabecera->sig;
    delete borrado;
    if (cabecera != nullptr)
        cabecera->ant = nullptr;
    else
        cola = nullptr;
}
template <class T>
void ListaDEnlazada<T>::borraFin(){
    Nodo<T> *borrado = cola;
    cola = cola->ant;
    delete borrado;
    if(cola!=nullptr)
        cola->sig = nullptr;
    else
        cabecera =nullptr;
}

template <class T>
void ListaDEnlazada<T>::borra(Iterador<T> &i){
    Nodo<T>*p=i.nodo;
    if (p == nullptr) {
        throw std::invalid_argument("Iterador nulo");
    }
    if (p == cabecera) {
        borraInicio();
    } else if (p == cola) {
        borraFin();
    } else {
        p->ant->sig = p->sig;
        p->sig->ant = p->ant;
        delete p;
    }
}
template <class T>
int ListaDEnlazada<T>::tam(){
    int tam=0;
    Nodo<T> *nuevo=cabecera;
    while(nuevo!=nullptr){
        nuevo=nuevo->sig;
        tam++;
    }
    return tam;
}
template <class T>
ListaDEnlazada<T>& ListaDEnlazada<T>::concatena(const ListaDEnlazada<T> lista){
    ListaDEnlazada<T> listafinal(this);
    Nodo<T> *actual = lista.cabecera;
    while(actual!=nullptr){
        this->insertaFin(actual->dato);
        actual = actual->sig;
    }
    return listafinal;
}

template <class T>
ListaDEnlazada<T>::~ListaDEnlazada(){
    Nodo<T> *borrado;
    while (cabecera != nullptr){
        borrado=cabecera;
        cabecera=cabecera->sig;
        delete borrado;
    }
}
template <class T>
Iterador<T> ListaDEnlazada<T>:: iterador() {
    Nodo<T> *nuevo;
    nuevo=cabecera;
    Iterador<T> it(nuevo);
    return it;
}
#endif //PRACTICA2_LISTADENLAZADA_H