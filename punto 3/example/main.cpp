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
condition_variable cv;
bool terminado = false; //sensores que terminaron de rportar sus tareas
int tareasCompletadas = 0;

void sensor(int idSensorTarea) {
    for(int i = 1; i <= CANT_TAREAS; ++i){
        //Tiempo de demora de generacion de una tarea
        this_thread::sleep_for(chrono::milliseconds(175));
        
        Tarea tareaReportada;
        tareaReportada.idSensor = idSensorTarea;
        tareaReportada.idTarea = i;
        tareaReportada.descripcion = "Tarea " + to_string(i);
        
        {
        unique_lock<mutex> lg(mtx);   
        tareas.push(tareaReportada);
        cout << "[SENSOR " << idSensorTarea << "] reporta " << tareaReportada.descripcion << endl;
        }  
        //Notificar a los robots que hay una nueva tarea
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
            cout << "[ROBOT " << idRobot << "] procesando " << tarea.descripcion << endl;
            //Tiempo de procesamiento del robot de la tarea
            this_thread::sleep_for(chrono::milliseconds(250)); 
        }
        else if(terminado) {
            cout << "[ROBOT " << idRobot << " TERMINO DE PROCESAR SUS TAREAS]" << endl;
            break;
        }
    }
}


int main(){
    vector<thread> robots;
    for (int i = 0; i < CANT_ROBOTS; i++){
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


