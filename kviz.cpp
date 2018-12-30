#include "kviz.h"
#include "baza.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cmath>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::sort;


// Funkcija za formatirano upisivanje pitanja, odgovora i rednog broja tacnog odgovora u .CSV fajl.
void pisanjePitanjaCSV()
{
	ofstream datotekaZaUpisPitanja; // Output file stream.
	datotekaZaUpisPitanja.open("pitanja.csv");

	if (datotekaZaUpisPitanja.is_open()) // Prevencija greske pri otvaranju datoteke u modu za pisanje.
	{
		datotekaZaUpisPitanja << 1 << ". Ko je izumio parnu masinu?\n1. James Voltage\n2. James Watt\n3. James Steam\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 2 << ". Koja planeta je najbliza suncu?\n1. Mars\n2. Venera\n3. Merkur\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 3 << ". Koje godine je izgradjen berlinski zid?\n1. 1962\n2. 1961\n3. 1960\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 4 << ". Koji od navedenih filmova je osvojio najvise Oskara?\n1. Ben-Hur\n2. Casablanca\n3. Dorucak kod Tifani\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 5 << ". Koje godine je Google postavljen na Web?\n1. 1997\n2. 1998\n3. 2000\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 6 << ". Koji kanadski reper se nalazio na vrhu top lista u februaru 2018 sa singlom God's Plan?\n1. Drake\n2. Dr.Dre\n3. KanyeWest\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 7 << ". Ko je izjavio: Mislim, dakle postojim?\n1. Rene Dekart\n2. Aristotel\n3. Euklid\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 8 << ". Na kom italijanskom ostvru se nalazi Palermo?\n1. Sardinija\n2. Sicilija\n3. Lipari\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 9 << ". Kako se zvala protestantska revolucija protiv dominacije pape?\n1. Inkvizicija\n2. Protest\n3. Reformacija\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 10 << ". Sta je po profesiji Popaj?\n1. Mornar\n2. Lovac\n3. Vatrogasac\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 11 << ". Ko je otkrio penicilin?\n1. Mihajlo Pupin\n2. Aleksandar Fleming\n3. Carls Darvin\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 12 << ". Kakva je RAM memorija?\n1. Virtuelna\n2. Sa kontrolom pristupa\n3. Sa slucajnim pristupom\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 13 << ". Iz koje zemlje potice koktel Mohito?\n1. Venecuele\n2. Kube\n3. Spanije\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 14 << ". Voda kljuca na 212 stepeni koje temperaturne skale?\n1. Farenhajtove\n2. Kelvinove\n3. Rankinove\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 15 << ". Koje godine je zavrsena francuska revolucija?\n1. 1798\n2. 1777\n3. 1799\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 16 << ". Ptica feniks je simbol:\n1. Pustosenja\n2. Besmrtnosti\n3. Mudrosti\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 17 << ". Poznatu recenicu \"Ne prekidaj neprijatelja dok grijesi\", izgovorio je:\n1. Aleksandar Makedonski\n2. Vinston Cercil\n3. Napoleon\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 18 << ". Prije nego sto je uzela ime \"Riblja Corba\", ova grupa se zvala:\n1. TNT\n2. Greh\n3. SOS\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 19 << ". \"Aceto balsamico\" je:\n1. Sirce\n2. Biljka\n3. Ulje\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 20 << ". Kakvu vlast ima vlada Republike Srbije?\n1. Apsolutnu\n2. Parlamentarnu\n3. Izvrsnu\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 21 << ". Jedna kopnena milja je duga oko:\n1. 1.6 km\n2. 1.4 km\n3. 1.7 km\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 22 << ". U kom okrugu se nalazi Dimitrovgrad?\n1. Pirotskom\n2. Moravskom\n3. Niskom\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 23 << ". Drzava Zimbabve se ranije zvala:\n1. Zair\n2. Dahomej\n3. Rodezija\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 24 << ". Ko je autor pjesme \"Cekaj me\" ?\n1. Milos Crnjanski\n2. Desanka Maksimovic\n3. Konstantin Simonov\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 25 << ". Ko je napisao knjigu \"Noz\" ?\n1. Vuk Draskovic\n2. Mesa Selimovic\n3. Dobrica Cosic\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 26 << ". Koji je sledeci broj u nizu: 1, 4, 9, 16, 25, 36... ?\n1. 81\n2. 47\n3. 49\n" << 3 << "\n\n";
		datotekaZaUpisPitanja << 27 << ". Srebrena planina ili:\n1. Tara\n2. Kopaonik\n3. Jahorina\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 28 << ". Za koji od klubova nije igrao Predrag Danilovic?\n1. Miami Heat\n2. Olimpijakos\n3. Partizan\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << 29 << ". Hemijska oznaka za zivu je:\n1. Hg\n2. Pb\n3. Zv\n" << 1 << "\n\n";
		datotekaZaUpisPitanja << 30 << ". Ko je pisao o trougaonim brojevima? \n1. Euklid\n2. Pitagora\n3. Dekart\n" << 2 << "\n\n";
		datotekaZaUpisPitanja << EOF;
	}
	else cout << "\nError: Datoteka za upis pitanja nije uspjesno otvorena!\n";

	datotekaZaUpisPitanja.close();
}

