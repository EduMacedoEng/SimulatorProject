#include "Process.h"
#include <iostream>

using namespace std;

Process::Process() 
{

}

Process::~Process() 
{

}

/*Process::Process(int total_time, int remaining_time, int process_id) {
	this->process_id = process_id;
	this->remaining_time = remaining_time;
	this->total_time = total_time;
}*/



/*Process::Process(int total_time, int remaining_time, int process_id, int quantum) {
	this->process_id = process_id;
	this->remaining_time = remaining_time;
	this->total_time = total_time;
	this->quantum = quantum;
}*/



void Process::showProcess() {
	if (quantum != NULL) {
		cout << "[ID:";
		cout << process_id;
		cout << "|RT:";
		cout << remaining_time;
		cout << "|TT:";
		cout << total_time;
		cout << "|Q:";
		cout << quantum;
		cout << "]";
	}
	else {
		cout << "[ID:";
		cout << process_id;
		cout << "|RT:";
		cout << remaining_time;
		cout << "|TT:";
		cout << total_time;
	}
		
}

// Método que gera randomicamente números em um intervalo de tempo
int Process::randRange(int low, int high) {

	return rand() % (high - low) + low;

};