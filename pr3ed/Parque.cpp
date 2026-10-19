//
// Created by admin on 09/10/2026.
//
#include "Parque.h"

void Parque::insertaEspecie(Especie *esp) {
    vEspecies.insertar(esp);
}

bool Parque::existeNbreCom(std::string ncomun) {
    for (unsigned i=0;i<vEspecies.tamlog();++i) {
        if (vEspecies[i]->get_nombre_comun()==ncomun) {
            return true;
        }
    }
    return false;
}

bool Parque::existeNbreCie(std::string ncient) {
    for (unsigned i=0;i<vEspecies.tamlog();++i) {
        if (vEspecies[i]->get_nombre_cientifico()==ncient) {
            return true;
        }
    }
    return false;
}

Parque::Parque():_cod_parque(0),_nbre_parque("") {}

Parque::Parque(int cod_parque, std::string nbre_parque):_cod_parque(cod_parque),_nbre_parque(nbre_parque){}

int Parque::get_cod_parque() {
    return _cod_parque;
}

std::string Parque::get_nbre_parque() {
    return _nbre_parque;
}

VDinamico<Especie*>& Parque::get_contains() {
    return vEspecies;
}

void Parque::set_nbre_parque(const std::string nbre_parque) {
    _nbre_parque = nbre_parque;
}
void Parque::set_cod_parque(const int cod_parque) {
    _cod_parque = cod_parque;
}