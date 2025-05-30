#include "../headers/pokedex.h"

//Constructores
Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info) {
    pokedexMap[pokemon] = info;
}

Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info, ofstream& out) {
    pokedexMap[pokemon] = info;
    serializar(out);
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

//Aca habria que ver si el pokemon esta o no en el mapa
void Pokedex:: agregarPokemon(Pokemon& NuevoPokemon, const PokemonInfo& nuevoinfo, ofstream& out) {
    if (pokedexMap.find(NuevoPokemon) == pokedexMap.end()) {
        pokedexMap.insert({NuevoPokemon, nuevoinfo});
        serializar(out);
    }
    else {
        cout << "El Pokemon ya pertenece a Pokedex" << endl;
    }
}

//Serializacion
void Pokedex:: serializar(ofstream& out) const {
    size_t size = pokedexMap.size();
    //Guardo el tamaño del mapa
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& par: pokedexMap){
        //Serializacion del Pokemon
        par.first.serializar(out);
        //Serializacion de la info
        par.second.serializar(out);
    }
}

//Deserializacion
void Pokedex:: deserializar(ifstream& in){
    size_t size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    for(size_t it = 0; it < size; ++it){
        Pokemon poke("", 0);
        PokemonInfo info;

        //Deserializacion del Pokemon
        poke.deserializar(in);
        //Deserializacion de la info
        infodeserializar(in);
        //Agrego el Pokemon y su info al mapa
        pokedexMap[poke] = info;
    }
}
