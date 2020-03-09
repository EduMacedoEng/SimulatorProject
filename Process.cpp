#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int range_time(int low, int high){
      return rand() % (high - low) + low;
    }
class Process {       // The class
  public:             // Access specifier
    int process_id = 0; //  identificador do processo, inteiro sequencial começando em zero. 
    int total_time = range_time(1,20); //  tempo total de execução, aleatório dentro do intervalo (1, 20) segundos.
    int state [3] = {1, 2, 3}; // 1 = Ready ; 2 = Running ; 3 = Terminated
    int remaining_time = 0; // Tempo de execução restante em segundos.
};