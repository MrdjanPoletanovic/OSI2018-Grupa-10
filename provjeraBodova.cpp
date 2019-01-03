#include "provjeraBodova.h"
#include <iostream>

bool provjeraBodova(const std::string &igra, const int &bodovi)
{
    if(igra.compare("broj")==0 ) 
        return true;
    else if (igra.compare("kviz")==0 && bodovi>=50)
    	return true;
    else if(igra.compare("loto")==0 && bodovi>=100)
        return true;
    else if(igra.compare("poker")==0 && bodovi>=5)
        return true;
    else return false;
}
