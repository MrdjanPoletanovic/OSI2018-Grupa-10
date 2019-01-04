#include "igrac_igranje.h"
#include "prijava_registracija.h"
#include <iostream>


int main()
{
	int control;
	std::string control_string;
	std::cout << "Da li zelite da se registrujete ili prijavite ( 1 / 0 )?";
	std::getline(std::cin, control_string);
	control = std::stoi(control_string);
	if(control)
		signUp();
	if(logIn())
	{
		Igrac i("ime", "password");
		i.igraj_broj();
		i.printStatBroj();
		i.igraj_loto();
		i.igraj_poker();
		i.printStatLoto();
		i.printStatPoker();
		std::cout << "Dobitak: " << i.getDobitak() << std::endl;
		std::cout << "Gubitak: " << i.getGubitak() << std::endl;
		std::cout << "Stanje: " << i.getStanje() << std::endl;
	}
	else
		std::cout << "Ne mozete igrati!" << std::endl;
	getchar();
	return 0;
}
