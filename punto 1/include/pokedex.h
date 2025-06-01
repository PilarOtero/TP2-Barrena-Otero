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
        string fileName;
    public:
        // Constructores
        Pokedex();
        //Sobrecarga del constructor - pasando nombre de archivo de serialización
        Pokedex(const string& fileNamePokedex);
        
        //Metodos
        void mostrar(const Pokemon& pokemon) const;
        void mostrarInfo(const Pokemon& pokemon) const;
        void mostrarTodos() const;
        void agregarPokemon(Pokemon& Nuevopokemon, const PokemonInfo& nuevoInfo);
        void eliminarPokemon(const string& nombrePokemon);

        //Serializacion y deserializacion
        void serializar() const;   
        void deserializar();

        //Destructor
        ~Pokedex() = default;
};      




