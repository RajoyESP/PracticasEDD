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
        Especie* _especie;

    public:
        Arbol():_especie(nullptr) {}
        Arbol(const std::string &assetnum) : _assetnum(assetnum), _especie(nullptr) {}
        Arbol(const std::string assetnum, int num_parque, int num_distrito, const std::string nbre_distrito, int num_barrio, const std::string nbre_barrio, double X, double Y, float perimetro, float altura);
        void setEspecie(Especie &e);
        std::string getCodEspecie();
        std::string getTipoEspecie();
        std::string getNbreComun();
        bool operator==(const Arbol &otro) const;
        bool operator<(const Arbol &otro) const;
        bool operator>(const Arbol &otro) const;
        std::string getAssetnum() const;
        float getAltura() const;
};
#endif // PRACTICA3_ARBOL_H