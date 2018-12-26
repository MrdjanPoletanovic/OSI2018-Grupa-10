#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <Windows.h>
#include <cmath>
#include "baza.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::sort;

// Definicija strukture i tipa za jedno pitanje.
typedef struct pitanja_odgovori
{
	int redniBrojPitanja;
	string pitanje;
	string odgovori[3];
	int tacanOdgovor;
} PITANJA;

void pisanjePitanjaCSV();
int stoi (string);
void pisiPitanjeIOdgovore(PITANJA, int);
bool pritisakNaDugme (DWORD, char);
int kviz();

