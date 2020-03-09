#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Process {       // The class
  public:             // Access specifier
    int process_id = 0;        // Attribute (int variable)
    //srand(time(NULL));
    int total_time = rand() % 100;
};