#include "pch.h"
#include "Prijava_na_igru.h"
#include "Generate.h"
#include <iostream>
bool prijava(int redni_broj_igre, int& kontrolna, std::string& str_gener)
{
	//kontrolna podrazumijeva vrijednost koja se salje iz glavne funkcije i ako ima vrijednost 1 znaci da je igra vec bila aktivirana
	// a ako ima vrijednost 0 znaci da je treba aktivirati
	// str_gener sluzi sa pamcenje generisanog koda u slucaju da se koristi kasnije
	

	std::string str_unos;

	if (redni_broj_igre == 1 && kontrolna!=1)
	{
		str_gener = generate("Broj");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			kontrolna = 1;
			return true;
		}
		else
			return false;

	}
	else if (redni_broj_igre == 2 && kontrolna != 1)
	{
		str_gener = generate("Kviz");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			kontrolna = 1;
			return true;
		}
		else
			return false;
	}
	else if (redni_broj_igre == 3 && kontrolna != 1)
	{
		str_gener = generate("Loto");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			kontrolna = 1;
			return true;
		}
		else
			return false;
	}
	else if (redni_broj_igre == 4 && kontrolna != 1)
	{
		str_gener = generate("Poker");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			kontrolna = 1;
			return true;
		}
		else
			return false;
	}
	else 
		return false;

}