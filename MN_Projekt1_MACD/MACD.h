#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class MACD
{
	ifstream pricesPerShare;
public:
	MACD(string fileName);
	~MACD();
	void print();
};

