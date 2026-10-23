//
// Created by Nitropc on 23/10/2026.
//

#ifndef PRACTICA2_NODOA_H
#define PRACTICA2_NODOA_H
template <typename U>
class NodoA {
public:
    NodoA<U> *izq, *der;
    U dato;
    char bal; // -1, 0 , 1 para un árbol avl
    NodoA(U &ele): izq(0), der(0), bal(0), dato(ele) {}
    ~NodoA()=default;
    NodoA(const NodoA<U> &n) {
        this->izq = n.izq;
        this->der = n.der;
        this->bal = n.bal;
        this->dato = n.dato;
    }
};
#endif //PRACTICA2_NODOA_H
