#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <queue>
using namespace std;

void print_queue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// método que seleciona o algoritmo de escalonamento a ser usado.
void set_scheduling_algorithm() {

}

//método principal do escalonador, que implementa sua execução de acordo com o algoritmo de escalonamento selecionado. 
void run (){

}

// método público usado para inserir um novo processo na fila de aptos.
queue<int> insert_process(queue<int> ready_queue, int qtd_process) {
	for (int i = 1; i <= qtd_process; i++) {
		ready_queue.push(i);
	}
	return ready_queue;
}

// método público usado para deletar um novo processo na fila de aptos.
queue<int> delete_process(queue<int> ready_queue) {
	int size_ready_queue = ready_queue.size();
	for (int i = 0; i < size_ready_queue; i++) {
		ready_queue.pop();
	}
	return ready_queue;
}

// método usado para escalonar um processo e iniciar sua execução num core de processamento. 
// Quando um processo acaba na fila do core ele tem que voltar para fila de processos ?
queue<int> schedule_process (queue<int> core, queue<int> ready_queue){
    int size_ready_queue = ready_queue.size();
	for (int i = 0; i < size_ready_queue; i++) {
		core.push(ready_queue.front());
		ready_queue.pop();
	}
}

// método usado para remover um processo de um core de processamento.
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

// método que implementa o algoritmo de escalonamento FIFO.
void fifo_scheduler(queue<int> core, queue<int> ready_queue) {
	core = schedule_process(core, ready_queue);
	ready_queue = delete_process(ready_queue);
	core = deschedule_process(core, ready_queue);
}

// método que implementa o algoritmo de escalonamento SJF.
void shortest_job_first(){

}

// método que implementa o algoritmo de escalonamento Round Robin. 
void round_robin(){

}

class Scheduler {
    queue<int> core = 64; //objeto que internamente representa os cores de processamento da CPU por meio de uma estrutura de dados.
    queue<int> ready_queue; //fila dos processos prontos para execução.
}

// pop(): remove elementos
// push(): insere elementos
// front(): pega o primeiro elemento da fila