#include "loto.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <cmath>
#include <algorithm>
#include <thread>
#define NUM_CARDS 45
#define NUM_DRAWED 20
#define NUM_CHOSEN 7


void izvuci(int izvuceni[NUM_CHOSEN], int niz[NUM_DRAWED])
{
	for(int i=0, index; i<NUM_DRAWED; i++)
	{
		index = std::rand()%(NUM_CARDS-i);
		izvuceni[i] = niz[index];
		std::swap(niz[index], niz[NUM_CARDS-1-i]);
	}
}


void izaberi(int izabrani[NUM_CHOSEN])
{
	std::cout << "Izaberite 7 brojeva: " << std::endl;
	for(int i=0; i<NUM_CHOSEN; i++)
	{
		std::cin >> izabrani[i];
	}
}


void prikazi_izvlacenje(int izvuceni[NUM_DRAWED])
{
	std::cout << std::endl << "Izvuceni: " << std::endl;
	for(int i=0; i<NUM_DRAWED; i++)
	{
		std::cout << std::setw(2) << izvuceni[i] << " ";
		if ((i+1)%5 == 0)
		{
			std::cout << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	std::cout << std::endl;
}


int provjera(int izvuceni[NUM_DRAWED], int izavrani[NUM_CHOSEN])
{
	int br=0, bodovi=0;
	for(int i=0; i<NUM_CHOSEN; i++)
	{
		for(int j=0; j<NUM_DRAWED; j++)
		{
			if (izavrani[i] == izvuceni[j])
			{
				bodovi += (br++)*10;
				break;
			}
		}
	}
	return bodovi;
}
