#include "Simulator.h"
#include "Scheduler.h"
#include "Kernel.h"
#include "Process.h"
#include "core.h"

//Retorna o inicio do processo
void start() {
	//Start o simulador
	cout << "Simulator started" << endl;
   
}
// Função que gera randomicamente números em um intervalo de tempo
int randRange(int low, int high) {

	return rand() % (high - low) + low;

};




int main()
{
	//inicio main
	start();
	srand(time(NULL));
	//Process process;
	int qtd_process;

	cout << "Quantidade de processos : ";
	cin >> qtd_process;
	Process* arrayProcess = new Process[qtd_process];

	for (int i = 0; i < qtd_process; i++) {
		int state_id = 0;
		arrayProcess[i].state[state_id];
		arrayProcess[i].total_time = randRange(1, 20);
		arrayProcess[i].quantum = randRange(1, 10);
		arrayProcess[i].remaining_time = arrayProcess[i].total_time;
		arrayProcess[i].process_id = i + 1;
			cout << "P";
			cout << i + 1;
			arrayProcess[i].showProcess();
			if (i != (qtd_process - 1)) {
				cout << ", ";
			}
	}


	//final main
	_getch(); //pause final
}
