#include "provjeraPrijave.h"
#include <iostream>
#include <fstream>
#include <string>

bool provjera(std::string &userName, std::string &password)
{
    std::ifstream dataBase;
    dataBase.open("nalozi.csv");          //otvaranje csv fajla pod imenom "nalozi"; promijeniti naziv fajla
    while(dataBase.good())
    {
        std::string _name, _password, ignore;
        getline(dataBase, _name, ',');
        getline(dataBase, _password, '\n');     // pretpostavka da u tabeli postoje samo 2 kolone: username i password
        if(userName.compare(_name)==0 && password.compare(_password)==0)
            return true;
    }
    return false;
}

