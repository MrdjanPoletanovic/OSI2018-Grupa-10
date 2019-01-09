#include "broj.h"
#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include "igrac_igranje.h"

int unos(int i)
{
	int j;
	std::string unos;
	bool dobar;
	int broj;
	do
	{
		std::cout << i << ". pokusaj: ";
		std::getline(std::cin, unos);
		if (unos.compare("") == 0)
		{
			std::cout << "Neispravan unos! Unesite broj izmedju 0 i 100." << std::endl;
			continue;
		}
		for(j = 0; unos[j] == ' '; j++);
		for(broj=0, dobar=true; unos[j]!='\0' && unos[j]!=' ' ; j++)
		{
			if (unos[j] >= '0' && unos[j] <= '9')
			{
				if (broj > 0)
					broj *= 10;
				broj += unos[j] - 0x30;
				if (broj > 100)
				{
					dobar = false;
					break;
				}
			}
			else
			{
				dobar = false;
				break;
			}
		}
		if (dobar)
			return broj;
		else
			std::cout << "Neispravan unos! Unesite broj izmedju 0 i 100." << std::endl;
	}
	while(true);
}



int broj(int pokusaj)
{
	std::srand (std::time(0));
	int zadaniBroj=rand()%100+1;
	int s=rand()%5+1; //s je slucajan broj od 1 do 5 koji odlucuje u kojem pokusaju ce igra omoguciti pogodak (za prva 3 igranja)
	int uneseniBroj,min=0,max=100, bodovi=0; //granice opsega koje se odredjuju tokom igranja
	bool pogodio=false;
	for(int i=1;i<=5;i++)
	{
		uneseniBroj = unos(i);
		if(pokusaj<3 && s==i && s<5 && (uneseniBroj<min || uneseniBroj> max)) s++;
		if (uneseniBroj==zadaniBroj || (pokusaj<3 && s==i && uneseniBroj>min && uneseniBroj<max))
		{
			std::cout<<"Pogodak!! Osvojili ste "<<100/i<<" bodova!!"<<std::endl;
			bodovi=100/i;
			bodovi= 100/i;
			pogodio=true;
			pokusaj++;
			break;
		}
		else if(uneseniBroj>zadaniBroj)
		{
			if(i<5)
				std::cout<<"Trazeni broj je MANJI od unesenog"<<std::endl;
			if(uneseniBroj<max) max=uneseniBroj;
		}
		else if (uneseniBroj<zadaniBroj)
		{
			if(i<5)
				std::cout<<"Trazeni broj je VECI od unesenog"<<std::endl;
			if(uneseniBroj>min) min=uneseniBroj;
		}
	}
	if(pogodio==false)
		std::cout<<"Trazeni broj je "<< zadaniBroj << std::endl;
	return bodovi;
}


bool namjestanje (int pokusaj, int s, int i, int uneseniBroj, int min, int max)
{
     if(pokusaj<3 && s==i && s<5 && (uneseniBroj<min || uneseniBroj> max)) s++;
     if(pokusaj<=3 && s==i && uneseniBroj>min && uneseniBroj<max) return true;
     return false;
}

void printPravilaBroj()
{
	clear_screen();
	std::cout << "PRAVILA: " << std::endl << std::endl << "**********" << std::endl << std::endl << "- Imate 5 pokusaja za pogadjanje trazenog broja.";
	std::cout << std::endl << "- Unosite brojeve od 0 do 100.";
	std::cout << std::endl << "- Tacno pogodjen broj nosi 100/broj_pokusaja bodova." << std::endl << "- Nema negativnih bodova." << std::endl ;
	std::cout << std::endl  << "**********" << std::endl << std::endl;
	std::cout << "Da nastavite, pritisnite ENTER!" << std::endl;
	getchar();
	clear_screen();
}