
#include "pch.h"
#include <iostream>
#include <string>
#include "Provjera_trajanja_kljuca.h"

int main()
{
	time_t timer;
	time(&timer);
	std::string str;
	std::cin >> str;//manipulacija vremenom
	time_t timer2;
	time(&timer2);
	double vrijeme = 3'590; // vrijeme koje predstavlja broj sekundi provjedenih igrajuci
	std::cout << "VRIJEME: " << timer << "   " << timer2 << "\n";
	if (provjera_kljuca(2, timer, timer2, vrijeme))
		std::cout << "TRAJE"; 
	else
		std::cout << "NE TRAJE"; // poziv funkcije otkazi igru i slicno
}