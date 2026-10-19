//
// Created by Portatil on 25/09/2026.
//

#ifndef ESPECIE_H
#define ESPECIE_H

#include <string>
#include <iostream>

enum TipoPlanta {
    VACIO, ARBUSTO, CONIFERA, PALMACEA, HERB_PERENNES, FRONDOSA,TAPIZANTE_TREPADORA,
    CACTACEA_SUCULENTA, SUBTROPICAL_TROPICAL, HERB_ANUAL, HERB_ANUALES
};

class Especie {
private:
    std::string _cod_especie;
    std::string _nbre_comun;
    std::string _nbre_cientif;
    TipoPlanta _tipo_planta;
public:
    Especie(){}
    Especie(const std::string& cod_especie, const std::string& nbre_comun, const std::string& nbre_cientif, TipoPlanta tipo_planta) {
        _cod_especie = cod_especie;
        _nbre_comun = nbre_comun;
        _nbre_cientif = nbre_cientif;
        _tipo_planta = tipo_planta;
    }
    std::string get_codigo_especie() const {
        return _cod_especie;
    }
    std::string get_nombre_comun() const {
        return _nbre_comun;
    }
    std::string get_nombre_cientifico() const {
        return _nbre_cientif;
    }
    TipoPlanta get_tipo_planta() const {
        return _tipo_planta;
    }
    void set_codigo_especie(const std::string& cod_especie) {
        _cod_especie = cod_especie;
    }
    void set_nombre_comun(const std::string& nbre_comun) {
        _nbre_comun = nbre_comun;
    }
    void set_nombre_cientifico(const std::string& nbre_cientif) {
        _nbre_cientif = nbre_cientif;
    }
    std::string tipoPlantaATexto(TipoPlanta tipoPlanta) {
        switch (tipoPlanta) {
            case VACIO: return "Sin tipo de especie";
            case ARBUSTO: return "Arbusto";
            case CONIFERA: return "Conifera";
            case PALMACEA: return "Palmacea";
            case HERB_PERENNES: return "Herbacea perenne";
            case FRONDOSA: return "Frondosa";
            case TAPIZANTE_TREPADORA: return "Tapizante o trepadora";
            case CACTACEA_SUCULENTA: return "Catacea o suculenta";
            case SUBTROPICAL_TROPICAL: return "Subtropical o tropical";
            case HERB_ANUAL: return "Herbacea anual";
            case HERB_ANUALES: return "Herbaceas anuales";
        }
        return "Sin identificar";
    }

    bool operator==(Especie &e) {
        if (_cod_especie==e.get_codigo_especie()) {
            return true;
        }
        return false;
    }
    bool operator!=(const Especie &e) {
        if (_nbre_cientif!=e.get_nombre_cientifico()) {
            return true;
        }
        return false;
    }

    bool operator<(Especie &e) {
        if (_cod_especie<e.get_codigo_especie()) {
            return true;
        }
        return false;
    }

    void mostrarInfo() {
        std::cout<<"Codigo especie: "<<_cod_especie<<std::endl;
        std::cout<<"Nombre especie: "<<_nbre_comun<<std::endl;
        std::cout<<"Nombre cientifico: "<<_nbre_cientif<<std::endl;
        std::cout<<"Tipo planta: "<<_tipo_planta<<std::endl;

    }
};


#endif