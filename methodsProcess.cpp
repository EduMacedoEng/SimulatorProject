#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int randRange(int low, int high){
	return rand() % (high - low) + low;
}

int main() {
	srand(time(NULL));
	Process process;

	for (int i = 1; i <= 5; i++) {
		int state_id = 0;
		process.total_time = randRange(1, 20);
		process.remaining_time = process.total_time;
		process.process_id = i;
		cout << "Processo: " << process.process_id << " | Status: " << process.state[state_id] << "\n";
		cout << "Tempo estimado para execucao: " << process.total_time << " segundos. \n\n";
		auto start = chrono::system_clock::now();
		state_id++;
		cout << "Processo: " << process.process_id << " | Status: " << process.state[state_id] << "\n\n";
		
		int dec = 0;
		while (dec < process.total_time) {
			cout << "Tempo restante: " << process.remaining_time << endl;
			dec++;
			process.remaining_time--;
			Sleep(1000);
			//system("cls");
		}

		auto end = chrono::system_clock::now();
		state_id++;
		cout << "Processo: " << process.process_id << " | Status: " << process.state[state_id] << "\n\n";
		
		chrono::duration<double> elapsed_seconds = end - start;
		
		time_t end_time = std::chrono::system_clock::to_time_t(end);
		cout << "Tempo de execucao do processo: " << elapsed_seconds.count() << " segundos. \n\n";
	}
	return 0;
}