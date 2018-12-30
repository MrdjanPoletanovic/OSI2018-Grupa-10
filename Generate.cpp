#include "pch.h"
#include "Generate.h"
#include <iostream>
#include <random>
#include <chrono>

void fill(std::string& str)
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distributionInteger(0, 9);
	std::string str1;
	for (int i = 5; i < 19; i++)
	{
		if (i == 9 || i == 14)
			str.insert(i,"-");
		else
		{
			
			int p = distributionInteger(generator);
			str1 = std::to_string(p);
			str.insert(i, str1);
		}
	}

}
std::string generate(std::string s)
{
	std::string key;
	if (s.compare("Loto")==0 )
	{
		
		key = "3168-";   //broj 3 oznacava redni broj igre, a 168 vrijeme trajanja igre izrazeno u satima
		fill(key);
	}
	else if (s.compare("Broj") == 0)
	{
		
		key = "1024-";  // broj 1 oznacava redni broj igre, a 024 vrijeme trajanja igre izrazeno u satima
		fill(key);
	}
	else if (s.compare("Kviz") == 0)
	{
		
		key = "2001-";  // broj 2 oznacava redni broj igre, a 001 vrijeme trajanja igre izrazeno u satima
		fill(key);
	}
	else if (s.compare("Poker") == 0)
	{
		
		key = "4000-"; //  broj 4 oznacava redni broj igre, a 000 neograniceno trajanje igre
		fill(key);
	}
	return key;
}
