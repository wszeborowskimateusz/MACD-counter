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


double MACD::EMA(int N, int samleNumber)
{
	double alfa = 2 / (N - 1);
	double numerator = prices[samleNumber], denominator = 1;
	for (int i = 0; i < N; i++) {
		numerator += (prices[samleNumber - i] * pow((1 - alfa), i));
		denominator += pow((1 - alfa), i);
	}

	return numerator/denominator;
}


double * MACD::MACDindex()
{
	double* MACDarray = NULL;
	if (numberOfSamples > 26) {
		MACDarray = new double[numberOfSamples - 26];
		int sampleCount = 26, arrayIndex = 0;
		for (; sampleCount < numberOfSamples; sampleCount++) {
			MACDarray[arrayIndex] = EMA(12, sampleCount) - EMA(26, sampleCount);
		}
	}
	return MACDarray;
}

void MACD::print()
{
	for (int i = 0; i < numberOfSamples; i++) {
		cout << prices[i] << endl;
	}
}
