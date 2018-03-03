#include "MACD.h"



MACD::MACD(string fileName)
{
	pricesPerShare.open(fileName);
}


MACD::~MACD()
{
	pricesPerShare.close();
}

void MACD::print()
{
	double price;
	while (pricesPerShare >> price) {
		cout << price << endl;
	}
}
