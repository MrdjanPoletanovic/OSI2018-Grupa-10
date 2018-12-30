#include "NamjestanjeBroj.h"


bool namjestanje (int pokusaj, int s, int i, int uneseniBroj, int min, int max)
{
     if(pokusaj<3 && s==i && s<5 && (uneseniBroj<min || uneseniBroj> max)) s++;
     if(pokusaj<=3 && s==i && uneseniBroj>min && uneseniBroj<max) return true;
     return false;
}
