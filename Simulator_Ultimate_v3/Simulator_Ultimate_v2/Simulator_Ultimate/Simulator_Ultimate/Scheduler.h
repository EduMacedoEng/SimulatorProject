#pragma once
#include "Kernel.h"
#include "Process.h"
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <thread>

using namespace std;

class Scheduler {
public:

	//Kernel::CPU* cpu;
	Process* p;

	Scheduler() {};

	list<Process*> cores;
	list<Process*>::iterator it;

	queue<Process*> ready_queue;

	int aux_scheduling_algorithm = 0;
	int aux_processor_cores_number = 0;


	void run(int opcao, int qtd_cores, list<Process*> process_control_table) {
		aux_scheduling_algorithm = opcao;
		aux_processor_cores_number = qtd_cores;

		ready_queue = insert_process(process_control_table, ready_queue);
		set_scheduling_algorithm(ready_queue, cores, aux_scheduling_algorithm);
		
	}

	void set_scheduling_algorithm(queue<Process*> processos, list<Process*> cores, int alg) {
		if (alg == 1) {
			FIFO(processos, cores);
		}
		if (alg == 2) {
			SJF(processos, cores);
		}
		if (alg == 3) {
			RR(processos, cores);
		}
	}

	queue<Process*> insert_process(list<Process*> process_control_table, queue<Process*> ready_queue) {
		int size = process_control_table.size();
		for (int i = 0; i < size; i++)
		{
			ready_queue.push(process_control_table.front());
			process_control_table.pop_front();
		}
		return ready_queue;
	}

	void schedule_process(Process* process) {
		it = cores.begin();
		advance(it, cores.size());
		cores.insert(it, process);
		ready_queue.pop(); //Quando eu inserir o processo que está na primeira posição da fila na lista de cores eu removo ele. 
	}

	void deschedule_process(int pos) {
		it = cores.begin();
		advance(it, pos);
		cores.erase(--it);
	}

	void resumo(queue<Process*> processos, queue<Process*> processos_finalizados, list<Process*> cores2, int t) {
		cout << endl;
		cout << "T" << t << endl;
		print_list(cores2);
		cout << "\n\n";
		print_queue(processos);
		cout << "\n\n";
		print_queue_terminated(processos_finalizados);
		cout << "\n\n";
	}

	void resumoRR(queue<Process*> processos, queue<Process*> processos_finalizados, list<Process*> cores2, int t) {
		cout << endl;
		cout << "T" << t << endl;
		print_list_RR(cores2);
		cout << "\n\n";
		print_queue_RR(processos);
		cout << "\n\n";
		print_queue_terminated_RR(processos_finalizados);
		cout << "\n\n";
	}

	void print_queue(queue <Process*> gq) {
		queue <Process*> g = gq;
		cout << "FILA: ";
		while (!g.empty()) {
			g.front()->displayInfo();
			g.pop();
		}
	}

	void print_queue_terminated(queue <Process*> gq) {
		queue <Process*> g = gq;
		cout << "TERMINADOS: ";
		while (!g.empty()) {
			g.front()->displayInfo();
			g.pop();
		}
	}

	void print_list(list <Process*> p) {
		cout << "\nCORES: ";
		for (list<Process*>::iterator it = p.begin(); it != p.end(); it++) {
			(*it)->displayInfo();
		}
	}

	void print_queue_RR(queue <Process*> gq) {
		queue <Process*> g = gq;
		cout << "FILA: ";
		while (!g.empty()) {
			g.front()->displayInfoRR();
			g.pop();
		}
	}

	void print_queue_terminated_RR(queue <Process*> gq) {
		queue <Process*> g = gq;
		cout << "TERMINADOS: ";
		while (!g.empty()) {
			g.front()->displayInfoRR();
			g.pop();
		}
	}

	void print_list_RR(list <Process*> p) {
		cout << "\nCORES: ";
		for (list<Process*>::iterator it = p.begin(); it != p.end(); it++) {
			(*it)->displayInfoRR();
		}
	}

	int minIndex(queue<Process*>& q, int sortedIndex) {
		queue<Process*> qclone = q;
		int min_index = -1;
		int min_val = INT_MAX;
		int n = qclone.size();

		for (int i = 0; i < n; i++) {
			int curr = qclone.front()->total_time;
			qclone.pop();

			if (curr <= min_val && i <= sortedIndex) {
				min_index = i;
				min_val = curr;
			}
			qclone.push(qclone.front());
		}
		return min_index;
	}

	int minIndex_list_FIFO_SJF(list<Process*> q, int sortedIndex) {
		list<Process*> qclone = q;
		list<Process*> aux_clone;
		int min_index = -1;
		int min_val = INT_MAX;
		int n = qclone.size();

		for (int i = 0; i < n; i++) {
			int curr = qclone.front()->remaining_time;
			aux_clone.push_front(qclone.front());
			qclone.pop_front();

			if (curr <= min_val && i <= sortedIndex) {
				min_index = i;
				min_val = curr;
			}
			qclone.push_back(aux_clone.front());
		}
		return min_index;
	}

