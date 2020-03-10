#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
class Process {       // The class
  public:             // Access specifier
    int process_id = 0; //  identificador do processo, inteiro sequencial começando em zero. 
    int total_time; //  tempo total de execução, aleatório dentro do intervalo (1, 20) segundos.
    string state [3] = {"Ready", "Running", "Terminated"}; // 1 = Ready ; 2 = Running ; 3 = Terminated
    int remaining_time; // Tempo de execução restante em segundos.
};