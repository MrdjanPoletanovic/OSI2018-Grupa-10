#include "ResApl.h"

#include <string>
#include <cstdio>
#include <chrono>
#include <ctime>
#include <random>

void RestartujApl()
{

	std::string MasterPassword, str;
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distributionInteger(0, 9);
	std::string str1;
	for (int i = 0; i < 5; i++)
	{
		int p = distributionInteger(generator);
		str1 = std::to_string(p);
		str.insert(i, str1);
	}
	std::cout << "Master Password je " << str << std::endl;
	do
	{
		std::cout << "Unesite MasterPassword: ";
		std::getline(std::cin, MasterPassword);
		if (str.compare(MasterPassword) == 0)
		{
			std::remove("nalozi.csv");
		}
		else
		{
			std::cout << "Pogresan MasterPassword pokusajte ponovo" << std::endl;
		}
	}
    while(str.compare(MasterPassword)!=0);

}
