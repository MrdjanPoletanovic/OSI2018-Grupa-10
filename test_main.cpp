#include "igrac_igranje.h"
#include "prijava_registracija.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
	int control, test;
	bool first_time = false;
	std::string opcija;
	std::string control_string;
	std::cout << "Da li zelite da se registrujete ili prijavite ( 1 / 0 )?";
	std::getline(std::cin, control_string);
	control = std::stoi(control_string);
	if (control)
	{
		signUp();
		first_time = true;
	}
	test = logIn();
	if (test > -1)
	{
		Igrac i(test, first_time);
		do
		{
			clear_screen();
			printMenu();
			std::cout << "STANJE: " << i.getStanje() << std::endl;
			do
			{
				std::cout << "Izaberite opciju:";
				std::getline(std::cin, opcija);
			} while (opcija != "1" && opcija != "2" && opcija != "3" && opcija != "4" && opcija != "5" && opcija != "6" && opcija != "7" && opcija != "8" && opcija != "9" && opcija!="10");
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
				i.writePodaci();
				signUp();
				test = logIn();
				std::cout << test << std::endl;
				first_time = true;
				i = Igrac(test, first_time);
			}
			else if (opcija == "6")
			{
				i.writePodaci();
				test = logIn();
				std::cout << test << std::endl;
				first_time = false;
				i = Igrac(test, first_time);
			}
			else if (opcija == "7")
			{
				std::cout << "\nOva opcija podrazumijeva vracanje aplikacije na fabricka podesavanja.\nDa li ste sigurni da zelite nastaviti?\n";
				std::cout << "Unesite DA ako zelite nastaviti proces resetovanja: ";
				std::string str;
				std::getline(std::cin, str);
				if (!str.compare("Da") || !str.compare("da") || !str.compare("DA") || !str.compare("dA"))
					RestartujApl();
				else
					std::cout << "Aplikacija nece biti resetovana!\n";
			}
			else if (opcija == "8")
			{
				i.writePodaci();
				i.printAllStat();
				getchar();
			}
			else if (opcija == "9")
			{
				i.otkazi();
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(4000));
			clear_screen();
		} while (opcija != "10");
		i.writePodaci();
	}
	else
		std::cout << "Ne mozete igrati!" << std::endl;
	getchar();
	return 0;
}