#include "MACD.h"
#include "earnMoney.h";


int main(int argc, const char * argv[])
{
	if (argc > 1) {
		MACD x(argv[1]);
		x.doMACD();
		//Zadanie dodatkowe 
		earnMoney xd;
		cout<<"Profit = "<<xd.countProfit(argv[1])<<endl;
		
	}

	return 0;
}