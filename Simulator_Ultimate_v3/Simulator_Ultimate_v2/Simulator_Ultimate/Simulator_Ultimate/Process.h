#pragma once
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <thread>
#include<time.h>

using namespace std;

class Process {

public:
	//Simulator* sim = new Simulator();
	int process_id, total_time, remaining_time, st, rr, aux, quantum;
	string state[4] = { "Ready", "Waiting", "Running", "Terminated" };

	Process() {};

	Process(int p, int tt, int st) {
		
		this->process_id = p;
		this->total_time = tt;
		this->remaining_time = this->total_time;
		this->st = st;
		this->rr = quantum;
		this->aux = this->rr;
	};

	Process(int p, int tt, int st, int q) {

		this->process_id = p;
		this->total_time = tt;
		this->remaining_time = this->total_time;
		this->st = st;
		this->rr = q;
		this->aux = this->rr;
	};

	void setSt(int st) {
		this->st = st;
	}

	void displayInfo() {
	
		   cout << "[Pr: " << this->process_id
				<< " | TT:" << this->total_time
				<< " | ST:" << this->state[this->st]
				<< " | TR:" << this->remaining_time
				//<< " | QT:" << this->rr
				<< "]    ";
	}

	void displayInfoRR() {

		cout << "[Pr: " << this->process_id
			<< " | TT:" << this->total_time
			<< " | ST:" << this->state[this->st]
			<< " | TR:" << this->remaining_time
			<< " | QT:" << this->rr
			<< "]    ";
	}

	int randRange(int low, int high) {
		int valor = (rand() % ((high - low) + low)) + 2;
		return valor;
	};

	void run() {;
	}
};