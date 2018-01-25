
#include "LinkedHashTable.h"
#include "DoubleHashTable.h"
#include "LinearHashTable.h"

#include <fstream>
#include <chrono>
#include <string>


typedef std::chrono::high_resolution_clock::time_point ExecTime;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

int main(int argc, char* argv[]) {

  
	system("pause");
}
