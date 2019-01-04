#pragma once
#include <Windows.h>
#include <string>

// Definicija strukture i tipa za jedno pitanje.
typedef struct pitanja_odgovori
{
	int redniBrojPitanja;
	std::string pitanje;
	std::string odgovori[3];
	int tacanOdgovor;
} PITANJA;

void pisanjePitanjaCSV();
void pisiPitanjeIOdgovore(PITANJA, int);
bool pritisakNaDugme (DWORD, char&);
int kviz(int&, int&, int&, int&);
