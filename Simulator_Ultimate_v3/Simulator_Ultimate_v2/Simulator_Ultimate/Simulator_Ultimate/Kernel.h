#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Simulator.h"
#include "Process.h"
#include "Scheduler.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Kernel {
public:
	Scheduler* s = new Scheduler();
	Process* p = new Process();

	list<Process*> process_control_table;
	list<Process*>::iterator it;

	Kernel() {};

	void run(int scheduling_algorithm, int processor_cores_number) {
		print_list(process_control_table);
		cout << "\n\n";
		
		//thread th3(&Scheduler::run, &s, scheduling_algorithm, processor_cores_number, process_control_table);
		s->run(scheduling_algorithm, processor_cores_number, process_control_table);
		//th3.join();
	}

	void create_process() {
		it = process_control_table.begin();
		advance(it, process_control_table.size());
		process_control_table.insert(it, new Process(process_control_table.size()+1, p->randRange(1, 10), 0));
	} 

	void create_process(int quantum) {
		it = process_control_table.begin();
		advance(it, process_control_table.size());
		process_control_table.insert(it, new Process(process_control_table.size() + 1, p->randRange(1, 10), 0, quantum));
	}

	void kill_process(int pos) {
		it = process_control_table.begin();
		advance(it, pos);
		process_control_table.erase(--it);
	}

	void print_list(list <Process*> p) {
		for (list<Process*>::iterator it = p.begin(); it != p.end(); it++) {
			(*it)->displayInfo();
		}
	}

	void run_process() {

	}

	class CPU {
	public:
		CPU() {};
		list<Process*> cores;
	};

};


