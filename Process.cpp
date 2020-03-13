#include "Process.h"

// Método que gera randomicamente números em um intervalo de tempo
int Process::randRange(int low, int high) {
	return rand() % (high - low) + low;
};