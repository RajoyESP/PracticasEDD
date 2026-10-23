#ifndef PRACTICA3_ARBOL_H
#define PRACTICA3_ARBOL_H

#include <string>
#include "Especie.h"

class Arbol {
    private:
        std::string _assetnum;
        int _num_parque;
        int _num_distrito;
        std::string _nbre_distrito;
        int _num_barrio;
        std::string _nbre_barrio;
        std::string _nbre_comun;
        std::string _nbre_cientifico;
        double _X;
        double _Y;
        float _perimetro;
        float _altura;

    public:
        Arbol(std::string assetnum, int num_parque, int num_distrito, std::string nbre_distrito, int num_barrio, std::string nbre_barrio, double X, double Y, float perimetro, float altura);
        Especie setEspecie(const Especie& e);
        std::string getCodigoEspecie() const;
        std::string getTipoEspecie() const;
        std::string getNbreComun() const;
}
#endif // PRACTICA3_ARBOL_H