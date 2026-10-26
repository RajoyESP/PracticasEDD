//
// Created by Portatil on 09/10/2026.
//

#ifndef PRACTICA2_PARQUE_H
#define PRACTICA2_PARQUE_H

#include <string>
#include "VDinamico.h"
#include "Arbol.h"

class Parque {
private:
    int _cod_parque;
    std::string _nbre_parque;
    VDinamico<Arbol*> vArboles;
public:
    Parque();
    Parque(int cod_parque, std::string nbre_parque);

    void insertarArbol(Arbol *arb);
    Arbol* arbolMasAlto();
    int contarEspecies();
    int contarTipos();

    bool existeNbreCom(std::string ncomun);
    int get_cod_parque();
    std::string get_nbre_parque();
    void set_nbre_parque(std::string const nbre_parque);
    void set_cod_parque(int const cod_parque);
    VDinamico<Arbol*> &get_contains();
};


#endif