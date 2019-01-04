#define _CRT_SECURE_NO_WARNINGS 
#include "igrac_igranje.h"
#include "loto.h"
#include "broj.h"
#include "poker.h"
#include "kviz.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <random>
#include <chrono>
#include <sstream>

Igrac::Igrac(const std::string& ime, const std::string& sifra) : korisnicko_ime(ime), sifra(sifra), dobitak(0), gubitak(0), stanje(10), pokusajBroj(0), pokusajLoto(0)
{
	for(int i=0; i<4; i++)
	{
		prijavljen[i] = otkazan[i] = 0;
		vrijeme_igranja[i] = 0;
	}
}


Igrac::Igrac(int line)
{
	std::ifstream file("nalozi.csv");
	if (file.is_open())
	{
		std::string tmp;
		for(int i=0; i<line; i++)
			std::getline(file, tmp);
		std::getline(file, tmp, ',');
		korisnicko_ime = tmp;
		std::getline(file, tmp);
		sifra = tmp;
		std::getline(file, tmp, ',');
		stanje = std::stoi(tmp);
		std::getline(file, tmp, ',');
		gubitak = std::stoi(tmp);
		std::getline(file, tmp, ',');
		dobitak = std::stoi(tmp);
		std::getline(file, tmp, ',');
		pokusajBroj= std::stoi(tmp);
		std::getline(file, tmp);
		pokusajLoto = std::stoi(tmp);
		for(int i=0; i<4; i++)
		{
			if (i != 3)
				std::getline(file, tmp, ',');
			else
				std::getline(file, tmp);
			otkazan[i] = std::stoi(tmp);
		}
		for(int i=0; i<4; i++)
		{
			if (i != 3)
				std::getline(file, tmp, ',');
			else
				std::getline(file, tmp);
			prijavljen[i] = std::stoi(tmp);
		}
		for(int i=0; i<4; i++)
		{
			if (i != 3)
				std::getline(file, tmp, ',');
			else
				std::getline(file, tmp);
			vrijeme_igranja[i] = std::stod(tmp);
		}
		for(int i=0; i<4; i++)
			nizovi[i] = KruzniBafer(file);
		file.close();
	}
}


std::string convertBodoviToMessageLoto(int x)
{
	std::string poruka;
	switch(x)
	{
	case 0:
	{
		poruka = "Nije pogodjen nijedan broj.";
		break;
	}
	case 10:
	{
		poruka = "Pogodjen 1 broj";
		break;
	}
	case 30:
	{
		poruka = "Pogodjena 2 broja";
		break;
	}
	case 60:
	{
		poruka = "Pogodjena 3 broja";
		break;
	}
	case 100:
	{
		poruka = "Pogodjena 4 broja";
		break;
	}
	case 150:
	{
		poruka = "Pogodjeno 5 brojeva";
		break;
	}
	case 210:
	{
		poruka = "Pogodjeno 6 brojeva";
		break;
	}
	case 280:
	{
		poruka = "Pogodjeno 7 brojeva";
	}
	}
	return poruka;
}


std::string convertBodoviToMessageBroj(int bodovi)
{
	std::string poruka;
	if (bodovi > 0)
	{
		char tmp[100];
		snprintf(tmp, sizeof(tmp), "Pogodjeno iz %d. pokusaja", 100/bodovi);
		poruka = tmp;
	}
	else
	{
		poruka = "Broj nije pogodjen.";
	}
	return poruka;
}


std::string convertBodoviToMessagePoker(int bodovi)
{
	std::string poruka;
	switch(bodovi)
	{
	case 4000:
		poruka = "Royal Flush";
		break;
	case 250:
		poruka = "Straight Flush";
		break;
	case 125:
		poruka = "Poker";
		break;
	case 45:
		poruka = "Full House";
		break;
	case 30:
		poruka = "Flush";
		break;
	case 20:
		poruka = "Straight";
		break;
	case 15:
		poruka = "Three of a Kind";
		break;
	case 10:
		poruka = "Two Pairs";
		break;
	case 5:
		poruka = "Jack's or Better";
		break;
	default:
		poruka = "Nista niste osvojili";
	}
	return poruka;
}


std::string getTime()
{
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "%d.%m.%Y %H:%M:%S");
	return oss.str();
}


