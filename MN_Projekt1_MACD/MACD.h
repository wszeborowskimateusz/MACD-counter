#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class MACD
{
	//Table to store all prices of given shares
	double* prices;
	int numberOfSamples = 0;
public:
	MACD(string fileName);
	~MACD();
	double EMA(int N);

	void print();
};

