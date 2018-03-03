#include <iostream>
#include <fstream>
#include "MACD.h"

using namespace std;

int main(int argc, const char * argv[])
{
	if (argc > 1) {
		MACD x(argv[1]);
	}
	return 0;
}