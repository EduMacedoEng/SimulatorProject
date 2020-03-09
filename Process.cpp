#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Process {       // The class
  public:             // Access specifier
    int process_id = 0; //  identificador do processo, inteiro sequencial começando em zero. 
    int total_time = rand() % 20; //  tempo total de execução, aleatório dentro do intervalo (1, 20) segundos.
    int state [3] = {1, 2, 3}; // 1 = Ready ; 2 = Running ; 3 = Terminated
    int remaining_time = total_time; // Tempo de execução restante em segundos.
};