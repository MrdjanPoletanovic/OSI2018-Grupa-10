#include "igranje.h"
#include <iostream>


int main()
{
	Igrac i("ime", "password");
	KruzniBafer k[2];
	igraj_broj(k[0], i);
	igraj_loto(k[1], i);
	k[0].print();
	k[1].print();
	std::cout << "Dobitak: " << i.getDobitak() << std::endl;
	std::cout << "Gubitak: " << i.getGubitak() << std::endl;
	std::cout << "Stanje: " << i.getStanje() << std::endl;
	return 0;
}
