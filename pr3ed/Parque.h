//
// Created by Portatil on 09/10/2026.
//

#ifndef PRACTICA2_PARQUE_H
#define PRACTICA2_PARQUE_H

#include <string>
#include "Especie.h"
#include "VDinamico.h"

class Parque {
private:
    int _cod_parque;
    std::string _nbre_parque;
    VDinamico<Especie*> vEspecies;
public:
    Parque();
    Parque(int cod_parque, std::string nbre_parque);
    void insertaEspecie(Especie *esp);
    bool existeNbreCom(std::string ncomun);
    bool existeNbreCie(std::string ncient);
    int get_cod_parque();
    std::string get_nbre_parque();
    void set_nbre_parque(std::string const nbre_parque);
    void set_cod_parque(int const cod_parque);
    VDinamico<Especie*> &get_contains();
};


#endif