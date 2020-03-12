#include<iostream>
#include <stdio.h>
#include <queue>
#include "Scheduler.h" // Transformar o arquivo Scheduler para .h, pois desta forma eu consigo importar para o main.

using namespace std;

int main() {
    Scheduler scheduler;

    int num_cores;
    int num_processos;
    int num_alg;
    int Matriz_Fifo[64][4];

    cout << "****************************************" << endl;
    cout << "************ Seja bem-vindo ************" << endl;
    cout << "****************************************" << endl;

    cout << "\nDigite a quantidade de cores: ";
    cin >> num_cores;

    cout << "\nDigite a quantidade de processos: ";
    cin >> num_processos;

    cout << "\n****************************************" << endl;
    cout << "Escolha o algoritmo que deseja executar" << endl;
    cout << "****************************************" << endl;
    cout << "1 - FIFO" << endl;
    cout << "2 - SJF" << endl;
    cout << "3 - ROUND ROBIN" << endl;
    cout << "****************************************" << endl;
    cout << "Digite o codigo do algoritmo: ";
    cin >> num_alg;
    cout << "****************************************" << endl;

    cout << "Id do processo\t\tTempo Total\t\tStatus\t\tTempo Restante\n";
    cout << "________________________________________________________________________________________\n";
    scheduler.insert_process_fifo(Matriz_Fifo, num_processos);

    scheduler.print_matriz(Matriz_Fifo, num_processos);
}