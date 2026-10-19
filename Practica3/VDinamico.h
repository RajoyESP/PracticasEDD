//
// Created by admin on 18/09/2026.
//

#ifndef VDINAMICO_H
#define VDINAMICO_H

#include <iostream>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <cmath>

template<class T>
class VDinamico {
private:
    unsigned int tamal;
    unsigned int tamaf;
    T *dato;
    unsigned int calcularPotencia2(unsigned int tamano) const {
        if (tamano == 0) return 1;
        unsigned int potencia = 1;
        while (potencia < tamano) {
            potencia *= 2;
        }
        return potencia;
    }
public:
    VDinamico();
    VDinamico(unsigned int tamlog, const T &datoInicial);
    VDinamico(const VDinamico<T>& origen);
    VDinamico(const VDinamico<T>& origen, unsigned int posicionInicial, unsigned int numElementos);
    ~VDinamico();
    VDinamico<T>& operator=(const VDinamico<T>& orig);
    T& operator[](unsigned int pos);
    void insertar(const T& nuevoDato, unsigned int pos = UINT_MAX);
    T borrar(unsigned int pos = UINT_MAX);
    void ordenar();
    int busquedaDicotomica(T& datoABuscar);
    unsigned int tamlog() const;
};

template<class T>
VDinamico<T>::VDinamico() {
    tamaf = 1;
    tamal = 0;
    dato = new T[tamaf];
}

template<class T>
VDinamico<T>::VDinamico(unsigned int tamlog, const T &datoInicial) {
    this->tamal = tamlog;
    this->tamaf = calcularPotencia2(tamlog);
    dato = new T[tamaf];
    for (unsigned int c = 0; c < tamlog; c++) {
        dato[c] = datoInicial;
    }
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen) {
    tamal = origen.tamal;
    tamaf = origen.tamaf;
    dato = new T[tamaf];
    for (unsigned int c = 0; c < tamal; c++) {
        dato[c] = origen.dato[c];
    }
}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T>& origen, unsigned int posicionInicial, unsigned int numElementos) {
    if (posicionInicial + numElementos > origen.tamal) {
        throw std::out_of_range("Copia parcial fuera de rango.");
    }
    tamal = numElementos;
    tamaf = calcularPotencia2(tamal);
    dato = new T[tamaf];
    for (unsigned int c = 0; c < tamal; c++) {
        dato[c] = origen.dato[posicionInicial + c];
    }
}

template<class T>
VDinamico<T>::~VDinamico() {
    delete[] dato;
}

template<class T>
VDinamico<T>& VDinamico<T>::operator=(const VDinamico<T>& orig) {
    if (this != &orig) {
        delete[] dato;
        tamaf = orig.tamaf;
        tamal = orig.tamal;
        dato = new T[tamaf];
        for (unsigned int c = 0; c < tamal; c++) {
            dato[c] = orig.dato[c];
        }
    }
    return *this;
}

template<class T>
T& VDinamico<T>::operator[](unsigned int pos) {
    if (pos >= tamal) {
        throw std::out_of_range("Posicion fuera de rango de operator[]");
    }
    return dato[pos];
}

template<class T>
void VDinamico<T>::insertar(const T& nuevoDato, unsigned int pos) {
    if (pos == UINT_MAX) {
        pos = tamal; // Se inserta al final
    } else if (pos > tamal) {
        throw std::out_of_range("Posicion de insercion fuera de los limites del vector");
    }

    // Si se necesita, se aumenta el tamaño fisico
    if (tamal == tamaf) {
        tamaf = tamaf * 2;
        T *vaux = new T[tamaf];
        for (unsigned int i = 0; i < tamal; i++) {
            vaux[i] = dato[i];
        }
        delete[] dato;
        dato = vaux;
    }

    // Desplaza hacia la derecha para hacer hueco
    for (unsigned int i = tamal; i > pos; i--) {
        dato[i] = dato[i - 1];
    }

    dato[pos] = nuevoDato;
    tamal++;
}

template<class T>
T VDinamico<T>::borrar(unsigned int pos) {
    if (tamal == 0) {
        throw std::underflow_error("El vector esta vacio.");
    }

    if (pos == UINT_MAX) {
        pos = tamal - 1; // Borra el ultimo
    } else if (pos >= tamal) {
        throw std::out_of_range("Posicion de borrado fuera de rango.");
    }

    T elementoBorrado = dato[pos];

    // Desplaza hacia la izquierda para tapar el hueco
    for (unsigned int i = pos; i < tamal - 1; i++) {
        dato[i] = dato[i + 1];
    }
    tamal--;

    // Reduce tamaño físico si tamal * 3 < tamaf
    if (tamal * 3 < tamaf && tamaf > 1) {
        tamaf = tamaf / 2;
        T *vaux = new T[tamaf];
        for (unsigned int i = 0; i < tamal; i++) {
            vaux[i] = dato[i];
        }
        delete[] dato;
        dato = vaux;
    }

    return elementoBorrado;
}

template<class T>
void VDinamico<T>::ordenar() {
    std::sort(dato, dato + tamal);
}


template<class T>
int VDinamico<T>::busquedaDicotomica(T& datoABuscar) {
    int inf = 0;
    int sup = tamal - 1;
    int curIn;

    while (inf <= sup) {
        curIn = (inf + sup) / 2;
        if (dato[curIn] == datoABuscar) {
            return curIn;
        } else if (dato[curIn] < datoABuscar) {
            inf = curIn + 1;
        } else {
            sup = curIn - 1;
        }
    }
    return -1;
}

template<class T>
unsigned int VDinamico<T>::tamlog() const {
    return tamal;
}

#endif // VDINAMICO_H