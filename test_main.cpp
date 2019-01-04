#include "igrac_igranje.h"
#include "prijava_registracija.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
	int control;
	bool test;
	std::string opcija;
	std::string control_string;
	std::cout << "Da li zelite da se registrujete ili prijavite ( 1 / 0 )?";
	std::getline(std::cin, control_string);
	control = std::stoi(control_string);
	Igrac i("mrdjan", "admin");
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
		do
		{

			printMenu();
			do
			{
				std::cout << "Izaberite opciju:";
				std::getline(std::cin, opcija);
			} while (opcija != "1" && opcija != "2" && opcija != "3" && opcija != "4" && opcija != "5" && opcija != "6" && opcija != "7" && opcija != "8" && opcija != "9");
			if (opcija == "1")
			{
				i.igraj_broj();
				
				
			}
			else if (opcija == "2")
			{
				i.igraj_kviz();
				
				
			}
			else if (opcija == "3")
			{
				i.igraj_loto();
				
				
			}
			else if (opcija == "4")
			{
				i.igraj_poker();
				
				
			}
			else if (opcija == "5")
			{
				signUp();
			}
			else if (opcija == "6")
			{
				logIn();
			}
			else if (opcija == "7")
			{
				RestartujApl();
			}
			else if (opcija == "8")
			{
				i.printStatBroj();
				i.printStatKviz();
				i.printStatLoto();
				i.printStatPoker();
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			clear_screen();
		} while (opcija != "9");

		//std::cout << "Dobitak: " << i.getDobitak() << std::endl;
		//std::cout << "Gubitak: " << i.getGubitak() << std::endl;
		std::cout << "Stanje: " << i.getStanje() << std::endl;
	}
	else
		std::cout << "Ne mozete igrati!" << std::endl;
	getchar();
	return 0;
}