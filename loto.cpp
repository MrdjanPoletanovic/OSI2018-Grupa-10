#include "loto.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <string>
#include <thread>
#include "igrac_igranje.h"
#define NUM_CARDS 45
#define NUM_DRAWN 20
#define NUM_CHOSEN 7
#define POKUSAJI 80


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
	do
	{
		std::cout << "Izaberite 7 brojeva: ";
		std::getline(std::cin, unos);
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


int provjera(int izvuceni[NUM_DRAWN], int izabrani[NUM_CHOSEN], bool namjestanje)
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
	if (!namjestanje)
	{
		if (br == 0)
			std::cout << "Niste pogodili nijedan broj. Vise srece drugi put" << std::endl;
		else
		{
			std::cout << "Pogodjeni brojevi: ";
			for(int i=0; i<br; i++)
				std::cout << pogodjeni[i] << " ";
			std::cout << std::endl;
		}
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


bool check_namjestanje(int dobitak, int gubitak, int igranje)
{
	return (igranje % 3 == 0) && (gubitak != dobitak*1.4);
}


int get_optimalno(int dobitak, int gubitak)
{
	return (gubitak - dobitak*1.4);
}


void namjesti(int izabrani[], int izvuceni[], int niz[], int optimalno)
{
	int nizovi[POKUSAJI][NUM_DRAWN], index;
	if (optimalno > 0)
		for(int best=300, i=0, bodovi; i<POKUSAJI; i++)
		{
			izvuci(nizovi[i], niz, NUM_DRAWN);
			bodovi = provjera(nizovi[i], izabrani, true);
			if (optimalno - bodovi < best)
			{
				best = optimalno - bodovi;
				index = i;
			}

		}
	else
		for(int min=300, i=0, bodovi; i<POKUSAJI; i++)
		{
			izvuci(nizovi[i], niz, NUM_DRAWN);
			bodovi = provjera(nizovi[i], izabrani, true);
			if (bodovi < min)
			{
				min = bodovi;
				index = i;
			}
		}
	for(int i=0; i<NUM_DRAWN; i++)
		izvuceni[i] = nizovi[index][i];
}


int loto(int stanje, int dobitak, int gubitak, int igranje)
{
	int niz[45], izvuceni[20], izabrani[7], bodovi;
	for(int i=0; i<45; i++)
		niz[i] = i+1;
	std::srand(std::time(0));
	izaberi(izabrani, niz);
	if (check_namjestanje(dobitak, gubitak,  igranje))
	{
		int optimalno = get_optimalno(dobitak, gubitak);
		namjesti(izabrani, izvuceni, niz, optimalno);
	}
	else
		izvuci(izvuceni, niz, NUM_DRAWN);
	prikazi_izvlacenje(izvuceni);
	bodovi = provjera(izvuceni, izabrani);
	std::cout << "Osvojili ste " << bodovi << " bodova." << std::endl;
	std::cout << "Trenutno stanje: " << stanje+bodovi << std::endl << std::endl;
	return bodovi;
}

void printPravilaLoto()
{
	clear_screen();
	std::cout << "PRAVILA: " << std::endl << std::endl << "**********" << std::endl << std::endl << "- Unesite 7 razlicitih brojeva u opsegu od 1 do 45.";
	std::cout << std::endl << "- Mozete i ukucati 'slucajno' za automatsko generisanje 7 brojeva.";
	std::cout << std::endl << "- Za svaki pogodjen broj dobija se (redni_broj_pogotka)*10 bodova." << std::endl << "- Moguce je osvojiti maksimalno 280 bodova." << std::endl;
	std::cout << std::endl << "**********" << std::endl << std::endl;
	std::cout << "Da nastavite, pritisnite ENTER!" << std::endl;
	getchar();
	clear_screen();
}