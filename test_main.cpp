#include "igrac_igranje.h"
#include "prijava_registracija.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
	int test;
	bool first_time = false;
	std::string opcija;
	std::string control_string;
	ponovo:
	std::cout << "Da li zelite da se registrujete ili prijavite?" << std::endl;
	std::cout << "Unesite 1 za registraciju, a 0 za prijavu: ";
	std::getline(std::cin, control_string);
	if (control_string.compare("1") == 0)
	{
		clear_screen();
		signUp();
		first_time = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		clear_screen();
	}
	else if (control_string.compare("0"))
	{
		std::cout << std::endl << "Neispravan unos! Bicete automatski proslijedjeni na prijavu!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		first_time = false;
	}
	clear_screen();
	while ((test = logIn()) == -1)
	{
		first_time = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		clear_screen();
		signUp();
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		clear_screen();
	}
	Igrac i = Igrac(test, first_time);
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	do
	{
		clear_screen();
		printMenu();
		std::cout << "STANJE: " << i.getStanje() << std::endl << std::endl;
		do
		{
			std::cout << "Izaberite opciju: ";
			std::getline(std::cin, opcija);
		} while (opcija != "1" && opcija != "2" && opcija != "3" && opcija != "4" && opcija != "5" && opcija != "6" && opcija != "7" && opcija != "8" && opcija != "9" && opcija != "0");
		if (opcija == "1")
		{
			i.igraj_broj();
			i.writePodaci();

		}
		else if (opcija == "2")
		{
			i.igraj_kviz();
			i.writePodaci(); //upis podataka u toku igranja mozda, jer ako se izadje na x ne izvrsi se upis u datoteku sa novim stanjem

		}
		else if (opcija == "3")
		{
			i.igraj_loto();
			i.writePodaci();

		}
		else if (opcija == "4")
		{
			i.igraj_poker();
			i.writePodaci();

		}
		else if (opcija == "5")
		{
			i.writePodaci();
			clear_screen();
			signUp();
			test = logIn();
			first_time = true;
			i = Igrac(test, first_time);
		}
		else if (opcija == "6")
		{
			i.writePodaci();
			clear_screen();
			test = logIn();
			first_time = false;
			i = Igrac(test, first_time);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
		else if (opcija == "7")
		{
			clear_screen();
			std::cout << "\nOva opcija podrazumijeva vracanje aplikacije na fabricka podesavanja i brisanje svih podataka." << std::endl;
			std::cout << "Unesite DA ako zelite nastaviti proces resetovanja: ";
			std::string str;
			std::getline(std::cin, str);
			if (!str.compare("Da") || !str.compare("da") || !str.compare("DA") || !str.compare("dA"))
			{
				RestartujApl();
				clear_screen();
				goto ponovo;
			}
			else
				std::cout << "Aplikacija nece biti resetovana!\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1100));
		}
		else if (opcija == "8")
		{
			i.writePodaci();
			clear_screen();
			i.printAllStat();
			std::cout << "Pritisnite ENTER da nastavite!\n";
			getchar();
		}
		else if (opcija == "9")
		{
			clear_screen();
			i.otkazi();
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		}
		clear_screen();
	} while (opcija != "0");
	return 0;
}
