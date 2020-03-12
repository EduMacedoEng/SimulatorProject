#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <queue>
using namespace std;


class Scheduler {
public:
    queue<int> core; //objeto que internamente representa os cores de processamento da CPU por meio de uma estrutura de dados.
    queue<int> ready_queue; //fila dos processos prontos para execução.

    void print_queue(queue<int> q) {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }

    void print_matriz(int Matriz[64][4], int qtd_processos) {
        for (int i = 0; i < qtd_processos; i++) {
            cout << Matriz[i][0] << "\t\t\t"
                << Matriz[i][1] << "\t\t\t"
                << Matriz[i][2] << "\t\t"
                << Matriz[i][3] << "\n";
        }
    }

    // método que seleciona o algoritmo de escalonamento a ser usado.
    void set_scheduling_algorithm(int number, queue<int> core, queue<int> ready_queue, int processos[] processos, int burst_time[] burst_time, int quantum) {
        if (number == 1){
            fifo_scheduler(core, ready_queue);
        } else if (number == 2) {
            int mat[10][6];
            shortest_job_first_non_preemptive(mat);
            // Perguntar ao professor se os métodos de inserção serão para todos os metodos de sort.
        } else if (number == 3) {
            round_robin(processos, burst_time, quantum); // Passar uma lista com processos e outra com o burst time.
        }
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

    void insert_process_fifo(int Matriz[64][4], int qtd_process) {
        int status = 0;
        for (int i = 0; i < qtd_process; i++) {
            process.process_id = i+1;
            Matriz[i][0] = process.process_id;
            process.total_time = process.randRange(1, 20);
            Matriz[i][1] = process.total_time;
            Matriz[i][2] = status;
            process.remaining_time = process.total_time;
            Matriz[i][3] = process.remaining_time;
        }
        print_matriz(Matriz, qtd_process);
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
    // 1 - Classifique todo o processo de acordo com a hora de chegada.
    // 2 - Em seguida, selecione o processo que possui o tempo mínimo de chegada e o tempo mínimo de Burst.
    // 3 - Após a conclusão do processo, faça um pool de processos que após a conclusão do processo anterior e
    //     selecione esse processo entre o pool que estiver com o tempo mínimo de Burst.

    // Como calcular os tempos abaixo no SJF usando um programa?
    //	1 - Tempo de Conclusão: Tempo em que o processo completa sua execução.
    // 	2 - Turn Around Time: Diferença de tempo entre o tempo de conclusão e o horário de chegada. 
    //		Hora de Entrega = Hora de Conclusão - Hora de Chegada
    //	3 - Waiting Time (W.T): Diferença de tempo entre o tempo de retorno e o tempo de burst.
    //    	Tempo de espera = tempo de retorno - tempo de ruptura

    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void arrangeArrival(int num, int mat[][6]) {
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num - i - 1; j++) {
                if (mat[j][1] > mat[j + 1][1]) {
                    for (int k = 0; k < 5; k++) {
                        swap(mat[j][k], mat[j + 1][k]);
                    }
                }
            }
        }
    }

    void completionTime(int num, int mat[][6]) {
        int temp, val;
        mat[0][3] = mat[0][1] + mat[0][2];
        mat[0][5] = mat[0][3] - mat[0][1];
        mat[0][4] = mat[0][5] - mat[0][2];

        for (int i = 1; i < num; i++) {
            temp = mat[i - 1][3];
            int low = mat[i][2];
            for (int j = i; j < num; j++) {
                if (temp >= mat[j][1] && low >= mat[j][2]) {
                    low = mat[j][2];
                    val = j;
                }
            }
            mat[val][3] = temp + mat[val][2];
            mat[val][5] = mat[val][3] - mat[val][1];
            mat[val][4] = mat[val][5] - mat[val][2];
            for (int k = 0; k < 6; k++) {
                swap(mat[val][k], mat[i][k]);
            }
        }
    }

