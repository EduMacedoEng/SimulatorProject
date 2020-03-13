#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <chrono>
#include <queue>

using namespace std;

// classe que implementa o escalonador de processos, suas estruturas de dados e algoritmos
class Scheduler {
public:
	// Objeto que internamente representa os cores de processamento da CPU por meio de uma estrutura de dados.
	// Preciso tentar usar Matriz para os cores...
	queue<int> core;

	// Fila dos processos prontos para execução.
	queue<int> ready_queue;

	// Método que imprime a fila
	void print_queue();

	// Método que seleciona o algoritmo de escalonamento a ser usado. 
	void set_scheduling_algorithm(int number, queue<int> core, queue<int> ready_queue);

	// Método principal do escalonador, que implementa sua execução de acordo com o algoritmo de escalonamento selecionado. 
	void run(); 

	// Método público usado para inserir um novo processo na fila de aptos.
	void insert_process(queue<int> ready_queue, int qtd_processos); 

	// Método usado para escalonar um processo e iniciar sua execução num core de processamento.
	void scheduler_process(queue<int> core, queue<int> ready_queue); 

	// Método usado para remover um processo de um core de processamento.
	void descheduler_process(queue<int> core, queue<int> ready_queue); 

	// Método que implementa o algoritmo de escalonamento FIFO
	void fifo_scheduler(queue<int> core, queue<int> ready_queue);

	// Método que implementa o algoritmo de escalonamento SJF
	void shortest_job_first();

	// Método que implementa o algoritmo de escalonamento Round Robin
	void round_robin();
};