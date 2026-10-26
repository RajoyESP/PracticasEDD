//
// Created by admin on 09/10/2026.
//

#ifndef PRACTICA2_CONTROLPARQUES_H
#define PRACTICA2_CONTROLPARQUES_H

#include "VDinamico.h"
#include "Especie.h"
#include "ListaDEnlazada.h"
#include "Parque.h"
#include "AVL.h"
#include "Arbol.h"

class ControlParques {
private:
    VDinamico<Especie> vEspeciesTotales;
    ListaDEnlazada<Parque> lParques;
    Avl<Arbol> AArboles;

public:
    ControlParques(std::string rutaEspecies, std::string rutaParques);

    Arbol* buscarArbol(std::string asNum);
    VDinamico<Arbol*> listaArbParque(std::string nbre_parque);
    Arbol* arbolMasAlto();
    int contarEspecies(std::string nbre_parque);
    int contarTipos();

    // void asignarEspecieParque(Especie e,Parque p);
    int contarEspecieParque(std::string ncomun);
    VDinamico<Especie*> listadoEspecieSubNbre(std::string cadena);
    Parque* buscarParque(std::string nbre_parque);
    Especie* buscarEspecie(std::string nbre_parque);
    VDinamico<Especie> &get_varieties();
    ListaDEnlazada<Parque> &get_parks();
    void eliminarParque(std::string nombre);
    // void eliminarEspecie(std::string nombre);
};


#endif