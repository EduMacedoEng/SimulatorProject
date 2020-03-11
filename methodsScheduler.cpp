#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <queue>

using namespace std;

class Scheduler {
public:
	queue<int> core;
	queue<int> process;
};
void print_queue(queue<int> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

queue<int> insert_process(queue<int> ready_queue, int qtd_process) {
	for (int i = 1; i <= qtd_process; i++) {
		ready_queue.push(i);
	}
	return ready_queue;
}

queue<int> delete_process(queue<int> ready_queue) {
	int size_ready_queue = ready_queue.size();
	for (int i = 0; i < size_ready_queue; i++) {
		ready_queue.pop();
	}
	return ready_queue;
}

queue<int> schedule_process(queue<int> core, queue<int> ready_queue) {
	int size_ready_queue = ready_queue.size();
	for (int i = 0; i < size_ready_queue; i++) {
		core.push(ready_queue.front());
		ready_queue.pop();
	}
	return core;
}

queue<int> deschedule_process(queue<int> core, queue<int> ready_queue) {
	int size_core = core.size();
	for (int i = 0; i < size_core; i++) {
		//cout << "Insercao na fila de cores: " << endl;
		//print_queue(core);
		int removed = core.front();
		core.pop();
		//cout << "Processo removido do core: " << removed << endl;
		int size = core.size();
		//cout << "Quantidade de processo que estao na fila dos cores: " << size << endl;
		//print_queue(ready_queue);
	}
	return core;
}

void fifo_scheduler(queue<int> core, queue<int> ready_queue) {
	cout << "Fila inicial de processos: " << endl; print_queue(ready_queue);
	core = schedule_process(core, ready_queue);
	cout << "Fila inicial de cores: " << endl; print_queue(core);
	ready_queue = delete_process(ready_queue);
	cout << "Fila final de processos: " << endl; print_queue(ready_queue);
	core = deschedule_process(core, ready_queue);
	cout << "Fila final de cores: " << endl; print_queue(core);

}

void set_scheduling_algorithm(int number, queue<int> core, queue<int> ready_queue) {
	if (number == 1) {
		fifo_scheduler(core, ready_queue);
	}
}

int main() {
	Scheduler scheduler;

	scheduler.process = insert_process(scheduler.process, 3);

	cout << "Fila inicial: " << endl; 
	print_queue(scheduler.process);
	int size = scheduler.process.size();
	cout << "Tamanho da fila: " << size << endl;

	cout << "\n\nInicio do Fifo" << endl;
	//fifo_scheduler(scheduler.core, scheduler.process);
	set_scheduling_algorithm(1, scheduler.core, scheduler.process);
}