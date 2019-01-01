#pragma once
#include <string>


class Igrac
{
	std::string korisnicko_ime;
	std::string sifra;
	int dobitak, gubitak, stanje;
	int pokusajLoto, pokusajBroj;
public:
	Igrac(const std::string&, const std::string&);
	inline int& getDobitak() {return dobitak;}
	inline int& getGubitak() {return gubitak;}
	inline int& getStanje() {return stanje;}
	inline int& getPL() {return pokusajLoto;}
	inline int& getPB() {return pokusajBroj;}
};
