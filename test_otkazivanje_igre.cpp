
#include "pch.h"
#include <iostream>
#include "Otkazivanje_igre.h"

int main()
{


	int niz[4] = { 0 };
	otkazi_igru(1, niz);
	for (int x : niz)
		std::cout << x << " ";
	std::cout << std::endl;
	otkazi_igru(3, niz);
	for (int x : niz)
		std::cout << x << " ";
	std::cout << std::endl;
}