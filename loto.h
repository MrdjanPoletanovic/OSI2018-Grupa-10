#pragma once
#include <string>


void izaberi(int izabrani[], int niz[]);
void izvuci(int izvuceni[], int niz[], int n);
void prikazi_izvlacenje(int izvuceni[]);
int provjera(int izvuceni[], int izabrani[], bool is_namjestanje=false);
void loto(int& stanje, int& dobitak, int& gubitak, int& igranje);
bool provjeri_broj(int izabrani[], int i);
bool check_input(std::string&, int izabrani[], int niz[]);
void loto(int& stanje, int& dobitak, int& gubitak, int& igranje);
bool check_namjestanje(int dobitak, int gubitak, int& igranje, int& redni);
int get_optimalno(int dobitak, int gubitak);
void namjesti(int izabrani[], int izvuceni[], int niz[], int optimalno);
