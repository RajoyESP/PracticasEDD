//
// Created by Nitropc on 05/10/2026.
//

#ifndef PRACTICA2_ITERADOR_H
#define PRACTICA2_ITERADOR_H
#include "Nodo.h"
#include "Iterador.h"
template <class T>
class ListaDEnlazada;
template<class T>
class Iterador {
    Nodo<T> *nodo;
    friend class ListaDEnlazada<T>;
public:

    Iterador(Nodo<T> *aNodo) : nodo(aNodo) {}

    bool hayAnterior() { return nodo != nullptr && nodo->ant != nullptr; }

    bool fin() { return nodo == nullptr; }

    void anterior() { nodo = nodo->ant; }

    void avanza() { nodo = nodo->sig; }

    T &getdato() { return nodo->dato; }

    ~Iterador() =default;
};
#endif //PRACTICA2_ITERADOR_H