#ifndef _KERNEL_H_
#define _KERNEL_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <chrono>
#include <queue>

using namespace std;

class Kernel {

public:
	Kernel();
	~Kernel();

	// Inicia a execução do kernel
	void run();

	// Estrutura de dados que contém todos os processos e seus metadados.
	int Process_Control_Table[64][6];

	// Método que cria um processo e insere na tabela de processos.
	void create_process(queue<int> ready_queue, int qtd_process);

	// Método que destrói um processo e remove da tabela de processos.
	void kill_process(queue<int> ready_queue);

	// Método que inicializa a execução de um processo pelo escalonador de processos.
	void run_process();

	// Classe que representa a CPU e seus cores de processamento

};
#endif