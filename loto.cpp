#include "loto.h"
#include "baza.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <cmath>
#include <string>
#include <algorithm>
#include <thread>
#define NUM_CARDS 45
#define NUM_DRAWN 20
#define NUM_CHOSEN 7


void izvuci(int izvuceni[], int niz[NUM_CARDS], int n)
{
	for(int i=0, index; i<n; i++)
	{
		index = std::rand()%(NUM_CARDS-i);
		izvuceni[i] = niz[index];
		std::swap(niz[index], niz[NUM_CARDS-1-i]);
	}
}


bool check_input(std::string& unos, int izabrani[NUM_CHOSEN], int niz[NUM_CARDS])
{
	std::string test = "slucajno";
	int j, i=0;
	for(j=0; unos[j]==' '; j++);
	if (unos[j]=='s' || unos[j]=='S')
	{
		bool tacno = true;
		int k;
		for(k=0; test[k]!=0 && tacno; j++, k++)
		{
			if (unos[j]>='A' && unos[j]<='Z')
				unos[j] += 0x20;
			if (unos[j] != test[k])
				tacno = false;
		}
		if (tacno)
		{
			izvuci(izabrani, niz, NUM_CHOSEN);
			i = 7;
			std::cout << "Vasi brojevi: ";
			for(int i=0; i<7; i++)
				std::cout << izabrani[i] << " ";
			std::cout << std::endl;
		}
	}
	else
	{
		for(; unos[j]!=0; j++)
		{
			if(unos[j]>='0' && unos[j]<='9')
			{
				if(unos[j+1]>='0' && unos[j+1]<='9')
				{
					izabrani[i] = (unos[j]-'0')*10 + (unos[j+1]-'0');
					j++;
					if (provjeri_broj(izabrani, i))
						i++;
					else
						break;
				}
				else if(unos[j+1]==' ' || unos[j+1]==0)
				{
					izabrani[i] = (unos[j]-'0');
					if (provjeri_broj(izabrani, i))
						i++;
					else
						break;
				}
				else
					break;
			}
			else if (unos[j]==' ')
			{
				continue;
			}
			else
				break;
		}
	}
	if (i == 7)
		return false;
	else
	{
		std::cout << "Neispravan unos! Unesite 7 razlicith brojeva izmedju 1 i 45 u sljedecem formatu." << std::endl;
		std::cout << "Primjer: 1 23 42 37 18 7 31" << std::endl;
		std::cout << "Takodje mozete napisati slucajno ako zelite da brojevi budu automatski izabrani." << std::endl << std::endl;
		return true;
	}
}


void izaberi(int izabrani[NUM_CHOSEN], int niz[NUM_CARDS])
{
	std::string unos;
	int broj_pokusaja = 0;
	do
	{
		std::cout << "Izaberite 7 brojeva: ";
		std::getline(std::cin, unos);
		broj_pokusaja++;
		if (broj_pokusaja == 4)
		{
			clear_screen();
			broj_pokusaja = 0;
		}
	}
	while(check_input(unos, izabrani, niz));
}


void prikazi_izvlacenje(int izvuceni[NUM_DRAWN])
{
	std::cout << std::endl << "Izvuceni: " << std::endl;
	for(int i=0; i<NUM_DRAWN; i++)
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


int provjera(int izvuceni[NUM_DRAWN], int izabrani[NUM_CHOSEN])
{
	int br=0, bodovi=0, pogodjeni[NUM_DRAWN];
	for(int i=0; i<NUM_CHOSEN; i++)
	{
		for(int j=0; j<NUM_DRAWN; j++)
		{
			if (izabrani[i] == izvuceni[j])
			{
				pogodjeni[br++] = izabrani[i];
				bodovi += (br)*10;
				break;
			}
		}
	}
	if (br == 0)
		std::cout << "Niste pogodili nijedan broj. Vise srece drugi put" << std::endl;
	else
	{
		std::cout << "Pogodjeni brojevi: ";
		for(int i=0; i<br; i++)
			std::cout << pogodjeni[i] << " ";
		std::cout << std::endl;
	}
	return bodovi;
}


bool provjeri_broj(int izabrani[NUM_DRAWN], int i)
{
	if(izabrani[i]<1 || izabrani[i]>NUM_CARDS)
		return false;
	for(int j=0; j<i; j++)
	{
		if (izabrani[j] == izabrani[i])
			return false;
	}
	return true;
}


void loto(int& stanje, int& dobitak, int& gubitak, int& igranje)
{
	int niz[45], izvuceni[20], izabrani[7], bodovi;
	for(int i=0; i<45; i++)
		niz[i] = i+1;
	do
	{
		stanje -= 100;
		std::srand(std::time(0));
		clear_screen();
		izaberi(izabrani, niz);
		izvuci(izvuceni, niz, 20);
		prikazi_izvlacenje(izvuceni);
		bodovi = provjera(izvuceni, izabrani);
		gubitak += 100;
		igranje++;
		std::cout << "Osvojili ste " << bodovi << " bodova." << std::endl;
		dobitak += bodovi;
		stanje += bodovi;
		std::cout << "Trenutno stanje: " << stanje << std::endl << std::endl;
		if (stanje < 100)
		{
			std::cout << "Nemate dovoljno sredstava da ponovo igrate." << std::endl << std::endl;
			break;
		}
	}
	while(igraj_ponovo());
	// std::cout << dobitak << std::endl;
	// std::cout << gubitak << std::endl;
}
