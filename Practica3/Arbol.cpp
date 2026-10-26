#include "Arbol.h"

Arbol::Arbol(const std::string assetnum, int num_parque, int num_distrito, const std::string nbre_distrito, int num_barrio, const std::string nbre_barrio, double X, double Y, float perimetro, float altura)
    : _assetnum(assetnum), _num_parque(num_parque), _num_distrito(num_distrito), _nbre_distrito(nbre_distrito), _num_barrio(num_barrio), _nbre_barrio(nbre_barrio), _X(X), _Y(Y), _perimetro(perimetro), _altura(altura), _especie(nullptr) {}

void Arbol::setEspecie(Especie &e) {
    _especie = &e;
}

std::string Arbol::getCodEspecie() {
    if (_especie!=nullptr) {
        return _especie->get_codigo_especie();
    }
    return "No tiene especie asociada";
}

std::string Arbol::getTipoEspecie() {
    if (_especie!=nullptr) {
        return _especie->tipoPlantaATexto(_especie->get_tipo_planta());
    }
    return "No tiene especie asociada";
}

std::string Arbol::getNbreComun() {
    if (_especie!=nullptr) {
        return _especie->get_nombre_comun();
    }
    return "No tiene especie asociada";
}

bool Arbol::operator==(const Arbol &otro) const {
    return _assetnum == otro._assetnum;
}

bool Arbol::operator<(const Arbol &otro) const {
    return _assetnum < otro._assetnum;
}

bool Arbol::operator>(const Arbol &otro) const {
    return _assetnum > otro._assetnum;
}

std::string Arbol::getAssetnum() const {
    return _assetnum;
}

float Arbol::getAltura() const {
    return _altura;
}