#include "igrac_igranje.h"
#include "loto.h"
#include "broj.h"
#include "poker.h"
#include <iostream>
#include <iomanip>
#include <ctime>


Igrac::Igrac(const std::string& ime, const std::string& sifra) : korisnicko_ime(ime), sifra(sifra), dobitak(0), gubitak(0), stanje(100), pokusajBroj(0), pokusajLoto(0)
{}


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
	int bodovi;
	do
	{
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
	}
	while(igraj_ponovo());
}


void Igrac::igraj_broj()
{
	int bodovi;
	do
	{
		clear_screen();
		bodovi = broj(pokusajBroj);
		pokusajBroj++;
		stanje+=bodovi;
		dobitak+=bodovi;
		nizovi[0].enqueue(bodovi, convertBodoviToMessageBroj(bodovi), getTime());
	}
	while(igraj_ponovo());
}


void Igrac::igraj_poker()
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


bool igraj_ponovo()
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
