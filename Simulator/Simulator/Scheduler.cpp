#include "Scheduler.h"
#include "Kernel.h"
#include "Process.h"

Kernel kernel;

Scheduler::Scheduler()
{

}

Scheduler::~Scheduler()
{

}

// M�todo que imprime a fila
void print_queue(queue<int> q) {

	while (!q.empty()) {

		cout << q.front() << " ";

		q.pop();

	}

	cout << endl;

}

// M�todo que seleciona o algoritmo de escalonamento a ser usado
void Scheduler::set_scheduling_algorithm(int number, queue<int> core, queue<int> ready_queue) {

	if (number == 1) {

		fifo_scheduler(core, ready_queue);

	}

}

// M�todo principal do escalonador, que implementa sua execu��o de acordo com o algoritmo de escalonamento selecionado
void Scheduler::run() {

}

// M�todo p�blico usado para inserir um novo processo na fila de aptos. 
void Scheduler::insert_process(queue<int> ready_queue, int qtd_processos) {

	for (int i = 0; i < qtd_processos; i++) {

		ready_queue.push(i);

	}

}

// M�todo usado para escalonar um processo e iniciar sua execu��o num core de processamento. 
void Scheduler::scheduler_process(queue<int> core, queue<int> ready_queue) {

	int size_ready_queue = ready_queue.size();

	for (int i = 0; i < size_ready_queue; i++) {

		core.push(ready_queue.front());

		ready_queue.pop();

	}

}

// M�todo usado para remover um processo de um core de processamento.
void Scheduler::descheduler_process(queue<int> core, queue<int> ready_queue) {

	int size_ready_queue = core.size();

	for (int i = 0; i < size_ready_queue; i++) {

		int removed = core.front();

		core.pop();

		int size = core.size();

	}

}

// M�todo que implementa o algoritmo de escalonamento FIFO
void Scheduler::fifo_scheduler(queue<int> core, queue<int> ready_queue) {

	Scheduler::scheduler_process(core, ready_queue);

	kernel.kill_process(ready_queue);

	Scheduler::descheduler_process(core, ready_queue);

}

// M�todo que implementa o algoritmo de escalonamento SJF
void Scheduler::shortest_job_first() {

}

// M�todo que implementa o algoritmo de escalonamento Round Robin
void Scheduler::round_robin() {

}