// String to integer.
int stoi (string s)
{
    int suma=0;
    for (int i=0, p=1; s[i]; i++)
    {
        suma = suma * p + s[i] - 0x30;
        p*=10;
    }
    return suma;
}

// Funkcija za ispis jednog pitanja sa ponudjenim odgovorima na izlaz.
void pisiPitanjeIOdgovore(PITANJA X, int Y)
{
	cout << "-------------------------------------------" << endl;
	cout << "IMATE 15 SEKUNDI DA ODGOVORITE NA PITANJE !" << endl << endl;
	cout << Y << X.pitanje << endl;
	cout << endl << "\t" << X.odgovori[0] << endl << "\t" << X.odgovori[1] << endl << "\t" << X.odgovori[2] << endl;
}

// Funkcija koja vraca TRUE ako registruje pritisak na dugme i upisuje pritisnuto dugme na adresu karaktera 'prviKarakter' ili vraca FALSE ako dugme nije pritisnuto prije zavrsnog vremena.
bool pritisakNaDugme(DWORD zavrsnoVrijeme, char &prviKarakter)
{
	HANDLE pokazivacNaStandardniUlaz = GetStdHandle(STD_INPUT_HANDLE); // "HANDLE" je pokazivac na void -- "GetStdHandle();" vraca HANDLE na Windows objekat, u ovom slucaju, standardni ulaz.
	DWORD brojEventova = 0; // "DWORD" je programski tip definisan u Windowsu, aka "Double Word".
	INPUT_RECORD strukturaUlaza = { 0 }; // "INPUT_RECORD" je stuktura sa mogucim ulazima: "Key", "Mouse", "Windows Buffer Size", "Menu" and "Focus".
	DWORD brojUlaza = 0; // Varijabla potrebna za poziv funkcije "ReadConsoleInput();" u koju se upisuje broj procitanih ulaznih podataka.

	while (GetTickCount() < zavrsnoVrijeme) // Funkcija se izvrsava dok god je trenutno vrijeme manje od zavrsnog.
	{
		if (brojEventova > 0) // Provjera da li je "GetNumberOfConsoleInputEvents();" vratio pozitivan rezultat, aka. da li je neki od ulaza iz struktureUlaza aktiviran.
		{
			ReadConsoleInput(pokazivacNaStandardniUlaz, &strukturaUlaza, 1, &brojUlaza); // Cita podatke iz bafera kontrolnog ulaza i cisti bafer.
			if (strukturaUlaza.EventType == KEY_EVENT) // Provjera da li je ulaz koji je bio aktiviran tastatura.
			{
				if (strukturaUlaza.Event.KeyEvent.bKeyDown)  // Provjerava da li je tastatura aktivirana jednim fizickim pritiskom, a ne drzanjem tastera ili virtuelno.
				{
					prviKarakter = strukturaUlaza.Event.KeyEvent.uChar.AsciiChar; // Upisivanje ASCII vrijednosti pritisnutog karaktera na adresu promjenjive "prviKarakter".
					return true;
				}
			}
		}
		// YieldProcessor(); // "Yield Processor();" je makro koji signalira procesoru da odobri resurse threadovima koji cekaju na izvrsavanje funkcija (Potreban multi-thread procesor).
		GetNumberOfConsoleInputEvents(pokazivacNaStandardniUlaz, &brojEventova); // Kupi broj neprocitanih ulaznih aktivnosti sa konzole i dodjeljuje ih promjenjivoj "brojEventova".
	}

	return false; // Funkcija vraca FALSE ako nista na tastaturi nije pritisnuto prije promjenjive "zavrsnoVrijeme".
}

