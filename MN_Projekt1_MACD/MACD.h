#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;
class MACD
{

public:
	MACD();
	MACD(string fileName);
	~MACD();
	//Creates 2 files one with macd and one with signal
	void doMACD();

	//Count EMA for a specific sample and a specific array with prices
	double EMA(int N, int samleNumber, double* sourcePrices);

private:
	//Table to store all prices of given shares
	double* prices;
	int numberOfSamples = 0;

	//Count EMA for a specific sample
	double EMA(int N, int samleNumber);

	//Count MACD index for all samples
	double* MACDindex();
	//Count SIGNAL index for all samples
	double* SIGNAL(double* MACDarray);


	void print();
};

