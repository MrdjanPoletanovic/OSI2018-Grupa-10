#include "igrac_igranje.h"
#include "prijava_registracija.h"
#include <iostream>


int main()
{
	if(logIn())
	{
		Igrac i("ime", "password");
		i.igraj_broj();
		i.printStatBroj();
		//i.igraj_loto();
		//i.igraj_poker();
		//i.printStatLoto();
		//i.printStatPoker();
		std::cout << "Dobitak: " << i.getDobitak() << std::endl;
		std::cout << "Gubitak: " << i.getGubitak() << std::endl;
		std::cout << "Stanje: " << i.getStanje() << std::endl;
	}
	else
		std::cout << "Ne mozete" << std::endl;
	return 0;
}
