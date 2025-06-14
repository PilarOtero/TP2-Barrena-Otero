#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <string>
#include <chrono>


const int CANT_SENSORES = 3;
const int CANT_ROBOTS = 3;
const int CANT_TAREAS = 3;

using namespace std;

struct Tarea {
    int idSensor;
    int idTarea;
    string descripcion;
};

queue<Tarea> tareas;
mutex mtx;
// Mutex para la impresion de mensajes en consola sin superposición
mutex mtxImpresion;
condition_variable cv;
//Sensores que terminaron de reportar sus tareas
bool terminado = false; 
int tareasCompletadas = 0;

void sensor(int idSensorTarea) {
    for(int i = 1; i <= CANT_TAREAS; ++i){
        //Tiempo de demora de generacion de una tarea
        this_thread::sleep_for(chrono::milliseconds(175));
        
        Tarea tareaReportada;
        tareaReportada.idSensor = idSensorTarea;
        tareaReportada.idTarea = i + idSensorTarea * 10;
        tareaReportada.descripcion = "Tarea " + to_string(tareaReportada.idTarea);
        
        {
        unique_lock<mutex> lg(mtx); 
        //Se agrega la tarea a la cola de tareas  
        tareas.push(tareaReportada );
        
        //Impresion del mensaje dentro del mismo scope para que no salga antes de que un robot pueda procesar la tarea
        lock_guard<mutex> lock(mtxImpresion);
        cout << "[SENSOR " << idSensorTarea << "] reporta " << tareaReportada.descripcion << endl;
        }
        //Notificar a todos los robots que hay una nueva tarea
        cv.notify_all();
    }
    {
        unique_lock<mutex> lg(mtx);
        tareasCompletadas ++;
        if (tareasCompletadas == CANT_SENSORES) {
            terminado = true;
            //Se notifica a los robots que no hay mas tareas a realizar
           cv.notify_all(); 
        }
    }
}

void robot(int idRobot) {
    while(true) {
        unique_lock<mutex> ul(mtx);
        //Se espera a que haya tareas pendientes a procesar
        cv.wait(ul, [] {return !tareas.empty() || terminado; });

        if (!tareas.empty()) {
            Tarea tarea = tareas.front();
            tareas.pop();
            ul.unlock();

            {
            lock_guard<mutex> lock(mtxImpresion);
            cout << "[ROBOT " << idRobot << "] procesando " << tarea.descripcion << endl;
            }
            //Tiempo de procesamiento del robot de la tarea
            this_thread::sleep_for(chrono::milliseconds(250)); 
        }
        else if(terminado) {
            ul.unlock();
            {
            lock_guard<mutex> lock(mtxImpresion);
            cout << "[ROBOT " << idRobot << " TERMINO DE PROCESAR SUS TAREAS]" << endl;
            }
        break;
        }
    }
}


int main(){
    vector<thread> robots;
    for (int i = 0; i < CANT_ROBOTS; i++){
        //emplace_back agrega un nuevo elemento al vector de robots 
        robots.emplace_back(robot, i + 1);
    }

    vector<thread> sensores;
    for (int i = 0; i < CANT_SENSORES; ++i){
        sensores.emplace_back(sensor, i + 1);
    }
    for (auto& s : sensores) s.join();
    for (auto& r : robots) r.join();

    cout << "Todos los robots han terminado de procesar las tareas." << endl;
    return 0;
}


