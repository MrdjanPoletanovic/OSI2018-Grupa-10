#include "prijava.h"
#include <iostream>
#include <string>
#include <conio.h>

void prijava()
{
    std::cout<<"User name: ";
    std::string name;
    getline(std::cin, name);
    std::cout<<"Password: ";
    std::string password="";
    char x;
    do
    {
        x=getch();
        if(x=='\r') break;
        if(x=='\b')
        {
           password=password.substr(0,password.length()-1);
           std::cout<<"\b"<<" \b";
        }
        else
        {
            std::cout<<"*";
            password+=x;
        }
    }while(x!='\r');
}
