#include "Arbol.h"
#include "AVL.h"

Arbol::Arbol(const std::string assetnum, int num_parque, int num_distrito, const std::string nbre_distrito, int num_barrio, const std::string nbre_barrio, double X, double Y, float perimetro, float altura)
    : _assetnum(assetnum), _num_parque(num_parque), _num_distrito(num_distrito), _nbre_distrito(nbre_distrito), _num_barrio(num_barrio), _nbre_barrio(nbre_barrio), _X(X), _Y(Y), _perimetro(perimetro), _altura(altura) {}

bool Arbol::setEspecie(Especie &e) {
    return especie.inserta(e);
}

std::string Arbol::getCodigoEspecie() {
    if (especie.numElementos() > 0) {
        Especie esp = *(especie.recorreinorden()[0]);
        return esp.get_codigo_especie();
    }
    return "";
}

std::string Arbol::getTipoEspecie() {
    if (especie.numElementos() > 0) {
        Especie esp = *(especie.recorreinorden()[0]);
        return esp.tipoPlantaATexto(esp.get_tipo_planta());
    }
    return "";
}

std::string Arbol::getNbreComun() {
    if (especie.numElementos() > 0) {
        Especie esp = *(especie.recorreinorden()[0]);
        return esp.get_nombre_comun();
    }
    return "";
}