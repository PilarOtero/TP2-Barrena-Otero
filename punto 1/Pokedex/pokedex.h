#pragma once

#include "pokemonInfo.h"
#include <unordered_map>

using namespace std;

class Pokedex {
    private:
        unordered_map<Pokemon, PokemonInfo> pokedexMap;
    public:
        // Constructor
        Pokedex(Pokemon* pokemon, const PokemonInfo& info);
        //Sobrecarga del constructor - pasando nombre de archivo de serialización
        Pokedex(Pokemon* pokemon, const PokemonInfo& info, const string& nombreArchivo);
        
        // Getters
        Pokemon* getPokemon() const;
        PokemonInfo getInfo() const;
        
        //PREGUNTAR SEGUNDO METODO MOSTRAR
        //Serializacion
        void serializar(const string& nombreArchivo) const;   

        void mostrar(Pokemon& pokemon) const;
        void mostrarTodos() const;
};



