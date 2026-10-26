//
// Created by admin on 09/10/2026.
//
#include "Parque.h"

Parque::Parque():_cod_parque(0),_nbre_parque("") {}

Parque::Parque(int cod_parque, std::string nbre_parque):_cod_parque(cod_parque),_nbre_parque(nbre_parque){}

void Parque::insertarArbol(Arbol *arb) {
    vArboles.insertar(arb);
}

Arbol* Parque::arbolMasAlto() {
    if (vArboles.tamlog()!=0) {
        Arbol* maxArbol = vArboles[0];
        for (unsigned int i = 1; i < vArboles.tamlog(); ++i) {
            if (vArboles[i]->getAltura() > maxArbol->getAltura()) {
                maxArbol = vArboles[i];
            }
        }
        return maxArbol;
    }
    return nullptr;
}

bool Parque::existeNbreCom(std::string ncomun) {
    for (unsigned int i = 0; i < vArboles.tamlog(); ++i) {
        if (vArboles[i]->getNbreComun() == ncomun) {
            return true;
        }
    }
    return false;
}

int Parque::contarEspecies() {
    VDinamico<std::string> especiesUnicas;
    for (unsigned int i = 0; i < vArboles.tamlog(); ++i) {
        std::string codEspecie = vArboles[i]->getCodEspecie();
        if (codEspecie.empty()){

        }
        bool encontrada = false;
        for (unsigned int j = 0; j < especiesUnicas.tamlog(); ++j) {
            if (especiesUnicas[j] == codEspecie) {
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            especiesUnicas.insertar(codEspecie);
        }
    }
    return especiesUnicas.tamlog();
}

int Parque::contarTipos() {
    VDinamico<std::string> tiposUnicos;
    for (unsigned int i = 0; i < vArboles.tamlog(); ++i) {
        std::string tipoPlanta = vArboles[i]->getTipoEspecie();

        bool encontrado = false;
        for (unsigned int j = 0; j < tiposUnicos.tamlog(); ++j) {
            if (tiposUnicos[j] == tipoPlanta) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            tiposUnicos.insertar(tipoPlanta);
        }
    }
    return tiposUnicos.tamlog();
}

int Parque::get_cod_parque() {
    return _cod_parque;
}

std::string Parque::get_nbre_parque() {
    return _nbre_parque;
}

VDinamico<Arbol*>& Parque::get_contains() {
    return vArboles;
}

void Parque::set_nbre_parque(const std::string nbre_parque) {
    _nbre_parque = nbre_parque;
}
void Parque::set_cod_parque(const int cod_parque) {
    _cod_parque = cod_parque;
}