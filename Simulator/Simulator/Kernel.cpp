#include "Kernel.h"
#include "Scheduler.h"
#include "Process.h"


Kernel::Kernel()
{

}

Kernel::~Kernel()
{

}

Process process;

// Método que imprime na tela os metadados da Matriz
void print_matriz(int Matriz[64][6], int qtd_processos) {

    for (int i = 0; i < qtd_processos; i++) {

        cout << Matriz[i][0] << "\t\t\t"

            << Matriz[i][1] << "\t\t\t"

            << Matriz[i][2] << "\t\t"

            << Matriz[i][3] << "\n";

    }

}

// Método que cria um processo e insere na tabela de processos.
void Kernel::create_process(queue<int> ready_queue, int qtd_process) {

    int status = 0;

    for (int i = 0; i < qtd_process; i++) {

        process.process_id = i + 1;

        Kernel::Process_Control_Table[i][0] = process.process_id;

        process.total_time = process.randRange(1, 20);

        Kernel::Process_Control_Table[i][1] = process.total_time;

        Kernel::Process_Control_Table[i][2] = status;

        process.remaining_time = process.total_time;

        Kernel::Process_Control_Table[i][3] = process.remaining_time;

    }

    print_matriz(Process_Control_Table, qtd_process);

}

// Método que destrói um processo e remove da tabela de processos.
void Kernel::kill_process(queue<int> ready_queue) {

    int size_ready_queue = ready_queue.size();

    for (int i = 0; i < size_ready_queue; i++) {

        ready_queue.pop();

    }

}

// Inicia a execução do kernel
void Kernel::run() {

}

// Método que inicializa a execução de um processo pelo escalonador de processos.
void Kernel::run_process() {

}