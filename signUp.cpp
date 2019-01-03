#include "signUp.h"

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

void signUp()
{
	string korisnickoIme = "", lozinka = "";
	bool controlIme, controlLozinka;

	cout << "*** Molim unesite korisnicko ime koristeci alfanumericke znakove i simbole tacka (.) ili donja crta (_)";
	cout << std::endl << "*** Molim unesite sigurnu lozinku koristeci alfanumericke znakove." << std::endl;

	do
	{
		controlIme = true;
		controlLozinka = true;

		cin.sync(); // Ciscenje ulaznog bafera.
		cout << "\nMolim unesite korisnicko ime: ";
		cin >> korisnickoIme;

		for (int j = 0; j < (int)korisnickoIme.length(); j++) // Provjera da li unijeto korisnicko ime sadrzi nedozvoljene karaktere.
			if (!(isalpha(korisnickoIme.at(j)) || isdigit(korisnickoIme.at(j)) || korisnickoIme.at(j) == '_' || korisnickoIme.at(j) == '.'))
				controlIme = false;

		cin.sync(); // Ciscenje ulaznog bafera.
		cout << "Molim unesite lozinku: ";
		cin >> lozinka;

		for (int j = 0; j < (int)lozinka.length(); j++)  // Provjera da li unijeta lozinka sadrzi nedozvoljene karaktere.
			if (!(isalpha(lozinka.at(j)) || isdigit(lozinka.at(j))))
				controlLozinka = false;

		cout << std::endl;

		if (!controlIme)
			cout << "Unijeli ste ime u pogresnom formatu.\n";

		if (!controlLozinka)
			cout << "Unijeli ste lozinku u pogresnom formatu.\n";
	}
	while (!controlIme || !controlLozinka);

	std::ifstream datotekaSaNalozima; // Otvaranje datoteke za iscitavanje naloga kao "Input File Stream".
	datotekaSaNalozima.open("nalozi.csv");

	string compareUsername, demPassword;
	bool control = true;

	if (datotekaSaNalozima.is_open())
		// Poredjenje naloga iz fajla sa unijetim nalogom.
		while(!datotekaSaNalozima.eof())
		{
			getline(datotekaSaNalozima, compareUsername, ',');
			getline(datotekaSaNalozima, demPassword);

			if (!korisnickoIme.compare(compareUsername))
			{
				cout << "\nKorisnicko ime vec postoji.\n";
				control  = false;
				break;
			}
		}
	// Zatvaranje datoteke u modu za pisanje.
	datotekaSaNalozima.close();

	// Otvaranje datoteke u modu za upisivanje "Output File Stream" u "Append" modu.
	std::ofstream datotekaSaNalozimaUpis;
	datotekaSaNalozimaUpis.open("nalozi.csv", std::ios::app);

	if (control)
		datotekaSaNalozimaUpis << korisnickoIme << ',' << lozinka << '\n'; // Formatiran upis korisnickog imena i lozinke u fajl.

	datotekaSaNalozimaUpis.close();

	return;
}

