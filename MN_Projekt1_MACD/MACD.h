#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;
class MACD
{
	//Table to store all prices of given shares
	double* prices;
	int numberOfSamples = 0;
public:
	MACD(string fileName);
	~MACD();
	//Count EMA for a specific sample
	double EMA(int N,int samleNumber);
	//Count MACD index for all samples
	double* MACDindex();
	void print();
};

