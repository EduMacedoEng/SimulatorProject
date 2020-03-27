#include "Process.h"
#include "Kernel.h"
#include "Scheduler.h"
#include "Simulator.h"

using namespace std;

int main() {
    Process process;
    Kernel kernel;
    Scheduler scheduler;
    Simulator simulator;

    int cores = 0;
    int processos = 0;
    int algId = 0;


    cout << "Quantos cores voce deseja criar? ";
    cin >> simulator.processor_cores_number;
    cout << "\nQuantos processos voce deseja criar?";
    cin >> processos;
    cout << "\nDigite o codigo de um dos algoritmos abaixo." << endl;
    cout << "1 - FIFO"
        << "\n2 - SJF"
        << "\n3 - Round Robin"
        << endl;
    cout << "Opçao: ";
    cin >> simulator.scheduling_algorithm;

    return 0;
}