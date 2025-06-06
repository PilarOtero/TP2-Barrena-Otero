#include "../include/Hangar.h"
#include <string>
#include <memory>
#include <chrono>

void Hangar::despegar(int dron){
    int der = (dron - 1 + CANTDRONES) % CANTDRONES; //EXPLICARRRRRRRR FORMULAS
    int izq = dron;

    if (dron==5) cout << "aaaaaaa" << endl;
    
    {
    lock_guard<mutex> lock(habilitado);
    cout << "Dron " << dron << " esperando para despegar..." << endl;
    }

    if (dron==5) cout << "aaaaaaa" << endl;

    unique_lock<mutex> lock_der(posiciones[der], defer_lock); //usamos defer_lock para hacer manualmente el bloqueo del mutex mas adelante 
    unique_lock<mutex> lock_izq(posiciones[izq], defer_lock); 
    lock(lock_der, lock_izq); //evita deadlock 

    
    
    {
    lock_guard<mutex> lock(habilitado);
    cout << "Dron " << dron << " despegando..."<< endl;
    }

    this_thread::sleep_for(chrono::seconds(5)); //espera de 5 segundos hasta alcanzar los 10 metros
    
    {
    lock_guard<mutex> lock(habilitado);
    cout << "Dron" << dron << " alcanzó altura de 10 metros" << endl; 
    }
}

void Hangar::simularDespegues() {
    for(int i = 0; i < CANTDRONES; ++i){
        drones.emplace_back(&Hangar::despegar, this, i + 1);
    }
    for(auto& dron : drones){
        dron.join();
    }
}

