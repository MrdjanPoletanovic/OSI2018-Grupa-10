
#include "prijava_registracija.h"
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdio>
#include <chrono>
#include <ctime>
#include <random>

bool logIn()
{
    std::cout<<"User name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout<<"Password: ";
    std::string password;
	std::getline(std::cin, password);
    if(provjera(name, password)) return true;
    else return false;
}


void signUp()
{
	std::string korisnickoIme, lozinka;
	bool controlIme, controlLozinka;

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
                for (int k=1; k<=44; k++)
                    getline(datotekaSaNalozima, temp);

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
        for (int k=1; k<=44; k++)
            datotekaSaNalozimaUpis << "\n";
    }

	datotekaSaNalozimaUpis.close();
	return;
}


bool provjera(std::string &userName, std::string &password)
{
    std::ifstream dataBase;
    dataBase.open("nalozi.csv");          //otvaranje csv fajla pod imenom "nalozi"; po potrebi promijeniti naziv fajla
    while(dataBase.good())
    {
        std::string _name, _password;
        getline(dataBase, _name, ',');
        getline(dataBase, _password, '\n');     // pretpostavka da u tabeli postoje samo 2 kolone: username i password
        if(userName.compare(_name)==0 && password.compare(_password)==0)
            return true;
    }
    return false;
}

void printMenu()
{
	std::cout << "SOFT-GAMES\n" << "-----------------------\n";
	std::cout << "-----------------------\n";
	std::cout << "1. Pogadjanje broja\n" << "2. Kviz\n" << "3. Loto\n" << "4. Video Poker\n\n";
	std::cout << "5. Registracija\n" << "6. Prijava\n" << "7. Reset\n" << "8. Statistika\n";
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
	std::cout << "Master Password je " << str << std::endl;
	do
	{
		std::cout << "Unesite MasterPassword: ";
		std::getline(std::cin, MasterPassword);
		if (str.compare(MasterPassword) == 0)
		{
			std::remove("nalozi.csv");
		}
		else
		{
			std::cout << "Pogresan MasterPassword pokusajte ponovo" << std::endl;
		}
	} while (str.compare(MasterPassword) != 0);

}
