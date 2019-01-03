#include "igrac_igranje.h"
#include "loto.h"
#include "broj.h"
#include "poker.h"
#include "kviz.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include <chrono>

Igrac::Igrac(const std::string& ime, const std::string& sifra) : korisnicko_ime(ime), sifra(sifra), dobitak(0), gubitak(0), stanje(10), pokusajBroj(0), pokusajLoto(0)
{
	otkazan={0};
	prijavljen={0};
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


std::string convertBodoviToMessageKviz (int tacni, int netacni, int neodgovoreni)
{
	char tmp[100];
        snprintf(tmp, sizeof(tmp), "%d tacnih, %d netacnih odgovora i %d neodgovorenih pitanja", tacni, netacni, neodgovoreni);
	std::string poruka = tmp;
	return poruka
}


void Igrac::igraj_kviz()
{
	int bodovi, tacni = 0, netacni = 0, neodgovoreni = 0;
	do
	{
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

bool Igrac::prijava(int redni_broj_igre, std::string& str_gener)
{
	//kontrolna podrazumijeva vrijednost koja se salje iz glavne funkcije i ako ima vrijednost 1 znaci da je igra vec bila aktivirana
	// a ako ima vrijednost 0 znaci da je treba aktivirati
	// str_gener sluzi sa pamcenje generisanog koda u slucaju da se koristi kasnije
	

	std::string str_unos;

	if (redni_broj_igre == 1 && prijava[redni_broj_igre]==0 )
	{
		str_gener = generate("Broj");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			prijava[redni_broj_igre] = 1;
			return true;
		}
		else
			return false;

	}
	else if (redni_broj_igre == 2 && prijava[redni_broj_igre]==0 )
	{
		str_gener = generate("Kviz");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			prijava[redni_broj_igre] = 1;
			return true;
		}
		else
			return false;
	}
	else if (redni_broj_igre == 3 && prijava[redni_broj_igre]==0)
	{
		str_gener = generate("Loto");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			prijava[redni_broj_igre] = 1;
			return true;
		}
		else
			return false;
	}
	else if (redni_broj_igre == 4 && prijava[redni_broj_igre]==0)
	{
		str_gener = generate("Poker");
		std::cout << "Aktivacioni kljuc: " << str_gener << std::endl;
		std::cout << "Unesite aktivacioni kljuc za igru: ";
		std::cin >> str_unos;
		if (str_gener.compare(str_unos) == 0)
		{
			prijava[redni_broj_igre] = 1;
			return true;
		}
		else
			return false;
	}
	else 
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
