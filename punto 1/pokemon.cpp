#include "pokemon.h"

//Constructor mediante lista de inicialización
Pokemon::Pokemon(string nombrePokemon, int experienciaPokemon): nombre(nombrePokemon), experiencia(experienciaPokemon) {};

//Getters
string Pokemon::getNombre() const { return nombre; }
int Pokemon::getExperiencia() const { return experiencia; }

//Setters
void Pokemon:: setExperiencia(int nuevaExperiencia) {
    if (experiencia < 0 && nuevaExperiencia >= 0) experiencia = nuevaExperiencia;
}
