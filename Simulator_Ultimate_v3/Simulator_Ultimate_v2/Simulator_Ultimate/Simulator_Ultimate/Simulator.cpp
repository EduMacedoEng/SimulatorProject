#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <conio.h>
#include <chrono>
#include "windows.h"
#include "Simulator.h"
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    Simulator* sim = new Simulator();
    
    int qtd_processos, qtd_cores, opcao, quantum = 0;

    chrono::time_point<chrono::system_clock> start, end;

    cout << "Qual a quantidade de processos: ";
    cin >> qtd_processos;
    cout << "\nQual a quantidade de cores: ";
    cin >> qtd_cores;
    cout << "\nQual alg voce deseja selecionar ?" << endl;
    cout << "1 - Fifo" << "\t\t" << "2 - SJF" << "\t\t" << "3 - Round Robin" << endl;
    cout << "Qual a opcao: ";
    cin >> opcao;
    if (opcao == 3) {
        cout << "Qual o valor do quantum: ";
        cin >> quantum;
    }

    //thread th1(&Simulator::run, &sim, opcao,qtd_cores,qtd_processos, quantum);
    sim->run(opcao, qtd_cores, qtd_processos, quantum);
    //th1.join();
    //th1.join();

    _getch(); 
}