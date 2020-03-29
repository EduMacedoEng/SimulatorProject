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
void print_matriz(int** Matriz, int qtd_processos) {

    for (int i = 0; i < qtd_processos; i++) {

        cout << Matriz[i][0] << "\t\t\t"

            << Matriz[i][1] << "\t\t\t"

            << Matriz[i][2] << "\t\t"

            << Matriz[i][3] << "\n";

    }

}

/*void printMatriz(int** matriz, int qtd_process) {
    for (int i = 0; i < qtd_process; i++)
    {
        cout << matriz[i][0] << "\t\t\t"
            << matriz[i][1] << "\t\t\t"
            << matriz[i][2] << "\t\t\t"
            << matriz[i][3] << endl;
    }
}*/

// Método que cria um processo e insere na tabela de processos.
int** Kernel::create_process(int** matriz, int qtd_process) {

    int status = 0;

    Kernel::Process_Control_Table = matriz;

    return Kernel::Process_Control_Table;
    //printMatriz(Process_Control_Table, qtd_process);

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
