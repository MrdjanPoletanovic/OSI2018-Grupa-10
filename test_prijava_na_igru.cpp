
#include "pch.h"

#include <iostream>
#include "Generate.h"
#include "Prijava_na_igru.h"

int main()
{
	std::string str_gener1,str_gener2,str_gener3, str_gener4;
	int temp[4] = { 0 };
	
	if (prijava(1, temp[0],str_gener1))
		std::cout << "USPJESNO!\n";
	else
		std::cout << "NEUSPJENSO!\n";
	if (prijava(2, temp[1], str_gener2))
		std::cout << "USPJESNO!\n";
	else
		std::cout << "NEUSPJENSO!\n";
	if (prijava(3, temp[2], str_gener3))
		std::cout << "USPJESNO!\n";
	else
		std::cout << "NEUSPJENSO!\n";
	if (prijava(4, temp[3],str_gener4))
		std::cout << "USPJESNO!\n";
	else
		std::cout << "NEUSPJENSO!\n";
	std::cout << "\nNiz temp sa podacima o aktiviranju igre!\n";
	for (int i : temp)
		std::cout << i;
	std::cout << std::endl;
	std::cout << str_gener1 << std::endl;
	std::cout << str_gener2 << std::endl;
	std::cout << str_gener3 << std::endl;
	std::cout << str_gener4 << std::endl;
}