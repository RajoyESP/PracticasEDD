//
// Created by Nitropc on 23/10/2026.
//

#include "NodoA.h"
#include <iostream>
#include "VDinamico.h"

#ifndef PRACTICA2_AVL_H
#define PRACTICA2_AVL_H
template <typename T>
class Avl {
    NodoA<T> *raiz;
private:
    int inserta(NodoA<T>* &c, T &dato);
    void rotDecha(NodoA<T>* &p);
    void rotIzqda(NodoA<T>* &p);
public:
    Avl(): raiz(0) {}
    bool inserta(T &dato){ return inserta(raiz,dato); }
    void preorden (NodoA<T> *p, int nivel);
    Avl(const Avl<T> &origen);
    void operator =(const Avl<T> &origen);
    T* buscaRec(T &dato);
    T* buscaIt(T &dato);
    void inordenAux(NodoA<T>* p, VDinamico<T*>& vector);
    VDinamico<T*> recorreinorden ();
    unsigned int numElementos();
    unsigned int alturaAux(NodoA<T>* nodo);
    unsigned int altura();
    void eliminarposorden(NodoA<T>* &nodo);
};
template<typename T>
void Avl<T>::rotIzqda(NodoA<T>* &p){
    NodoA<T> *q = p, *r;
    p = r = q->der;
    q->der = r->izq;
    r->izq = q;
    q->bal++;
    if (r->bal < 0) q->bal += -r->bal;
    r->bal++;
    if(q->bal > 0) r->bal += q->bal; }

template<typename T>
void Avl<T>::rotDecha(NodoA<T>* &p){
    NodoA<T> *q = p, *l;
    p = l = q->izq;
    q->izq = l->der;
    l->der = q;
    q->bal--;
    if (l->bal > 0) q->bal -= l->bal;
    l->bal--;
    if(q->bal < 0) l->bal -= -q->bal; }

template<typename T>
int Avl<T>::inserta(NodoA<T>* &c, T &dato){
    NodoA<T> *p = c;
    int deltaH = 0;
    if (!p){
        p = new NodoA<T>(dato);
        c = p; deltaH=1;
    }
    else if (dato > p->dato){
        if (inserta(p->der, dato)){
            p->bal--;
            if (p->bal == -1) deltaH=1;
            else if (p->bal == -2) {
                if (p->der->bal == 1) rotDecha(p->der);
                rotIzqda(c);
            } } }
    else if (dato < p->dato){
        if (inserta(p->izq, dato)){
            p->bal++;
            if (p->bal==1) deltaH = 1;
            else if (p->bal == 2){
                if (p->izq->bal == -1) rotIzqda(p->izq);
                rotDecha(c);
            } } }
    return deltaH;
}
template <class T>
void Avl<T>::preorden (NodoA<T> *p, int nivel){
    if (p){
        // Sustituir por procesamiento ---
        std::cout << "Procesando nodo "<< p->dato ;
        std::cout << "en el nivel " << nivel << endl;
        // -----------
        preorden (p->izq, nivel+1);
        preorden (p->der, nivel+1);
    }
}
template <class T>
Avl<T>::Avl(const Avl<T> &origen) {
    NodoA<T> *aux(origen.raiz);
    this->raiz = aux;
    inserta(raiz->der,raiz->der->dato);
    inserta(raiz->izq,raiz->izq->dato);
}

template <class T>
void Avl<T>::operator =(const Avl<T> &origen) {
    NodoA<T> *aux(origen.raiz);
    this->raiz = aux;
    inserta(raiz->der,raiz->der->dato);
    inserta(raiz->izq,raiz->izq->dato);
}

template <class T>
T* Avl<T>::buscaRec(T &dato) {
    if (this->raiz==nullptr)
        return nullptr;
    if (this->raiz->dato == dato)
        return &dato;
    if (raiz->izq!=nullptr) {
        raiz->izq.buscaRec(dato);
    }
    else if (raiz->der!=nullptr) {
        raiz->der.buscaRec(dato);
    }
}
template <class T>
T* Avl<T>::buscaIt(T &dato) {
    NodoA<T> *aux(this->raiz);
    while (aux!=nullptr) {
        if (aux->dato == dato) {
            return &aux->dato;
        }
        if (aux->dato > dato) {
            aux = aux->izq;
        }
        if (aux->dato < dato) {
            aux = aux->der;
        }
    }
    return nullptr;
}

template <class T>
void Avl<T>::inordenAux(NodoA<T>* p, VDinamico<T*>& vector) {
    if (p != nullptr) {
        inordenAux(p->izq, vector);
        vector.inserta(p->dato, vector.tamlog());
        inordenAux(p->der, vector);
    }
}
template <class T>
VDinamico<T*> Avl<T>::recorreinorden (){
    VDinamico<T*> vector;
    inordenAux(this->raiz, vector);
    return vector;
}
template <class T>
unsigned int Avl<T>::numElementos() {
    return this->recorreinorden().tamlog();
}

template <class T>
unsigned int Avl<T>::alturaAux(NodoA<T>* nodo) {
    if (nodo==nullptr)
        return 0;
    unsigned int izq = alturaAux(nodo->izq);
    unsigned int der = alturaAux(nodo->der);
    if (izq > der)
        return izq;
    else
        return der;
}

template <class T>
unsigned int Avl<T>::altura() {
    return alturaAux(this->raiz);

}

template <class T>
void Avl<T>::eliminarposorden(NodoA<T>* &nodo) {
    if (nodo==nullptr){
        eliminarposorden(nodo->izq);
        eliminarposorden(nodo->der);
        delete nodo;
    }
}
#endif //PRACTICA2_AVL_H
