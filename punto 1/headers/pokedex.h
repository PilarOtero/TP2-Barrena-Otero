#pragma once

#include "pokemonInfo.h"
#include "pokemon.h"
#include <unordered_map>
#include <iostream>
#include <fstream>

using namespace std;

class Pokedex {
    private:
        unordered_map<Pokemon, PokemonInfo, PokemonHash> pokedexMap;
    public:
        // Constructores
        Pokedex();
        Pokedex(Pokemon& pokemon, const PokemonInfo& info);
        //Sobrecarga del constructor - pasando nombre de archivo de serialización
        Pokedex(Pokemon& pokemon, const PokemonInfo& info, ofstream& out);
        
        //Metodos
        void mostrar(const Pokemon& pokemon) const;
        void mostrarInfo(const Pokemon& pokemon) const;
        void mostrarTodos() const;
        void agregarPokemon(Pokemon& Nuevopokemon, const PokemonInfo& nuevoInfo, ofstream& out);

        //Serializacion y deserializacion
        void serializar(ofstream& out) const;   
        void deserializar(ifstream& in);

        //Destructor
        ~Pokedex() = default;
};      




