#include "MACD.h"
#include <fstream>


int main(int argc, const char * argv[])
{
	if (argc > 1) {
		MACD x(argv[1]);
	}
	return 0;
}