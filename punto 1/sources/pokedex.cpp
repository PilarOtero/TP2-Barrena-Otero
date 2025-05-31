#include "../headers/pokedex.h"

//Constructores
Pokedex::Pokedex() {};

Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info) {
    pokedexMap[pokemon] = info;
}

Pokedex::Pokedex(Pokemon& pokemon, const PokemonInfo& info, ofstream& out) {
    pokedexMap[pokemon] = info;
    serializar(out);
}

//Metodo para mostrar el nombre y tipo del Pokemon
void Pokedex::mostrar(const Pokemon& pokemon) const {
    auto it = pokedexMap.find(pokemon);
    if (it != pokedexMap.end()) {
        cout << "Pokemon(\"" << pokemon.getNombre() << "\", " << pokemon.getExperiencia() << ")" << endl;
    }
    else {
        cout << "Pokemon no encontrado en la Pokedex." << endl;
    }
}

//Metodo para mostrar la informacion del Pokemon
void Pokedex::mostrarInfo(const Pokemon& pokemon) const {
    auto it = pokedexMap.find(pokemon);
    if (it != pokedexMap.end()) {
        const PokemonInfo& info = it->second;
        cout << "PokemonInfo(\"" << info.getTipo() << "\",\"" << info.getDescripcion() << "\"";
        
        const auto& ataques = info.getAtaquesDisponiblesPorNivel();
        cout << ", {";
        for (auto it = ataques.begin(); it!= ataques.end(); ++it) {
            cout << "{\"" << it->first << "\",\"" << it->second << "}";
            //Si no se trata del ultimo elemento del map, agrega la coma
            if (next(it) != ataques.end()) cout << ",";
        }
        cout << "}, {";

        const auto& experiencia = info.getExperienciaProximoNivel();
        for (size_t i = 0; i < experiencia.size(); i++){
            cout << experiencia[i];
            if (i != experiencia.size() - 1) cout << ", ";
        }
        cout << "})" << endl;
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
        Pokemon poke;
        PokemonInfo info;

        //Deserializacion del Pokemon
        poke.deserializar(in);
        //Deserializacion de la info
        info.deserializar(in);
        //Agrego el Pokemon y su info al mapa
        pokedexMap[poke] = info;
    }
}

//Metodo para mostrar todos los Pokemones
void Pokedex::mostrarTodos() const {
    if (pokedexMap.empty()) {
        cout << "La Pokedex vacia" << endl;
        return;
    }

    int it = 1;
    for (const auto& par:pokedexMap){
        cout << "Caso " << it << ": ";
        const Pokemon& pokemon = par.first;
        mostrar(pokemon);
        mostrarInfo(pokemon);
        it++;
    }
}
