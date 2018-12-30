#include "pch.h"
#include "Provjera_trajanja_kljuca.h"

bool provjera_kljuca(int redni_broj, time_t begin, time_t end, double& trenutno_vrijeme)
{
	double vrijeme = 0;
	if (redni_broj == 1)
	{
		vrijeme = 86'400;
		trenutno_vrijeme += difftime(end, begin);
		if (trenutno_vrijeme >= vrijeme)
			return false;
		else
			return true;
	}
	else if (redni_broj == 2)
	{
		vrijeme = 3'600;
		trenutno_vrijeme += difftime(end, begin);
		if (trenutno_vrijeme >= vrijeme)
			return false;
		else
			return true;
	}
	else if (redni_broj == 3)
	{
		vrijeme = 604'800;
		trenutno_vrijeme += difftime(end, begin);
		if (trenutno_vrijeme >= vrijeme)
			return false;
		else
			return true;
	}
	else if (redni_broj == 4)
	{
		
		return true;
	}
	else
		return false;
}