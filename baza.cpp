#include "baza.h"
#include <string>
#include <iostream>


void clear_screen()
{
#ifdef _WIN32
	std::system("cls");
#elif _WIN64
    std::system("cls");
	// Assume POSIX;
#else
	std::system ("clear");
#endif
}


bool igraj_ponovo()
{
	int i = 0;
	std::string odgovor;
	do
	{
		std::cout << "Da li zelite ponovo da igrate? (da/ne) ";
		std::getline(std::cin, odgovor);
		for(i=0; odgovor[i]==' '; i++);
		if ((odgovor[i] == 'd' || odgovor[i] == 'D') &&
		    (odgovor[i+1] == 'a' || odgovor[i+1] == 'A'))
			return true;
		else if ((odgovor[i] == 'n' || odgovor[i] == 'N') &&
			 (odgovor[i+1] == 'e' || odgovor[i+1] == 'E'))
			return false;
		std::cout << "Neispravan unos!" << std::endl;
	}
	while(true);
}
