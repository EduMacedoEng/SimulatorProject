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

// Método que imprime a fila
void print_queue(queue<int> q) {

	while (!q.empty()) {

		cout << q.front() << " ";

		q.pop();

	}

	cout << endl;

}

// Método que seleciona o algoritmo de escalonamento a ser usado
void Scheduler::set_scheduling_algorithm(int number, queue<int> core, queue<int> ready_queue) {

	if (number == 1) {

		fifo_scheduler(core, ready_queue);

	}

}

// Método principal do escalonador, que implementa sua execução de acordo com o algoritmo de escalonamento selecionado
void Scheduler::run() {

}

// Método público usado para inserir um novo processo na fila de aptos. 
void Scheduler::insert_process(queue<int> ready_queue, int qtd_processos) {

	for (int i = 0; i < qtd_processos; i++) {

		ready_queue.push(i);

	}

}

// Método usado para escalonar um processo e iniciar sua execução num core de processamento. 
void Scheduler::scheduler_process(queue<int> core, queue<int> ready_queue) {

	int size_ready_queue = ready_queue.size();

	for (int i = 0; i < size_ready_queue; i++) {

		core.push(ready_queue.front());

		ready_queue.pop();

	}

}

// Método usado para remover um processo de um core de processamento.
void Scheduler::descheduler_process(queue<int> core, queue<int> ready_queue) {

	int size_ready_queue = core.size();

	for (int i = 0; i < size_ready_queue; i++) {

		int removed = core.front();

		core.pop();

		int size = core.size();

	}

}

// Método que implementa o algoritmo de escalonamento FIFO
void Scheduler::fifo_scheduler(queue<int> core, queue<int> ready_queue) {

	Scheduler::scheduler_process(core, ready_queue);

	kernel.kill_process(ready_queue);

	Scheduler::descheduler_process(core, ready_queue);

}

// Método que implementa o algoritmo de escalonamento SJF
void Scheduler::shortest_job_first() {

}

// Método que implementa o algoritmo de escalonamento Round Robin
void Scheduler::round_robin() {

}