// Funkcija azurira bodove korisnika u realnom vremenu.
void kviz(int& stanje)
{
	int bodovi = 0; // Vrijednost koju ce funkcija vracati.
	int brojTacnihOdgovora = 0; // Promjenjiva potrebna da bi se moglo dodijeliti dodatnih 50 bodova ako su svih 5 pitanja tacna.
	int redniBrojPitanja[5] = { 0 }; // Definicija i inicijalizacija na 0 niza od 5 random odabranih brojeva.
	PITANJA listaPitanja[5] = { 0 }; // Definicija i inicijalizacija na 0 niza od 5 pitanja koja ce biti prikazana.

	// Kod za dodjeljivanje 5 random rednih brojeva izmedju 1 i 15 jer imamo 15 pitanja i sortiranje u rastucem redoslijedu.
	{
		srand(time(NULL)); // Promjena inicijalizacije pseudo random generatora sa 1 na vrijednost trenutnog vremena.
		for (int i = 0; i < 5; i++)
		{
			int control = 1;
			int tempRedniBrojPitanja = rand() % 30 + 1; // Generisanje random broja izmedju 0 i 15.

			// Provjera da li je novi redni broj pitanja ranije generisan.
			for (int j = 0; j <= i; j++)
				if (redniBrojPitanja[j] == tempRedniBrojPitanja)
					control = 0;

			// Ako redni broj pitanja nije ranije generisan, dodavanje rednog broja u listu.
			if (control)
				redniBrojPitanja[i] = tempRedniBrojPitanja;

			// Ako je ranije generisan, vracanje jednu iteraciju unazad kroz petlju.
			else
				i--;
		}

		sort((redniBrojPitanja), (redniBrojPitanja + 5)); // Sortiranje rednih brojeva pitanja u rastucem redoslijedu radi lakseg ispisa.
	}

	 pisanjePitanjaCSV(); // Funkcija upisuje pitanja u "pitanja.csv"

	// Kod za izbor 5 pitanja iz liste.
	{
		PITANJA tempPitanje; // Trenutno pitanje koje se cita iz datoteke jer se sva pitanja citaju redom i provjeravaju se redni brojevi.
		string tempLine; // Linija koja se trenutno cita potrebna jer su podaci formatirano upisani u datoteku.
		int control = 0; // Promjenjiva koja predstavlja redni broj pitanja koje se trenutno upisuje.

		ifstream datotekaSaPitanjima; // Input file stream.
		datotekaSaPitanjima.open("pitanja.csv");

		if (datotekaSaPitanjima.is_open()) // Prevencija greske pri otvaranju datoteke u modu za citanje.
			while (!datotekaSaPitanjima.eof()) // Citanje iz datoteke dok god ne dodjemo do EOF.
			{
				// Formatirano citanje SVIH PITANJA IZ LISTE.

				datotekaSaPitanjima >> tempPitanje.redniBrojPitanja; // Citanje prve kolone iz ulaznog fajla. [REDNI BROJ PITANJA - INTEGER]
				getline(datotekaSaPitanjima, tempLine); // Citanje druge kolone iz ulaznog fajla. [PITANJE - STRING ZAVRSEN SA \n]
				tempPitanje.pitanje = tempLine;

				// Kod za citanje 3, 4. i 5. kolone iz ulaznog fajla. [ODGOVORI - STRING ZAVRSEN SA \n]
				for (int i = 0; i < 3; i++)
				{
					getline(datotekaSaPitanjima, tempLine);
					tempPitanje.odgovori[i] = tempLine;
				}

				datotekaSaPitanjima >> tempPitanje.tacanOdgovor; // Citanje 5 kolone iz ulaznog fajla [TACAN ODGOVOR - INTEGER]

				// Poredjenje rednog broja pitanja sa unaprijed generisanim rednim brojevima.
				if (redniBrojPitanja[control] == tempPitanje.redniBrojPitanja)
				{
					listaPitanja[control] = tempPitanje;
					control++; // Mozemo uvecavati control i ici dalje kroz datoteku jer je niz generisanih rednih brojeva sortiran.
				}
			}
		else cout << "Greska: Neuspjesno otvaranje datoteke sa pitanjima.";

		datotekaSaPitanjima.close();
	}

	// Kod za ispis pitanja i unos odgovora.
	{
		cout << "PRAVILA: " << endl << endl << "**********" << endl << endl << "- Imate 15 sekundi i 3 pokusaja da ispravno odgovorite na svako pitanje.";
		cout << endl << "- Odgovarate unosenjem rednog broja odgovora (1, 2 ili 3) i potvrdjivanje tipkom ENTER";
		cout << endl << "- Svaki tacan odgovor nosi 20 bodova." << endl << "- Svaki netacan odgovor oduzima 30 bodova." << endl << "- Svako neodgovoreno pitanje, oduzima 10 bodova.";
		cout << endl << "- Tacni odgovori na svih 5 pitanja nose dodatnih 50 bodova." << endl << endl << "**********" << endl << endl;
		Sleep(3000);

		// For petlja za ispisivanje 5 unaprijed dodjeljenih struktura PITANJE.
		for (int i = 0; i < 5; i++)
		{
			pisiPitanjeIOdgovore(listaPitanja[i], i + 1);

			string odgovor; // String koji unosi korisnik radi lakse prevencije greske.

			char prviKarakter; // Promjenjiva potrebna da bi se mogao "pauzirati" tajmer i asignovati prvi karakter na njenu adresu.

			// Pomocne promjenjive "timerControl" i "brojPokusaja" su vezane uz kompletno pitanje.
			bool timerControl = true; // Kontrolna promjenjiva za pokazivanje stanja da li je vrijeme isteklo.
			int brojPokusaja = 0; // Kontrolna promjenjiva za provjeru broja pokusaja.

			// Pomocna promjenjiva "control" je vezana uz pojedinacan odgovor koji korisnik unese, ali se mora inicijalizovati van DO - WHILE petlje jer je potrebna radi prevencije greske (lijeno izracunavanje).
			bool control; // Kontrolna promjenjiva za provjeru da li su uneseni znakovi brojevi ili slova.

			// Promjenjivu "zavrsnoVrijeme" inicijalizujemo van DO - WHILE petlje jer je zavrsno vrijeme vezano uz specificno pitanje.
			DWORD zavrsnoVrijeme = GetTickCount() + 15000; // "GetTickCount();" vraca broj sekundi koje su prosle od pokretanja sistema.

			// DO - WHILE petlja za citanje i provjeru ispravnosti unesenog odgovora.
			do
			{
				control = true;
				brojPokusaja++;

				// Ako je broj pokusaja veci od 3, prekidanje i izlazak iz petlje.
				if (brojPokusaja > 3)
					break;

				cout << endl << "Molimo odgovorite na pitanje: ";

				// Provjerava da li je tastatura aktivirana unutar 15 sekundi i dodjeljuje vrijednost pritisnutog karaktera na adresu "prviKarakter".
				if (pritisakNaDugme(zavrsnoVrijeme, prviKarakter))
				{
					// Provjerava da li je prvi karakter ENTER, ESCAPE ili BACKSPACE i prekida izvrsavanje programa ako jeste.
					if (prviKarakter == 13 || prviKarakter == 27 || prviKarakter == 8)
					{
						cout << ' ';
						odgovor = " ";
						cout << endl;
					}

					// Ako prvi karakter nije ENTER, ESCAPE ili BACKSPACE, ispisuje taj karakter i skuplja ostatak stringa koji korisnik unese.
					else
					{
						cout << prviKarakter;
						getline(cin, odgovor);
						odgovor = prviKarakter + odgovor;
					}
				}

				// Ako tastatura nije aktivirana unutar 15 sekundi, postavljanje kontrolne promjenjive na false i prekidanje petlje.
				else
				{
					timerControl = false; // Potrebno je postaviti kontrolnu promjenjivu da bismo znali zasto je ulazna petlja prekinuta i da bismo mogli ispisati gresku.
					break;
				}

				// Petlja za provjeru da li se u unesenom stringu nalaze karakteri koji nisu cifre radi prevencije greske.
				for (int j = 0; j < (int)odgovor.length(); j++)
					if (!isdigit(odgovor.at(j)))
					{
						// Postavljanje kontrolne promjenjive FALSE i prekidanje DO - WHILE petlje ako postoje.
						control = false; // Promjenjiva je potrebna radi prevencije greske, lijeno izracunavanje.
						break;
					}

			} while (!timerControl || !control || stoi(odgovor) > 3 || stoi(odgovor) < 1); // Ako samo jedna od kontrolnih promjenjivih nije zadovoljena, stoi() funkcija se nece izvrsiti pa nece doci do greske.

			// Ako je petlja prekinuta zbog tajmera, ispisvanje greske i prelazak na sljedece pitanje (sljedeca iteracija FOR petlje).
			if (!timerControl)
			{
				cout << endl << endl << "   ---   ISTEKLO VAM JE VRIJEME !" << endl;
				bodovi -= 10;
				stanje -= 10;
				cout << endl << "   ---   Trenutni broj bodova: " << bodovi << endl << endl;
				Sleep(2000); // Windows Sleep da bi korisnik imao 2s da pogleda svoj rezultat.
				continue;
			}

			// Ako je petlja prekinuta zbog tri neispravno unesena odgovora, ispisivanje greske i prelazak na sljedece pitanje.
			else if (brojPokusaja > 3)
			{
				cout << endl << "   ---   TRI PUTA STE NEPRAVILNO UNIJELI ODGOVOR !" << endl;
				bodovi -= 10;
				stanje -= 10;
				cout << endl << "   ---   Trenutni broj bodova: " << bodovi << endl << endl;
				Sleep(2000); // Windows Sleep da bi korisnik imao 2s da pogleda svoj rezultat.
				continue;
			}

			// Ako petlja nije prekinuta, uneseni string uspjesno konvertovan u integer i odgovor netacan - ispisivanje poruke i CONTINUE na FOR petlju.
			else if (stoi(odgovor) != listaPitanja[i].tacanOdgovor)
			{
				cout << endl << "   ---   NETACNO !" << endl;;
				bodovi -= 30;
				stanje -= 30;
				cout << endl << "   ---   Trenutni broj bodova: " << bodovi << endl << endl;
				Sleep(2000); // Windows Sleep da bi korisnik imao 2s da pogleda svoj rezultat.
				continue;
			}

			// Ako petlja nije prekinuta, uneseni string uspjesno konvertovan u integer i odgovor tacan - ispisivanje poruke i prelazak na sljedece pitanje.
			else
			{
				cout << endl << "   ---   TACNO !" << endl;
				bodovi +=20;
				stanje += 20;
				cout << endl << "   ---   Trenutni broj bodova: " << bodovi << endl << endl;
				brojTacnihOdgovora++;
				Sleep(2000); // Windows Sleep da bi korisnik imao 2s da pogleda svoj rezultat.
				continue;
			}

		}

		if (brojTacnihOdgovora == 5)
        {
            bodovi += 50;
			stanje += 50;
        }
	}

	cout << endl << "Ukupan broj bodova na kraju igre: " << bodovi << endl;
	cout << endl << "Ukupan broj bodova na vasem nalogu: " << stanje << endl << endl;

	system("PAUSE");

	return;
}
