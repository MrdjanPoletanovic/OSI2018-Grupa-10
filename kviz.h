#include <Windows.h>

// Definicija strukture i tipa za jedno pitanje.
typedef struct pitanja_odgovori
{
	int redniBrojPitanja;
	std::string pitanje;
	std::string odgovori[3];
	int tacanOdgovor;
} PITANJA;

void pisanjePitanjaCSV();
int stoi (std::string);
void pisiPitanjeIOdgovore(PITANJA, int);
bool pritisakNaDugme (DWORD, char);
int kviz();

