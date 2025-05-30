#pragma once

#include "pokemon.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class PokemonInfo {
    private:
        string tipo, descripcion;
        map<string, int> ataquesDisponiblesPorNivel;
        vector<int> experienciaProximoNivel; //o set
    public:
        //Constructor
        PokemonInfo(const string& tipoPokemon, const string& descripcionPokemon, map<string, int>& ataquesPorNivel, vector<int>& experienciaNivel);
        
        //Getters
        string getTipo() const;
        string getDescripcion() const;
        map<string, int> getAtaquesDisponiblesPorNivel() const;
        vector<int> getExperienciaProximoNivel() const;        
        
        //Setters
        void setTipo(string& nuevoTipo);

        //Serializacion y deserializacion
        void serializar(ofstream& out) const;   
        void deserializar(ifstream& in);

};