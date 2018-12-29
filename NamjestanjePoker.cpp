#include "NamjestanjePoker.h"
bool NamjestanjePoker(bool stela,int ukupna_dobit,int gubitak)
{
    return (stela && ((14*ukupna_dobit)>(10*gubitak)));
}
