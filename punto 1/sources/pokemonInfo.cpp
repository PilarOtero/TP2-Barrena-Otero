#include "../headers/pokemonInfo.h"
#include <fstream>

// Constructor mediante lista de inicialización
PokemonInfo::PokemonInfo(const string& tipoPokemon, const string& descripcionPokemon, map<string, int>& ataquesPorNivel, vector<int>& experienciaNivel): tipo(tipoPokemon), descripcion(descripcionPokemon), ataquesDisponiblesPorNivel(ataquesPorNivel), experienciaProximoNivel(experienciaNivel) {};

// Getters
string PokemonInfo::getTipo() const { return tipo; }
string PokemonInfo::getDescripcion() const { return descripcion; }
map<string, int> PokemonInfo::getAtaquesDisponiblesPorNivel() const { return ataquesDisponiblesPorNivel; }
vector<int> PokemonInfo::getExperienciaProximoNivel() const { return experienciaProximoNivel; }

// Setters
void PokemonInfo:: setTipo(string& nuevoTipo) {
    tipo = nuevoTipo;
}

//Serializacion
void PokemonInfo::serializar(const string& path) const {
    ifstream out(path, ios:: binary);
    if (out.is_open()){
        continue; // Implementar la lógica de serialización aquí
        out.close();
    }
}