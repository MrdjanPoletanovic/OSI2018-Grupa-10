#include "igrac_igranje.h"
#include "prijava_registracija.h"
#include <iostream>
#include "ResApl.h"
#include <cstdio>

int main()
{
	int control;
	bool test;
	std::string control_string;
	std::cout << "Da li zelite da se registrujete ili prijavite ( 1 / 0 )?";
	std::getline(std::cin, control_string);
	control = std::stoi(control_string);
	Igrac i("mrdjan","admin");
	if (control)
	{
		signUp();
		test = true;
		//Igrac i("mrdjan", "admin");
	}
	else
	{
		test = logIn();
		//Igrac i(0);
	}
	if (test)
	{
		i.igraj_broj();
		i.printStatBroj();
		i.igraj_loto();
		i.igraj_poker();
		i.printStatLoto();
		i.printStatPoker();
		//std::cout << "Dobitak: " << i.getDobitak() << std::endl;
		//std::cout << "Gubitak: " << i.getGubitak() << std::endl;
		std::cout << "Stanje: " << i.getStanje() << std::endl;
	}
	else
		std::cout << "Ne mozete igrati!" << std::endl;
	RestartujApl();
	getchar();
	return 0;
}
