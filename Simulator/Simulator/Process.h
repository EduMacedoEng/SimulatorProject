#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <chrono>
#include <queue>
#include <string.h>

using namespace std;

class Process
{
public:
	//Construtores
	Process();
	//Process(int total_time,int remaining_time,int process_id, int quantum);
	//Process(int total_time, int remaining_time, int process_id);
	~Process();

	// Identificador do process, inteiro sequencial começando em zero
	int process_id = 0;
	//Process arrayProcess[];
	// Tempo de execução para o algoritmo de escalonamento
	int quantum;

	// Tempo total de execução, aleatório dentro do intervalo (1, 20)
	int total_time;

	// Estado do processo: "Ready", "Running" ou "Terminated"
	string state[3] = { "Ready" ,"Running", "Terminated" };

	// Tempo de execução restante em segundos
	int remaining_time;

	// Método que gera randomicamente números em um intervalo de tempo
	int randRange(int low, int high);

	// Mostra o processo
	void showProcess();
};