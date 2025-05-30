#pragma once

#include "pokemonInfo.h"
#include "pokemon.h"
#include <unordered_map>
#include <iostream>

using namespace std;

class Pokedex {
    private:
        unordered_map<Pokemon, PokemonInfo, PokemonHash> pokedexMap;
    public:
        // Constructor
        Pokedex(Pokemon& pokemon, const PokemonInfo& info);
        //Sobrecarga del constructor - pasando nombre de archivo de serialización
        Pokedex(Pokemon& pokemon, const PokemonInfo& info, const string& nombreArchivo);
                
        //Serializacion y deserializacion
        void serializar(const string& nombreArchivo) const;   
        void deserializar(const string& nombreArchivo);

        void mostrar(Pokemon& pokemon) const;
        void mostrarTodos() const;
};      void agregarPokemon(const Pokemon& Nuevopokemon, const PokemonInfo& nuevoInfo);



