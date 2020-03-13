#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <chrono>
#include <queue>

using namespace std;

// classe que representa um processo e seus atributos, mais especificamente
class Process {
public:
	// Identificador do process, inteiro sequencial começando em zero
	int process_id = 0;

	// Tempo de execução para o algoritmo de escalonamento
	int quantum;

	// Tempo total de execução, aleatório dentro do intervalo (1, 20)
	int total_time;

	// Estado do processo: "Ready", "Running" ou "Terminated"
	string state[3] = { "Ready", "Running", "Terminated" };

	// Tempo de execução restante em segundos
	int remaining_time;

	// Método que gera randomicamente números em um intervalo de tempo
	int randRange(int low, int high);

};