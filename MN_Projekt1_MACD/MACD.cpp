#include "MACD.h"



MACD::MACD(string fileName)
{
	ifstream pricesPerShareFile(fileName);

	double x;
	while (pricesPerShareFile >> x) {
		++numberOfSamples;
	}
		
	prices = new double[numberOfSamples];


	//Come back to the begining of a file
	pricesPerShareFile.clear();
	pricesPerShareFile.seekg(0, ios::beg);


	int i = 0;
	while (pricesPerShareFile >> x) {
		prices[i++] = x;
	}

	pricesPerShareFile.close();
}


MACD::~MACD()
{
	delete[]prices;
}

void MACD::print()
{
	for (int i = 0; i < numberOfSamples; i++) {
		cout << prices[i] << endl;
	}
}
