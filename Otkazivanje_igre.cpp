#include "pch.h"
#include "Otkazivanje_igre.h"
#include <iostream>

void otkazi_igru(int redni_broj, int *kontrolni_niz)
{
	*(kontrolni_niz + (redni_broj - 1)) = 1;
	if (redni_broj == 1)
	{
		std::cout << "Vise nemate pristup igri: Pogadjanje broja!\n";
	}
	else if (redni_broj == 2)
	{
		std::cout << "Vise nemate pristup igri: Kviz!\n";
	}
	else if (redni_broj == 3)
	{
		std::cout << "Vise nemate pristup igri: Loto!\n";
	}
	else if (redni_broj == 4)
	{
		std::cout << "Vise nemate pristup igri: Video Poker!\n";
	}
}
