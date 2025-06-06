#include "../include/Hangar.h"
#include <string>
#include <memory>
#include <chrono>

void logMessage(const string& mensaje){
    lock_guard<mutex> lock(LogMutex);
}
void Hangar::despegar(int dron){
    int der = (dron - 1 + CANTDRONES) % CANTDRONES; //EXPLICARRRRRRRR FORMULAS
    int izq = dron;
    try{
        logMessage("Dron " + to_string(dron) + " esperando para despegar...");
        unique_lock<mutex> lock_der(posiciones[der], defer_lock); //usamos defer_lock para hacer manualmente el bloqueo del mutex mas adelante 
        unique_lock<mutex> lock_izq(posiciones[izq], defer_lock);
        lock(lock_der, lock_izq); //evita deadlock 
        logMessage("Dron " + to_string(dron) + " despegando...");
        this_thread::sleep_for(chrono::sleep(5)); //espera de 5 segundos hasta alcanzar los 10 metros
        logMessage("Dron" + to_string(dron) + " alcanzó altura de 10 metros"); 
    }
}