	int minIndex_list_RR(list<Process*> q, int sortedIndex) {
		list<Process*> qclone = q;
		list<Process*> aux_clone;
		int min_index = -1;
		int min_val = INT_MAX;
		int n = qclone.size();

		for (int i = 0; i < n; i++) {
			int curr = qclone.front()->rr;
			aux_clone.push_front(qclone.front());
			qclone.pop_front();

			if (curr <= min_val && i <= sortedIndex) {
				min_index = i;
				min_val = curr;
			}
			qclone.push_back(aux_clone.front());
		}
		return min_index;
	}

	void insertMinToRear(queue<Process*>& q, int min_index) {
		Process* min_val;
		int n = q.size();
		for (int i = 0; i < n; i++) {
			Process* curr = q.front();
			q.pop();
			if (i != min_index)
				q.push(curr);
			else
				min_val = curr;
		}
		q.push(min_val);
	}

	queue<Process*> sortQueue(queue<Process*>& q) {
		for (int i = 1; i <= q.size(); i++) {
			int min_index = minIndex(q, q.size() - i);
			insertMinToRear(q, min_index);
		}
		return q;
	}

	list <Process*> schedule_process_1(queue<Process*> process, list <Process*> cores, list <Process*>::iterator it) {
		process.front()->setSt(1);
		it = cores.begin();
		advance(it, cores.size());
		cores.insert(it, process.front());
		process.pop();
		return cores;
	}

	queue<Process*> schedule_process_2(queue<Process*> process, list <Process*> cores, list <Process*>::iterator it) {	
		process.front()->setSt(1);
		it = cores.begin();
		advance(it, cores.size());
		cores.insert(it, process.front());
		process.pop();
		return process;
	}
	
	/*
	list <Process*> deschedule_process_1(queue<Process*> process_terminated, list <Process*> cores) {
		cores.front()->setSt(3);
		process_terminated.push(cores.front());
		cores.pop_front();
		return cores;
	}

	queue<Process*> deschedule_process_2(queue<Process*> process_terminated, list <Process*> cores) {
		cores.front()->setSt(3);
		process_terminated.push(cores.front());
		cores.pop_front();
		return process_terminated;
	}

	queue<Process*> deschedule_process_3(queue<Process*> process, list <Process*> cores) {
		cores.front()->setSt(0);
		cores.front()->rr = cores.front()->aux;
		process.push(cores.front());
		cores.pop_front();
		return process;
	}

	list <Process*> deschedule_process_4(queue<Process*> process_terminated, list <Process*> cores) {
		cores.front()->setSt(0);
		process_terminated.push(cores.front());
		cores.pop_front();
		return cores;
	}
	*/
	list <Process*> deschedule_process_1(queue<Process*> process_terminated, list <Process*> cores) {
		list<Process*>::iterator it;
		it = cores.begin();

		int tam = cores.size();
		int index = minIndex_list_FIFO_SJF(cores, tam-1);

		advance(it, index);
		
		process_terminated.push((*it));
		(*it)->setSt(3);

		cores.erase(it);

		return cores;
	}

	queue<Process*> deschedule_process_2(queue<Process*> process_terminated, list <Process*> cores) {
		list<Process*>::iterator it;
		it = cores.begin();

		int tam = cores.size();
		//cout << "Tamanho: " << tam << endl;
		int index = minIndex_list_FIFO_SJF(cores, tam-1);
		//cout << "Index: " << index << endl;

		advance(it, index);
		
		process_terminated.push((*it));
		(*it)->setSt(3);

		cores.erase(it);

		return process_terminated;
	}

	queue<Process*> deschedule_process_3(queue<Process*> process, list <Process*> cores) {
		list<Process*>::iterator it;
		it = cores.begin();

		int tam = cores.size();
		//cout << "Tamanho: " << tam << endl;
		int index = minIndex_list_RR(cores, tam - 1);
		//cout << "Index: " << index << endl;

		advance(it, index);

		process.push((*it));
		(*it)->setSt(0);
		(*it)->rr = (*it)->aux;

		cores.erase(it);

		return process;
	}

	list <Process*> deschedule_process_4(queue<Process*> process, list <Process*> cores) {
		list<Process*>::iterator it;
		it = cores.begin();

		int tam = cores.size();
		int index = minIndex_list_RR(cores, tam - 1);

		advance(it, index);

		//process.push((*it));
		//(*it)->rr = (*it)->aux;
		//(*it)->setSt(0);

		cores.erase(it);

		return cores;
	}

	

	

