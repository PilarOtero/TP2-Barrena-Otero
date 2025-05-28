#include "pokedex.h"

//Constructores
Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info) {
    pokedexMap[pokemon] = info;
}

Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info, const string& nombreArchivo) {
    pokedexMap[pokemon] = info;
}

//Getters
