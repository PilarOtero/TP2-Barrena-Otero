#include "../headers/pokedex.h"

//Constructores
Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info) {
    pokedexMap[pokemon] = info;
}

Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info, const string& nombreArchivo) {
    pokedexMap[pokemon] = info;
    serializar(nombreArchivo);
}

//Metodo para mostrar la info del Pokemon
void Pokedex::mostrar(Pokemon& pokemon) const {
    auto it = pokedexMap.find(pokemon);
    if (it != pokedexMap.end()) {
        cout << "Pokemon(" << pokemon.getNombre() << "," << pokemon.getExperiencia() << ")" << endl;
    }
    else {
        cout << "Pokemon no encontrado en la Pokedex" << endl;
    }
}
