#include "ControlParques.h"
#include "Iterador.h"
#include "LectorCSV.h"

ControlParques::ControlParques(std::string rutaEspecies, std::string rutaParques) {
    LectorCSV lector;
    if (!lector.cargarEspecies(vEspeciesTotales, rutaEspecies)) {
        throw std::runtime_error("ControlParques -> no se pudo abrir el fichero de especies");
    }
    if (!lector.cargarParques(lParques,rutaParques)) {
        throw std::runtime_error("ControlParques -> no se pudo abrir el fichero de parques");
    }
}

Arbol* ControlParques::buscarArbol(std::string asNum) {
    Arbol claveArbol(asNum);
    return AArboles.buscaIt(claveArbol);
}

VDinamico<Arbol*> ControlParques::listaArbParque(std::string nbre_parque) {
    Parque* parque = buscarParque(nbre_parque);
    if (parque!=nullptr) {
        return parque->get_contains();
    }
    return VDinamico<Arbol*>();
}

Arbol* ControlParques::arbolMasAlto() {
    Arbol* arbMax = nullptr;
    float maxAltura = -1.0f;

    for (Iterador<Parque> it = lParques.iterador(); it.fin() == false; it.avanza()) {
        Arbol* maxParque = it.getdato().arbolMasAlto();
        if (maxParque != nullptr) {
            if (arbMax == nullptr || maxParque->getAltura() > maxAltura) {
                arbMax = maxParque;
                maxAltura = maxParque->getAltura();
            }
        }
    }
    return arbMax;
}

int ControlParques::contarEspecies(std::string nbre_parque) {
    Parque* parque = buscarParque(nbre_parque);
    if (parque != nullptr) {
        return parque->contarEspecies();
    }
    return 0;
}

int ControlParques::contarTipos() {
    VDinamico<std::string> tiposUnicos;
    for (Iterador<Parque> it = lParques.iterador(); it.fin() == false; it.avanza()) {
        VDinamico<Arbol*>& arboles = it.getdato().get_contains();
        for (unsigned int i = 0; i < arboles.tamlog(); ++i) {
            std::string tipoPlanta = arboles[i]->getTipoEspecie();
            bool encontrado = false;
            for (unsigned int j = 0; j < tiposUnicos.tamlog(); ++j) {
                if (tiposUnicos[j] == tipoPlanta) {
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado && !tipoPlanta.empty() && tipoPlanta != "No tiene especie asociada") {
                tiposUnicos.insertar(tipoPlanta);
            }
        }
    }
    return tiposUnicos.tamlog();
}

// void ControlParques::asignarEspecieParque(Especie e, Parque p) {
//     Iterador<Parque> it=lParques.iterador();
//     if (it.fin()==false) {
//         throw std::invalid_argument("ControlParques -> iterador no valido");
//     }
//     else {
//         it.getdato().insertaEspecie(&e);
//     }
// }

int ControlParques::contarEspecieParque(std::string ncomun) {
    int contador=0;
    for (Iterador<Parque> it=lParques.iterador();it.fin()==false;it.avanza()) {
        if (it.getdato().existeNbreCom(ncomun)==true) {
            contador++;
        }
    }
    return contador;
}

VDinamico<Especie*> ControlParques::listadoEspecieSubNbre(std::string cadena) {
    VDinamico<Especie*> resultado;
    for (unsigned i=0;i<vEspeciesTotales.tamlog();++i) {
        std::string nombre=vEspeciesTotales[i].get_nombre_cientifico();
        size_t pos=nombre.find(cadena);
        if (pos!=std::string::npos) {
            resultado.insertar(&vEspeciesTotales[i]);
        }
    }
    return resultado;
}

Parque* ControlParques::buscarParque(std::string nbre_parque) {
    for (Iterador<Parque> it=lParques.iterador();it.fin()==false;it.avanza()) {
        if (it.getdato().get_nbre_parque()==nbre_parque) {
            return &it.getdato();
        }
    }
    return 0;
}

Especie* ControlParques::buscarEspecie(std::string nbre_especie) {
    for (int i=0;i<vEspeciesTotales.tamlog();++i) {
        if (vEspeciesTotales[i].get_nombre_comun()==nbre_especie) {
            return &vEspeciesTotales[i];
        }
    }
    return 0;
}

VDinamico<Especie> &ControlParques::get_varieties() {
    return vEspeciesTotales;
}

ListaDEnlazada<Parque> &ControlParques::get_parks() {
    return lParques;
}

void ControlParques::eliminarParque(std::string nombre) {
    Parque *parque=buscarParque(nombre);
    if (parque==0) {
        throw std::invalid_argument("ControlParques -> no se puede eliminar el parque porque no existe");
    }
    else {
        Iterador<Parque> it=lParques.iterador();
        bool borrado=false;
        while (it.fin()==false &&borrado==false) {
            if (&it.getdato()==parque) {
                lParques.borra(it);
                borrado=true;
            }
            else {
                it.avanza();
            }
        }
        for (Iterador<Parque> it=lParques.iterador();it.fin()==false;it.avanza()) {
            if (&it.getdato()==parque) {
                lParques.borra(it);
            }
        }
    }
}
// void ControlParques::eliminarEspecie(std::string nombre) {
//     Especie *especie=buscarEspecie(nombre);
//     if (especie==0) {
//         throw std::invalid_argument("ControlParques -> no se puede eliminar la especie porque no existe");
//     }
//     else {
//         int pos;
//         for (int i=0;i<vEspeciesTotales.tamlog();++i) {
//             if (vEspeciesTotales[i].get_codigo_especie()==especie->get_codigo_especie()) {
//                 pos=i;
//             }
//         }
//         vEspeciesTotales.borrar(pos);
//         for (Iterador<Parque> it = lParques.iterador();
//          it.fin() == false; it.avanza()) {
//
//             VDinamico<Especie*>& especies = it.getdato().get_contains();
//
//             for (int i = 0; i < especies.tamlog(); ++i) {
//                 if (especies[i] == especie) {
//                     especies[i] = nullptr;
//                 }
//             }
//          }
//
//     }
// }