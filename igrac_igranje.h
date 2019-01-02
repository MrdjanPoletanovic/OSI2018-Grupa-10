#pragma once
#include <string>
#include "statistika.h"


class Igrac
{
	std::string korisnicko_ime;
	std::string sifra;
	int dobitak, gubitak, stanje;
	int pokusajBroj, pokusajLoto;
	KruzniBafer nizovi[4];
public:
	Igrac(const std::string&, const std::string&);
	Igrac(FILE*);
	inline int getDobitak() const {return dobitak;}
	inline int getGubitak() const{return gubitak;}
	inline int getStanje() const {return stanje;}
	inline int getPL() const {return pokusajLoto;}
	inline int getPB() const {return pokusajBroj;}
	void igraj_loto();
	void igraj_poker();
	void igraj_broj();
	void igraj_kviz();
};


void clear_screen();
bool igraj_ponovo();
