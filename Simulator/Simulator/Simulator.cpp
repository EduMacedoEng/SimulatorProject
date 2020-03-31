#include "Simulator.h"
#include "Kernel.h"
#include "core.h"

//const int N = 4; // Constante que representa o numero de atributos de cada processo
//const int M = 100;

Kernel* kernel = new Kernel();


Simulator::Simulator() {
	//
}

// Função que gera randomicamente números em um intervalo de tempo
int randRange(int low, int high) {
	return rand() % (high - low) + low;
};

void Simulator::run(int qtd_process) {

	cout << "Simulator started" << endl;
	//int** matriz = batch_process_init();
	batch_process_init(qtd_process);
	//int** matriz_kernel = kernel->create_process(matriz);
	//printMatrizProcess(matriz_kernel, qtd_process);
}

void Simulator::batch_process_init(int qtd_process) {
	
	kernel->Process_Control_Table = new Process[qtd_process];
	int status = 0;
	for (int i = 0; i < qtd_process; i++) {
		int state_id = 0;
		kernel->Process_Control_Table[i].state[state_id];
		kernel->Process_Control_Table[i].total_time = randRange(1, 20);
		kernel->Process_Control_Table[i].quantum = randRange(1, 10);
		kernel->Process_Control_Table[i].remaining_time = kernel->Process_Control_Table[i].total_time;
		kernel->Process_Control_Table[i].process_id = i;
		kernel->Process_Control_Table[i].showProcess(state_id);
	}
}

void Simulator::create_random_process() {
	kernel->create_process();
}

int main()
{
	//inicio main
	
	Simulator s;
	int qtd_process;

	cout << "Quantidade de processos : ";
	cin >> qtd_process;
	s.run(qtd_process);


	



	//final main
	_getch(); //pause final
}