void Igrac::igraj_loto()
{
	if (otkazan[2] == 0)
	{
		if (prijava(3))
		{
			int bodovi;
			time_t start, end=std::time(0);
			do
			{
				start = end;
				if (stanje < 100)
				{
					std::cout << "Nemate dovoljno sredstava da igrate loto." << std::endl;
					break;
				}
				clear_screen();
				stanje-=100;
				gubitak+=100;
				pokusajLoto++;
				bodovi = loto(stanje, dobitak, gubitak, pokusajLoto);
				dobitak+=bodovi;
				stanje+=bodovi;
				nizovi[2].enqueue(bodovi, convertBodoviToMessageLoto(bodovi), getTime());
				end = std::time(0);
			}
			while(provjera_kljuca(3, start, end) && igraj_ponovo());
		}
	}
	else
		std::cout << "Igra je otkazana. Ne mozete je vise igrati" << std::endl;
}


void Igrac::igraj_broj()
{
	if (otkazan[0] == 0)
	{
		if (prijava(1))
		{
			int bodovi;
			time_t start, end=std::time(0);
			do
			{
				start = end;
				clear_screen();
				bodovi = broj(pokusajBroj);
				pokusajBroj++;
				stanje+=bodovi;
				dobitak+=bodovi;
				nizovi[0].enqueue(bodovi, convertBodoviToMessageBroj(bodovi), getTime());
				end = std::time(0);
			}
			while(provjera_kljuca(1, start, end) && igraj_ponovo());
		}
	}
	else
		std::cout << "Igra je otkazana. Ne mozete je vise igrati" << std::endl;
}


void Igrac::igraj_poker()
{
	if (otkazan[3] == 0)
	{
		if (prijava(4))
		{
			int bodovi;
			do
			{
				if (stanje < 5)
				{
					std::cout << "Nemate dovoljno sredstava da igrate poker." << std::endl;
					break;
				}
				clear_screen();
				gubitak += 5;
				stanje -= 5;
				bodovi = poker(stanje, dobitak, gubitak);
				nizovi[3].enqueue(bodovi, convertBodoviToMessagePoker(bodovi), getTime());
				dobitak += bodovi;
				stanje += bodovi;
			}
			while(igraj_ponovo());
		}
	}
	else
		std::cout << "Igra je otkazana. Ne mozete je vise igrati" << std::endl;
}


std::string convertBodoviToMessageKviz (int tacni, int netacni, int neodgovoreni)
{
	char tmp[100];
        snprintf(tmp, sizeof(tmp), "%d tacnih, %d netacnih odgovora i %d neodgovorenih pitanja", tacni, netacni, neodgovoreni);
	std::string poruka = tmp;
	return poruka;
}


void Igrac::igraj_kviz()
{
	if (otkazan[1] == 0)
	{
		if (prijava(2))
		{
			int bodovi, tacni = 0, netacni = 0, neodgovoreni = 0;
			time_t start, end = std::time(0);
			do
			{
				start = end;
				if (stanje < 5) // Potrebno znati koliko bodova je potrebno za kviz.
				{
					std::cout << "Nemate dovoljno sredstava da igrate kviz." << std::endl;
					break;
				}
				clear_screen();
				stanje -= 5;
				bodovi = kviz(stanje, tacni, netacni, neodgovoreni);
				nizovi[1].enqueue(bodovi, convertBodoviToMessageKviz(tacni, netacni, neodgovoreni), getTime());
				stanje += bodovi;
				dobitak += bodovi;
				end = std::time(0);
			} while (provjera_kljuca(2, start, end) && igraj_ponovo());
		}
	}
}



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


bool Igrac::igraj_ponovo()
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


bool Igrac::prijava(int redni_broj_igre)
{
	//kontrolna podrazumijeva vrijednost koja se salje iz glavne funkcije i ako ima vrijednost 1 znaci da je igra vec bila aktivirana
	// a ako ima vrijednost 0 znaci da je treba aktivirati
	// str_gener sluzi sa pamcenje generisanog koda u slucaju da se koristi kasnije
	std::string str_gener;
	if (prijavljen[redni_broj_igre-1] == 0)
	{
		std::string str_unos;
		if (redni_broj_igre == 1)
		{
			str_gener = generate("Broj");
			std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
			std::cout << "Unesite aktivacioni kljuc za igru: ";
		}
		else if (redni_broj_igre == 2)
		{
			str_gener = generate("Kviz");
			std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
			std::cout << "Unesite aktivacioni kljuc za igru: ";
		}
		else if (redni_broj_igre == 3)
		{
			str_gener = generate("Loto");
			std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
			std::cout << "Unesite aktivacioni kljuc za igru: ";
		}
		else if (redni_broj_igre == 4)
		{
			str_gener = generate("Poker");
			std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
			std::cout << "Unesite aktivacioni kljuc za igru: ";
		}
		std::getline(std::cin, str_unos);
		if (str_gener.compare(str_unos) == 0)
		{
			prijavljen[redni_broj_igre-1] = 1;
			return true;
		}
		else
		{
			std::cout << "Aktivacija igre neuspjesna. Pokusajte ponovo." << std::endl;
		}
	}
	return false;
}


