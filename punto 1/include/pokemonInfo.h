#pragma once

#include "pokemon.h"
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class PokemonInfo {
    private:
        string tipo, descripcion;
        map<string, int> ataquesDisponiblesPorNivel;
        vector<int> experienciaProximoNivel;
    public:
        //Constructores
        PokemonInfo();
        PokemonInfo(const string& tipoPokemon, const string& descripcionPokemon, map<string, int>& ataquesPorNivel, vector<int>& experienciaNivelPoke);
        
        //Getters
        string getTipo() const;
        string getDescripcion() const;
        map<string, int> getAtaquesDisponiblesPorNivel() const;
        vector<int> getExperienciaProximoNivel() const;        
        
        //Setters
        void setTipo(const string& nuevoTipo);

        //Serializacion y deserializacion
        void cargarInfo(ofstream& out) const;   
        void descargarInfo(ifstream& in);
};