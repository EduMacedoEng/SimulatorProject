#pragma once
#include "Kernel.h"
#include "Process.h"
#include "Scheduler.h"
#include <thread>


using namespace std;
class Simulator {
public:
    Kernel* k = new Kernel();
    Process* p = new Process();

    Simulator() {

    };

    int scheduling_algorithm, processor_cores_number, quantum;

    void run(int opcao, int qtd_cores, int qtd_processos, int q) {
        
        scheduling_algorithm = opcao;
        processor_cores_number = qtd_cores;
        quantum = q;

        chrono::time_point<chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        time_t start_time = chrono::system_clock::to_time_t(start);
        cout << "Begin computation at " << ctime(&start_time) << endl;
        batch_process_init(qtd_processos, opcao, quantum);
        cout << "Process Control Table: ";

        //thread th2(&Kernel::run, &k, scheduling_algorithm, processor_cores_number);
        k->run(scheduling_algorithm, processor_cores_number);
        //th2.join();

        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        time_t end_time = chrono::system_clock::to_time_t(end);
        cout << "\n\n";
        cout << "Finished computation at " << ctime(&end_time) << endl
            << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    };

    void create_random_process(int quantum) {
        k->process_control_table.push_back(new Process(p->randRange(1, 100), p->randRange(1, 10),0, quantum));
    }

    void batch_process_init(int qtd_process, int opcao, int quantum) {
        if (opcao != 3) {
            for (int i = 0; i < qtd_process; i++) {
                k->create_process();
            }
        }
        else {
            for (int i = 0; i < qtd_process; i++) {
                k->create_process(quantum);
            }
        }
    }
};