#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <chrono>

using namespace std;

class Simulator
{
public:
    //Construtor
    Simulator();


    //int** create_random_process(int qtd_process);
    void create_random_process();
    //int** batch_process_init(int qtd_process);
    void batch_process_init(int qtd_processos);
    //void printMatrizProcess(int** arr, int qtd_process);
    //int** delete_matriz(int** matriz, int i, int j, int qtd_processos);
    void run(int qtd_process);

    int processor_cores_number;
    int quantum;
};