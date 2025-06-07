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
        //Nombre del archivo para la carga y descarga de la información 
        string fileName;
    public:
        //Constructores
        Pokedex();
        //Sobrecarga del constructor - pasando nombre de archivo
        Pokedex(const string& fileNamePokedex);
        
        //Metodos
        void mostrar(const Pokemon& pokemon) const;
        void mostrarInfo(const Pokemon& pokemon) const;
        void mostrarTodos() const;
        void agregarPokemon(Pokemon& Nuevopokemon, const PokemonInfo& nuevoInfo);

        //Carga y descarga de información al archivo
        void cargarInfo() const;   
        void descargarInfo();

        //Destructor
        ~Pokedex() = default;
};      




