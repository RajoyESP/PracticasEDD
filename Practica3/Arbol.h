#ifndef PRACTICA3_ARBOL_H
#define PRACTICA3_ARBOL_H

#include <string>
#include "Especie.h"
#include "AVL.h"
#include "VDinamico.h"

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
        Avl<Especie> especie;

    public:
        Arbol(){}
        Arbol(const std::string assetnum, int num_parque, int num_distrito, const std::string nbre_distrito, int num_barrio, const std::string nbre_barrio, double X, double Y, float perimetro, float altura);
        bool setEspecie(Especie &e);
        std::string getCodigoEspecie();
        std::string getTipoEspecie();
        std::string getNbreComun();
};
#endif // PRACTICA3_ARBOL_H