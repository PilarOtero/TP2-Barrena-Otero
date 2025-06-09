#include "../include/Hangar.h"
#include <string>
#include <memory>
#include <chrono>

void Hangar::despegar(int dron){
    //Zona derecha del dron - entre él y el de su izquierda
    int der = (dron - 1 + CANTDRONES) % CANTDRONES; 
    //Zona izquierda del dron - entre él y el de su derecha
    int izq = dron;
    
    {
    lock_guard<mutex> lock(habilitado);
    cout << "Dron " << dron << " esperando para despegar..." << endl;
    }

    //defer_lock para hacer manualmente el bloqueo del mutex más adelante 
    unique_lock<mutex> lock_der(posiciones[der], defer_lock); 
    unique_lock<mutex> lock_izq(posiciones[izq], defer_lock); 
    //Bloqueamos ambos threads para evitar deadlock
    lock(lock_der, lock_izq); 
    
    {
    lock_guard<mutex> lock(habilitado);
    cout << "Dron " << dron << " despegando..."<< endl;
    }

    //Espera de 5 segundos y alcanza los 10 metros
    this_thread::sleep_for(chrono::seconds(5)); 
    
    {
    lock_guard<mutex> lock(habilitado);
    cout << "Dron " << dron << " alcanzó altura de 10 metros" << endl; 
    }
}

void Hangar::simularDespegues() {
    //Despegue de los drones
    for(int i = 0; i < CANTDRONES; ++i){
        drones.emplace_back(&Hangar::despegar, this, i);
    }
    //Unión de los threads
    for(auto& dron : drones){
        dron.join();
    }
}

