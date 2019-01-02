#include "igrac_igranje.h"
#include <iostream>


int main()
{
	Igrac i("ime", "password");
	i.igraj_broj();
	i.igraj_loto();
	i.igraj_poker();
	i.printStatBroj();
	i.printStatLoto();
	i.printStatPoker();
	std::cout << "Dobitak: " << i.getDobitak() << std::endl;
	std::cout << "Gubitak: " << i.getGubitak() << std::endl;
	std::cout << "Stanje: " << i.getStanje() << std::endl;
	return 0;
}
