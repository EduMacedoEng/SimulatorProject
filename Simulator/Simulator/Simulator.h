#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "Kernel.h"
#include <time.h>
#include <stdio.h>
#include <chrono>

using namespace std;

class Simulator
{
public:
    //Construtor
    Simulator();


    int** create_random_process(int qtd_process);
    int** batch_process_init(int qtd_process);
    void run(int qtd_process);


    int processor_cores_number;
    int quantum;
};