	void FIFO(queue<Process*> processos, list<Process*> cores2) {
		list <Process*> cores;
		list <Process*> aux_cores;
		list <Process*>::iterator it;

		queue<Process*> process;
		queue<Process*> process_terminated;

		cores = cores2;
		process = processos;

		resumo(process, process_terminated, cores, 0);

		int loop = 0;
		int t = 0;
		int aux = 0;
		bool tp = true;
		while (tp) {
			if (!process.empty() && process.front()->st == 0) {
				if (cores.size() < aux_processor_cores_number) {
					cores = schedule_process_1(process, cores, it);
					process = schedule_process_2(process, cores, it);
				}
			}

			if (!cores.empty()) {
				for (list<Process*>::iterator it = cores.begin(); it != cores.end(); it++) {
					if ((*it)->remaining_time > 0) {
						(*it)->setSt(2);
						(*it)->remaining_time--;
					}
					else {
						(*it)->setSt(2);
					}
				}
			}

			aux_cores = cores;
			for (list<Process*>::iterator it = aux_cores.begin(); it != aux_cores.end(); ++it) {
				if (!cores.empty()) {
					if ((*it)->remaining_time == 0) {
						process_terminated = deschedule_process_2(process_terminated, cores);
						cores = deschedule_process_1(process_terminated, cores);
					}	
				}	
			}

			Sleep(1000); //1000000 microsegundos equivale a 1 segundo
			resumo(process, process_terminated, cores, aux + 1);
			aux++;
			if (cores.empty() && process.empty()) {
				tp = false;
			}
		}
	}

	void SJF(queue<Process*> processos, list<Process*> cores2) {
		list <Process*> cores;
		list <Process*> aux_cores;
		list <Process*>::iterator it;

		queue<Process*> process;
		queue<Process*> process_terminated;

		cores = cores2;
		process = sortQueue(processos);

		resumo(process, process_terminated, cores, 0);

		int loop = 0;
		int t = 0;
		int aux = 0;
		bool tp = true;
		while (tp) {
			if (!process.empty() && process.front()->st == 0) {
				if (cores.size() < aux_processor_cores_number) {
					cores = schedule_process_1(process, cores, it);
					process = schedule_process_2(process, cores, it);
				}
			}

			if (!cores.empty()) {
				for (list<Process*>::iterator it = cores.begin(); it != cores.end(); it++) {
					if ((*it)->remaining_time > 0) {
						(*it)->setSt(2);
						(*it)->remaining_time--;
					}
					else {
						(*it)->setSt(2);
					}
				}
			}

			aux_cores = cores;
			for (list<Process*>::iterator it = aux_cores.begin(); it != aux_cores.end(); ++it) {
				if (!cores.empty()) {
					if ((*it)->remaining_time == 0) {
						process_terminated = deschedule_process_2(process_terminated, cores);
						cores = deschedule_process_1(process_terminated, cores);
					}
				}
			}

			Sleep(1000); //1000000 microsegundos equivale a 1 segundo
			resumo(process, process_terminated, cores, aux + 1);
			aux++;
			if (cores.empty() && process.empty()) {
				tp = false;
			}
		}
	}

	void RR(queue<Process*> processos, list<Process*> cores2) {
		list <Process*> cores;
		list <Process*> aux_cores;
		list <Process*> aux_cores2;
		list <Process*> aux_cores3;
		list <Process*>::iterator it;
		
		queue<Process*> process;
		queue<Process*> process_terminated;

		cores = cores2;
		process = processos;

		resumoRR(process, process_terminated, cores, 0);

		int loop = 0;
		int t = 0;
		int aux = 0;
		bool tp = true;
		while (tp) {
			if (!process.empty() && process.front()->st == 0) {
				if (cores.size() < aux_processor_cores_number) {
					cores = schedule_process_1(process, cores, it);
					process = schedule_process_2(process, cores, it);
				}
			}

			if (!cores.empty()) {
				for (list<Process*>::iterator it = cores.begin(); it != cores.end(); it++) {
					if ((*it)->remaining_time > 0 && (*it)->rr > 0) {
						(*it)->setSt(2);
						(*it)->remaining_time--;
						(*it)->rr--;
					}
					else {
						(*it)->setSt(2);
					}
				}
			}

			aux_cores = cores;
			for (list<Process*>::iterator it = aux_cores.begin(); it != aux_cores.end(); it++) {
				if ((*it)->remaining_time == 0) {
					process_terminated = deschedule_process_2(process_terminated, cores);
					cores = deschedule_process_1(process_terminated, cores);
				}
			}

			aux_cores = cores;
			for (list<Process*>::iterator it = aux_cores.begin(); it != aux_cores.end(); it++) {
				if (!cores.empty() && (*it)->rr == 0) {
					cores = deschedule_process_4(process, cores);
					process = deschedule_process_3(process, aux_cores);
					
				}
			}

			Sleep(1000); //1000000 microsegundos equivale a 1 segundo

			resumoRR(process, process_terminated, cores, aux + 1);

			if (cores.empty() && process.empty()) {
				tp = false;
			}
			aux++;
		}
	}

};