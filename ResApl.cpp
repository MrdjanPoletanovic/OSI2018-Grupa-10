#include "ResApl.h"






void RestartujApl()
{
    int MasterPasvord;
    srand (time(0));
     int a=rand()%10000+1000;

     std::cout<<"Master Password je "<<a<<std::endl;
    do
    {
    std::cout<<"Unesite MasterPassword: ";
    std::cin>>MasterPasvord;
    if(MasterPasvord==a)
    {
        std::ofstream ofs;
        ofs.open("nalozi.csv", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
    else
    {
        std::cout<<"Pogresan MasterPassword pokusajte ponovo"<<std::endl;
    }
    }
    while(MasterPasvord!=a);

}
