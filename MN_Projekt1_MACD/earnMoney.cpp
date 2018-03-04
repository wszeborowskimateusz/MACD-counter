#include "earnMoney.h"



earnMoney::earnMoney()
{
}


earnMoney::~earnMoney()
{
}

double earnMoney::countProfit(string fileName)
{
	int currentDay = 0, ammountOfShares = 0;

	MACD macdHelp;
	std::vector<double> pricesPerShare,macd,signal;
	ifstream pricesPerShareFile(fileName);
	double initialPrice;
	pricesPerShareFile >> initialPrice;
	pricesPerShare.push_back(initialPrice);
	currentDay++;
	double ammountOfMoney = 1000 * initialPrice;

	//true if you can only sale and false if you can only buy
	bool canSell = false, isMACDgreater;


	double price, difference;
	while (pricesPerShareFile >> price) {
		pricesPerShare.push_back(price);
		if (currentDay > 26) {
			macd.push_back(macdHelp.EMA(12, currentDay, &pricesPerShare[0]) - macdHelp.EMA(26, currentDay, &pricesPerShare[0]));
			if (currentDay > 26 + 9 ) {
				signal.push_back(macdHelp.EMA(9, currentDay-26-1, &macd[0]));

				
				difference = abs(macd[currentDay - 26 - 1] - signal[currentDay - 26 - 9 - 1]);
				//Linie sie przecinaja
				if (difference<=0.2) {
					if (canSell) {
						//szukamy czy MACD przecina SIGNAL od góry
						if (currentDay - 26 -9  - 1 - 1 > 0 && 
							macd[currentDay - 26 - 1 - 1] > signal[currentDay - 26 - 9 - 1 - 1]) {

							ammountOfMoney += ammountOfShares*price;
							ammountOfShares = 0;
							canSell = false;
						}
					}
					else {
						//szukamy czy MACD przecina SIGNAL od do³u
						if (currentDay - 26 - 9 - 1 - 1 > 0 &&
							macd[currentDay - 26 - 1 - 1] < signal[currentDay - 26 - 9 - 1 - 1]) {
							int howManySharesCanWeBuy = ammountOfMoney / price;
							ammountOfMoney -= howManySharesCanWeBuy*price;
							ammountOfShares += howManySharesCanWeBuy;
							canSell = true;
						}
					}
				}
			}
		}
		currentDay++;
	}



	pricesPerShareFile.close();
	return (ammountOfShares * price + ammountOfMoney) / (1000 * initialPrice);
}
