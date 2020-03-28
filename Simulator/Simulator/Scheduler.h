#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <chrono>
#include <queue>

using namespace std;

class Scheduler
{
public:
	Scheduler();
	~Scheduler();
	
	// Objeto que internamente representa os cores de processamento da CPU por meio de uma estrutura de dados.
	// Preciso tentar usar Matriz para os cores...
	queue<int> core;

	// Fila dos processos prontos para execu��o.
	queue<int> ready_queue;

	// M�todo que imprime a fila
	void print_queue();

	// M�todo que seleciona o algoritmo de escalonamento a ser usado. 
	void set_scheduling_algorithm(int number, queue<int> core, queue<int> ready_queue);

	// M�todo principal do escalonador, que implementa sua execu��o de acordo com o algoritmo de escalonamento selecionado. 
	void run();

	// M�todo p�blico usado para inserir um novo processo na fila de aptos.
	void insert_process(queue<int> ready_queue, int qtd_processos);

	// M�todo usado para escalonar um processo e iniciar sua execu��o num core de processamento.
	void scheduler_process(queue<int> core, queue<int> ready_queue);

	// M�todo usado para remover um processo de um core de processamento.
	void descheduler_process(queue<int> core, queue<int> ready_queue);

	// M�todo que implementa o algoritmo de escalonamento FIFO
	void fifo_scheduler(queue<int> core, queue<int> ready_queue);

	// M�todo que implementa o algoritmo de escalonamento SJF
	void shortest_job_first();

	// M�todo que implementa o algoritmo de escalonamento Round Robin
	void round_robin();
};

#endif