#include "Simulator.h"
#include "Scheduler.h"
#include "Kernel.h"
#include "Process.h"
#include "core.h"

const int N = 4;
const int M = 100;
Simulator::Simulator() {
	//
}

//Retorna o inicio do processo
void start() {
	//Start o simulador
	cout << "Simulator started" << endl;
   
}

// Função que gera randomicamente números em um intervalo de tempo
int randRange(int low, int high) {

	return rand() % (high - low) + low;

};

void printMatriz(int** matriz, int qtd_process) {
	for (int i = 0; i < qtd_process; i++)
	{
		cout << matriz[i][0] << "\t\t\t"
			<< matriz[i][1] << "\t\t\t"
			<< matriz[i][2] << "\t\t\t"
			<< matriz[i][3] << endl;
	}
}

void printArray(int** arr, int qtd_process) {
	for (int i = 0; i < qtd_process; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << "|";
		}
		cout << endl;
	}
}

void Simulator::run(int qtd_process) {

	Kernel* kernel = new Kernel();

	cout << "Simulator started" << endl;
	int** matriz = batch_process_init(qtd_process);
	cout << "__________________" << endl;
	int** matriz_kernel = kernel->create_process(matriz,qtd_process);
	printArray(matriz_kernel, qtd_process);
}


int** Simulator::batch_process_init(int qtd_process) {
	int** matriz = create_random_process(qtd_process);
	return matriz;
}

int** getArray(int qtd_process) {
	int** arr = new int* [qtd_process];
	for (int i = 0; i < qtd_process; i++) {
		arr[i] = new int[qtd_process];
		for (int j = 0; j < N; j++) {
			arr[i][0] = (i + j - 2);
			arr[i][1] = randRange(1, 20);
			arr[i][2] = 0;
			arr[i][3] = arr[i][1];
		}
	}
	return arr;
}

int** Simulator::create_random_process(int qtd_process) {
	
	Process* arrayProcess = new Process[qtd_process];
	int state_id = 0;
	//int** matriz = new int*[100];
	int** matriz = getArray(qtd_process);

	for (int i = 0; i < qtd_process; i++) {
		for (int j = 0; i < 4; i++)
		{
			//matriz[i][0] = (i+j-2);
			matriz[i][1] = randRange(1, 20);
			matriz[i][2] = state_id;
			matriz[i][3] = matriz[i][1];
		}

	}
	printArray(matriz, qtd_process);
	return matriz;
}




int main()
{
	//inicio main
	Simulator s;
	int qtd_process;
	cout << "Quantidade de processos : ";
	cin >> qtd_process;
	//s.create_random_process(qtd_process);
	s.run(qtd_process);

	//final main
	_getch(); //pause final
}
