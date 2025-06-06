#include "../include/Hangar.h"
#include <string>
#include <memory>
#include <chrono>

void Hangar::despegar(int dron){
    habilitado.lock();
    int der = (dron - 1 + CANTDRONES) % CANTDRONES; //EXPLICARRRRRRRR FORMULAS
    int izq = dron;
    cout << "Dron " << dron << " esperando para despegar...";
    unique_lock<mutex> lock_der(posiciones[der], defer_lock); //usamos defer_lock para hacer manualmente el bloqueo del mutex mas adelante 
    unique_lock<mutex> lock_izq(posiciones[izq], defer_lock);
    lock(lock_der, lock_izq); //evita deadlock 
    cout << "Dron " << dron << " despegando...";
    this_thread::sleep_for(chrono::seconds(5)); //espera de 5 segundos hasta alcanzar los 10 metros
    cout << "Dron" << dron << " alcanzó altura de 10 metros"; 
    
}

void Hangar::simularDespegues() {
    for(int i = 0; i < CANTDRONES; i++){
        drones.emplace_back(despegar, posiciones[i % 5], i + 1);
        for(auto& dron : drones){
            dron.join();
        }
    }
}
