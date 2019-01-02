#include "igranje.h"
#include "baza.h"
#include "loto.h"
#include "poker.h"
#include "broj.h"
#include <iostream>
#include <iomanip>
#include <ctime>


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


std::string getTime()
{
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "%d.%m.%Y %H:%M:%S");
	return oss.str();
}


void igraj_loto(KruzniBafer& k, Igrac& i)
{
	int bodovi;
	do
	{
		clear_screen();
		bodovi = loto(i.getStanje(), i.getDobitak(), i.getGubitak(), i.getPL());
		k.enqueue(bodovi, convertBodoviToMessageLoto(bodovi), getTime());
		if (i.getStanje() < 100)
		{
			std::cout << "Nemate dovoljno sredstava da ponovo igrate." << std::endl;
			break;
		}
	}
	while(igraj_ponovo());
}


void igraj_broj(KruzniBafer& k, Igrac& i)
{
	int bodovi;
	do
	{
		clear_screen();
		bodovi = broj(i.getStanje(), i.getDobitak(), i.getPB());
		k.enqueue(bodovi, convertBodoviToMessageBroj(bodovi), getTime());
	}
	while(igraj_ponovo());
}