void Igrac::fill(std::string& str)
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distributionInteger(0, 9);
	std::string str1;
	for (int i = 5; i < 19; i++)
	{
		if (i == 9 || i == 14)
			str.insert(i,"-");
		else
		{
			int p = distributionInteger(generator);
			str1 = std::to_string(p);
			str.insert(i, str1);
		}
	}

}


std::string Igrac::generate(std::string s)
{
	std::string key;
	if (s.compare("Loto")==0 )
	{
		key = "3168-";   //broj 3 oznacava redni broj igre, a 168 vrijeme trajanja igre izrazeno u satima
		fill(key);
	}
	else if (s.compare("Broj") == 0)
	{
		key = "1024-";  // broj 1 oznacava redni broj igre, a 024 vrijeme trajanja igre izrazeno u satima
		fill(key);
	}
	else if (s.compare("Kviz") == 0)
	{
		key = "2001-";  // broj 2 oznacava redni broj igre, a 001 vrijeme trajanja igre izrazeno u satima
		fill(key);
	}
	else if (s.compare("Poker") == 0)
	{
		key = "4000-"; //  broj 4 oznacava redni broj igre, a 000 neograniceno trajanje igre
		fill(key);
	}
	return key;
}


void Igrac::otkazi_igru(int redni_broj)
{
	otkazan[redni_broj-1] = 1;
	if (redni_broj == 1)
	{
		std::cout << "Vise nemate pristup igri: Pogadjanje broja!\n";
	}
	else if (redni_broj == 2)
	{
		std::cout << "Vise nemate pristup igri: Kviz!\n";
	}
	else if (redni_broj == 3)
	{
		std::cout << "Vise nemate pristup igri: Loto!\n";
	}
	else if (redni_broj == 4)
	{
		std::cout << "Vise nemate pristup igri: Video Poker!\n";
	}
}


bool Igrac::provjera_kljuca(int redni_broj, time_t begin, time_t end)
{
	double vrijeme = 0;
	int index = redni_broj-1;
	if (redni_broj == 1)
	{
		vrijeme = 86'400;
		vrijeme_igranja[index] += difftime(end, begin);
		if (vrijeme_igranja[index] >= vrijeme)
		{
			otkazi_igru(redni_broj);
			return false;
		}
		else
			return true;
	}
	else if (redni_broj == 2)
	{
		vrijeme = 3'600;
		vrijeme_igranja[index] += difftime(end, begin);
		if (vrijeme_igranja[index] >= vrijeme)
		{
			otkazi_igru(redni_broj);
			return false;
		}
		else
			return true;
	}
	else if (redni_broj == 3)
	{
		vrijeme = 604'800;
		vrijeme_igranja[index] += difftime(end, begin);
		if (vrijeme_igranja[index] >= vrijeme)
		{
			otkazi_igru(redni_broj);
			return false;
		}
		else
			return true;
	}
	else if (redni_broj == 4)
	{
		return true;
	}
	else
		return false;
}


int Igrac::findName() const
{
	std::ifstream file("nalozi.csv");
	if (file.is_open())
	{
		int line = 0;
		std::string tmp;
		while(std::getline(file, tmp, ','))
		{
			if (tmp == korisnicko_ime)
				return line;
			std::getline(file, tmp);
			for(int i=0; i<44; i++)
				std::getline(file, tmp);
		}
	}
	return -1;
}


void Igrac::writePodaci() const
{
	write(findName());
}


Igrac::~Igrac()
{
	//write(findName());
}


void Igrac::write(int line) const
{
	std::fstream file;
	if (line == -1)
		file.open("nalozi.csv", std::ios::app);
	else
	{
		std::string tmp;
		file.open("nalozi.csv");
		for(int i=0; i<line; i++)
			std::getline(file, tmp);
	}
	file << korisnicko_ime << "," << sifra << "\n";
	file << stanje << "," << gubitak << "," << dobitak << "," << pokusajBroj << "," << pokusajLoto << "\n";
	for(int i=0; i<4; i++)
	{
		if (i != 3)
			file << otkazan[i] << ",";
		else
			file << otkazan[i] << "\n";
	}
	for(int i=0; i<4; i++)
	{
		if (i != 3)
			file << prijavljen[i] << ",";
		else
			file << prijavljen[i] << "\n";
	}
	for(int i=0; i<4; i++)
	{
		if (i != 3)
			file << vrijeme_igranja[i] << ",";
		else
			file << vrijeme_igranja[i] << "\n";
	}
	for(int i=0; i<4; i++)
		nizovi[i].writeToFile(file);
}
