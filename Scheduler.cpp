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
void insert_process (queue<int> ready_queue, int qtd_process, int id_process) {
    ready_queue.push(id_process);
    cout << "Insert process: " << id_process << endl;
}

// método usado para escalonar um processo e iniciar sua execução num core de processamento. 
void schedule_process (queue<int> core, int id_process){
    core.push(id_process);
    cout << "Insert process: " << id_process << endl;
}

// método usado para remover um processo de um core de processamento.
void deschedule_process (queue<int> q){
    int removed_process = q.front();
    q.pop();
    cout << "Removed process: " << removed_process << endl;
}

// método que implementa o algoritmo de escalonamento FIFO.
void fifo_scheduler(){

}

// método que implementa o algoritmo de escalonamento SJF.
void shortest_job_first(){

}

// método que implementa o algoritmo de escalonamento Round Robin. 
void round_robin(){

}

class Scheduler {
    queue<int> core; //objeto que internamente representa os cores de processamento da CPU por meio de uma estrutura de dados.
    queue<int> ready_queue; //fila dos processos prontos para execução.
}

// pop(): remove elementos
// push(): insere elementos
// front(): pega o primeiro elemento da fila