    void shortest_job_first_non_preemptive(int mat[][6]){
        int num, temp;

        cout << "Qual a quantidade de processos: ";
        cin >> num;

        cout << "...Diga qual o ID dos processos...\n";
        for (int i = 0; i < num; i++) {
            cout << "...Processo " << i + 1 << "...\n";
            cout << "Digite o ID do Processo: ";
            cin >> mat[i][0];
            cout << "Digite o Arrival Time: ";
            cin >> mat[i][1];
            cout << "Digite Burst Time: ";
            cin >> mat[i][2];
        }

        cout << "Antes de organizar...\n";
        cout << "Process ID\tArrival Time\tBurst Time\n";
        for (int i = 0; i < num; i++) {
            cout << mat[i][0] << "\t\t" 
                << mat[i][1] << "\t\t" 
                << mat[i][2] << "\n";
        }

        arrangeArrival(num, mat);
        completionTime(num, mat);

        cout << "Resultado Final...\n";
        cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
        for (int i = 0; i < num; i++) {
            cout << mat[i][0] << "\t\t" 
                << mat[i][1] << "\t\t" 
                << mat[i][2] << "\t\t" 
                << mat[i][4] << "\t\t" 
                << mat[i][5] << "\n";
        }
    }

    // método que implementa o algoritmo de escalonamento Round Robin.
    // Function to find the waiting time for all 
    // processes 
    void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum){
        // Make a copy of burst times bt[] to store remaining 
        // burst times. 
        int rem_bt[n];
        for (int i = 0; i < n; i++)
            rem_bt[i] = bt[i];

        int t = 0; // Current time 

        // Keep traversing processes in round robin manner 
        // until all of them are not done. 
        while (1) {
            bool done = true;

            // Traverse all processes one by one repeatedly 
            for (int i = 0; i < n; i++) {
                // If burst time of a process is greater than 0 
                // then only need to process further 
                if (rem_bt[i] > 0) {
                    done = false; // There is a pending process 
                    if (rem_bt[i] > quantum) {
                        // Increase the value of t i.e. shows 
                        // how much time a process has been processed 
                        t += quantum;
                        // Decrease the burst_time of current process 
                        // by quantum 
                        rem_bt[i] -= quantum;
                    }

                    // If burst time is smaller than or equal to 
                    // quantum. Last cycle for this process 
                    else {
                        // Increase the value of t i.e. shows 
                        // how much time a process has been processed 
                        t = t + rem_bt[i];

                        // Waiting time is current time minus time 
                        // used by this process 
                        wt[i] = t - bt[i];

                        // As the process gets fully executed 
                        // make its remaining burst time = 0 
                        rem_bt[i] = 0;
                    }
                }
            }

            // If all processes are done 
            if (done == true)
                break;
        }
    }

    // Function to calculate turn around time 
    void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
    {
        // calculating turnaround time by adding 
        // bt[i] + wt[i] 
        for (int i = 0; i < n; i++)
            tat[i] = bt[i] + wt[i];
    }

    // Function to calculate average time 
    void findavgTime(int processes[], int n, int bt[], int quantum) {
        int wt[n], tat[n], total_wt = 0, total_tat = 0;

        // Function to find waiting time of all processes 
        findWaitingTime(processes, n, bt, wt, quantum);

        // Function to find turn around time for all processes 
        findTurnAroundTime(processes, n, bt, wt, tat);

        // Display processes along with all details 
        cout << "Processes " << " Burst time "
            << " Waiting time " << " Turn around time\n";

        // Calculate total waiting time and total turn 
        // around time 
        for (int i = 0; i < n; i++) {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
            cout << " " << i + 1 << "\t\t" << bt[i] << "\t "
                << wt[i] << "\t\t " << tat[i] << endl;
        }

        cout << "Average waiting time = "
            << (float)total_wt / (float)n;
        cout << "\nAverage turn around time = "
            << (float)total_tat / (float)n;
    }

    void round_robin(int processes[] process, int burst_time[] burst_time, int quantum){
        // process id's 
        int processes[] = { 1, 2, 3 }; // Passar uma lista de processos
        int n = sizeof processes / sizeof processes[0];

        // Burst time of all processes 
        int burst_time[] = { 10, 5, 8 }; // Passar uma lista de Burst time

        // Time quantum 
        int quantum = 2; // Passar como variável o Quantum
        findavgTime(processes, n, burst_time, quantum);
        return 0;
    }

    }

    // pop(): remove elementos
    // push(): insere elementos
    // front(): pega o primeiro elemento da fila