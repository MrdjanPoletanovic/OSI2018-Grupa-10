#pragma once


#include "baza.h"
#include "NamjestanjePoker.h"


struct karta
{
       int broj;
       int znak;
};


void poker(int& pare,int& gubitak,int& dobitci);
void dobijanjeKarata(karta a[10]);
void ispisKarata(karta a[10],int pd);
void mjenjanjeKarata(karta a[10],std::string odluke[5]);
void sortiranjeKarata(karta a[10]);
int dobitak(karta a[10]);
void ispisDobitka(int dobit);
bool nastavitiIgru();
