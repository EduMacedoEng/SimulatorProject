#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
class Process {       // The class
  public:             // Access specifier
    int process_id = 0; // Identificador do processo, inteiro sequencial começando em zero. 
    int bt; // Burst time variable
    int art; // Arrival time variable
    int total_time; //  tempo total de execução, aleatório dentro do intervalo (1, 20) segundos.
    string state [3] = {"Ready", "Running", "Terminated"}; // 0 = Ready ; 1 = Running ; 2 = Terminated
    int remaining_time; // Tempo de execução restante em segundos.
};