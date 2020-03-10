#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int randRange(int low, int high){
	return rand() % (high - low) + low;
}