#pragma once
#include <string>


//funckija koja omogucava korisniku da izabere 7 brojeva
void izaberi(int izabrani[], int niz[]);

// funkcija zaduzena za nasumicno izvlacenje brojeva iz niza "niz" u niz izvuceni koji je duzine n
void izvuci(int izvuceni[], int niz[], int n);

// funkcija koja prikazuje izvlacenje na standardni izlaz
// duzina niza je fiksna i jednaka je broju karata koje program izvlaci (20)
void prikazi_izvlacenje(int izvuceni[]);

// provjerava koliko je bodova korisnik osvojio na osnovu nizova izabranih i izvucenih brojeva
// parametar is_namjestanje kontrolise ispis odredjenih informacija na standarni izlaz koji
// treba izbjeci u slucaju namjestanja rezultata
int provjera(int izvuceni[], int izabrani[], bool is_namjestanje=false);

// glavna funkcija koja je zaduzena za izvrsavanje cijele igre
int loto(int stanje, int dobitak, int gubitak, int igranje);

// funkcija koja provjerava da li je broj u dozvoljenom opsegu
// koristi se kao pomocna funkcija u provjeri korisnickog unosa
bool provjeri_broj(int izabrani[], int i);

// provjerava da li je korisnik unio validne podatke preko standardnog ulaza
bool check_input(std::string&, int izabrani[], int niz[]);

// funkcija koja provjerava da li je potrebno namjestanje
bool check_namjestanje(int dobitak, int gubitak, int igranje);

// u slucaju da je namjestanje potrebno funkcija vraca koliki je optimalan
// broj bodova koje korisnik treba da osvoji kako bi se zadovoljio uslov zadatka
int get_optimalno(int dobitak, int gubitak);

// funkcija koja namjesta izvucene brojeve u skladu sa parametrom optimalno
// koji dobija na osnovu prethodne funkcije
void namjesti(int izabrani[], int izvuceni[], int niz[], int optimalno);

//funkcija za ispis pravila na ekran
void printPravilaLoto();
