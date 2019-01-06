
#include "prijava_registracija.h"
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdio>
#include <chrono>
#include <ctime>
#include <random>

int logIn()
{
	int i = -1, pokusaji = 0;
	std::cout << "\nPRIJAVA:" << std::endl << std::endl;
	do
	{
		pokusaji++;
		std::cout << "User name: ";
		std::string name;
		std::getline(std::cin, name);
		std::cout << "Password: ";
		std::string password;
		std::getline(std::cin, password);
		i = provjera(name, password);
		if (pokusaji < 3 && i == -1 )
			std::cout << std::endl << "Neuspjesna prijava! " << "Preostalo " << 3 - pokusaji << " pokusaja." << std::endl  <<std::endl;
	} while (i == -1 && pokusaji < 3);
	if (pokusaji >= 3)
		std::cout << "\nIskoristili ste sve pokusaje! Ako nemate profil, registrujte se!" << std::endl << std::endl;
	return i;
}


void signUp()
{
	std::string korisnickoIme, lozinka;
	bool controlIme, controlLozinka;
	std::cout << "\nREGISTRACIJA:" << std::endl << std::endl;
	std::cout << "*** Molim unesite korisnicko ime koristeci alfanumericke znakove i simbole tacka (.) ili donja crta (_)";
	std::cout << std::endl << "*** Molim unesite sigurnu lozinku koristeci alfanumericke znakove." << std::endl;
	bool control = true;
	do
	{
		do
		{
			controlIme = true;
			controlLozinka = true;

			std::cin.sync(); // Ciscenje ulaznog bafera.
			std::cout << "\nMolim unesite korisnicko ime: ";
			std::getline(std::cin, korisnickoIme);

			for (int j = 0; j < (int)korisnickoIme.length(); j++) // Provjera da li unijeto korisnicko ime sadrzi nedozvoljene karaktere.
				if (!(isalpha(korisnickoIme.at(j)) || isdigit(korisnickoIme.at(j)) || korisnickoIme.at(j) == '_' || korisnickoIme.at(j) == '.'))
					controlIme = false;

			std::cin.sync(); // Ciscenje ulaznog bafera.
			std::cout << "Molim unesite lozinku: ";
			std::getline(std::cin, lozinka);

			for (int j = 0; j < (int)lozinka.length(); j++)  // Provjera da li unijeta lozinka sadrzi nedozvoljene karaktere.
				if (!(isalpha(lozinka.at(j)) || isdigit(lozinka.at(j))))
					controlLozinka = false;

			std::cout << std::endl;

			if (!controlIme)
				std::cout << "Unijeli ste ime u pogresnom formatu.\n";

			if (!controlLozinka)
				std::cout << "Unijeli ste lozinku u pogresnom formatu.\n";
		} while (!controlIme || !controlLozinka);

		std::ifstream datotekaSaNalozima; // Otvaranje datoteke za iscitavanje naloga kao "Input File Stream".
		datotekaSaNalozima.open("nalozi.csv");

		std::string compareUsername, temp;


		if (datotekaSaNalozima.is_open())
			// Poredjenje naloga iz fajla sa unijetim nalogom.
			while (!datotekaSaNalozima.eof())
			{
				getline(datotekaSaNalozima, compareUsername, ',');
				getline(datotekaSaNalozima, temp);
                /*for (int k=1; k<=44; k++)
                    getline(datotekaSaNalozima, temp);*/

				if (!korisnickoIme.compare(compareUsername))
				{
					std::cout << "\nKorisnicko ime vec postoji.\n";
					control = false;
					break;
				}
				else
					control = true;
			}
	// Zatvaranje datoteke u modu za pisanje.
		datotekaSaNalozima.close();
	} while (!control);
	// Otvaranje datoteke u modu za upisivanje "Output File Stream" u "Append" modu.
	std::ofstream datotekaSaNalozimaUpis;
	datotekaSaNalozimaUpis.open("nalozi.csv", std::ios::app);

	if (control)
    {
		datotekaSaNalozimaUpis << korisnickoIme << ',' << lozinka << '\n'; // Formatiran upis korisnickog imena i lozinke u fajl.
		datotekaSaNalozimaUpis << "10, 0, 0, 0, 0\n" << "0, 0, 0, 0\n" << "0, 0, 0, 0\n" << "0, 0, 0, 0\n";
		for (int i = 0; i < 40; i++)
			datotekaSaNalozimaUpis << "-1, greska, greska\n";
		std::cout << "Uspjesno ste registrovani i mozete se prijaviti na svoj nalog!" << std::endl;
    }

	datotekaSaNalozimaUpis.close();
	return;
}


int provjera(std::string &userName, std::string &password)
{
    std::ifstream dataBase;
	std::string test;
	int i = 0;
    dataBase.open("nalozi.csv");          //otvaranje csv fajla pod imenom "nalozi"; po potrebi promijeniti naziv fajla
    while(dataBase.good())
    {
        std::string _name, _password;
        std::getline(dataBase, _name, ',');
        std::getline(dataBase, _password); // pretpostavka da u tabeli postoje samo 2 kolone: username i password
		if (userName.compare(_name) == 0 && password.compare(_password) == 0)
		{
			dataBase.close();
			return i;
		}
		for (int j = 0; j < 44; j++)
			std::getline(dataBase, test);
		i += 45;
    }
    dataBase.close();
    return -1;
}

void printMenu()
{
	std::cout << "SOFT-GAMES\n" << "-----------------------\n";
	std::cout << "-----------------------\n";
	std::cout << "1. Pogadjanje broja\n" << "2. Kviz\n" << "3. Loto\n" << "4. Video Poker\n\n";
	std::cout << "5. Registracija\n" << "6. Prijava\n" << "7. Reset\n" << "8. Statistika\n" << "9. Otkazivanje igre\n" << "\n0. Izlaz\n";
	std::cout << "-----------------------\n";
	std::cout << "-----------------------\n";

}

void RestartujApl()
{

	std::string MasterPassword, str;
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distributionInteger(0, 9);
	std::string str1;
	for (int i = 0; i < 5; i++)
	{
		int p = distributionInteger(generator);
		str1 = std::to_string(p);
		str.insert(i, str1);
	}
	std::cout << "\nMaster Password: " << str << std::endl;
	int control = 0;
	do
	{
		control++;
		std::cout << "Unesite MasterPassword: ";
		std::getline(std::cin, MasterPassword);
		if (str.compare(MasterPassword) == 0)
		{
			std::remove("nalozi.csv");
			std::cout << "Aplikacija je uspjesno resetovana!" << std::endl;
			break;
		}
		else
		{
			std::cout << "\nPogresan MasterPassword!" << std::endl;
			if(control<3)
				std::cout << "Preostalo " << 3 - control << " pokusaja!" << std::endl <<std::endl;
			else
				std::cout << "Iskoristili ste sve pokusaje!" << std::endl;
		}
	} while (control < 3);
}
