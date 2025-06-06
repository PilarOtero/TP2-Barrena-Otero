#include "../include/pokedex.h"

//Constructores
Pokedex::Pokedex() {};

Pokedex::Pokedex(const string& fileNamePokedex): fileName("bin/" + fileNamePokedex) {};

//Metodo para mostrar el nombre y tipo del Pokemon
void Pokedex::mostrar(const Pokemon& pokemon) const {
    auto it = pokedexMap.find(pokemon);
    if (it != pokedexMap.end()) {
        cout << "NOMBRE -> " << pokemon.getNombre() << "\nEXPERIENCIA -> " << pokemon.getExperiencia() << endl;
    }
    else {
        cout << "Pokemon desconocido!" << endl;
    }
}

//Metodo para mostrar la informacion del Pokemon
void Pokedex::mostrarInfo(const Pokemon& pokemon) const {
    auto it = pokedexMap.find(pokemon);
    if (it != pokedexMap.end()) {
        const PokemonInfo& info = it->second;
        cout << "TIPO -> " << info.getTipo() << "\nDESCRIPCION -> " << info.getDescripcion() << "\n";
        
        const auto& ataques = info.getAtaquesDisponiblesPorNivel();
        cout << "ATAQUES " << endl;
        for (auto it = ataques.begin(); it!= ataques.end(); ++it) {
            cout << "- "<< it->first << " -> Puntaje de daño: " << it->second << endl;

        }

        const auto& experiencia = info.getExperienciaProximoNivel();
        cout << "EXPERIENCIA PROXIMO NIVEL " << endl;
        for (int i = 0; i < experiencia.size(); i++){
            cout << "- " << experiencia[i] << endl;
        }
    }

    else {
        cout << "Pokemon desconocido!" << endl;
    }
}

//Aca habria que ver si el pokemon esta o no en el mapa
void Pokedex:: agregarPokemon(Pokemon& NuevoPokemon, const PokemonInfo& nuevoinfo) {
    if (pokedexMap.find(NuevoPokemon) == pokedexMap.end()) {
        pokedexMap.insert({NuevoPokemon, nuevoinfo});
        if (!fileName.empty()){
            //Se agrega la nueva informacion al archivo
            cout << "Guardando a " << NuevoPokemon.getNombre() << " en el archivo " << fileName << "..." << endl;
            cout << "---------------------------------------------------------------" << endl;
            cargarInfo();
        }
    }
    else {
        cout << "El Pokemon ya pertenece a Pokedex" << endl;
    }
}

//Serializacion
void Pokedex::cargarInfo() const {
    ofstream out(fileName, ios::binary);
    if (!out.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    //Guardo el tamaño del mapa
    size_t size = pokedexMap.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& par: pokedexMap){
        //Serializacion del Pokemon
        par.first.serializar(out);
        //Serializacion de la info
        par.second.serializar(out);
    }
    out.close();
}

//Deserializacion
void Pokedex::descargarInfo(){
    ifstream in(fileName, ios::binary);
    if (!in.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    //Limpiamos antes de cargar la informacion
    pokedexMap.clear();

    size_t size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    for(int i = 0; i < size; ++i){
        Pokemon pokemon;
        PokemonInfo info;
        //Deserializacion del Pokemon
        pokemon.deserializar(in);
        //Deserializacion de la info
        info.deserializar(in);
        //Agrego el Pokemon y su info al mapa
        pokedexMap[pokemon] = info;
    }
    in.close();
}

//Metodo para mostrar todos los Pokemones
void Pokedex::mostrarTodos() const {
    if (pokedexMap.empty()) {
        cout << "La Pokedex esta vacia" << endl;
        return;
    }

    for (const auto& par:pokedexMap){
        const Pokemon& pokemon = par.first;
        mostrar(pokemon);
        mostrarInfo(pokemon);
        cout << "---------------------------------------------------------------" << endl;
    }
}
