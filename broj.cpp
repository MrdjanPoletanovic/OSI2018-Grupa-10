#include "broj.h"
#include<string>

void pogodiBroj()
{
    FILE *f;

    f=fopen("bodovi.txt","r");
        int bodovi; fscanf(f, "%d", &bodovi);
        fclose(f);
   std::string pitanje="da";
   while(pitanje=="da" || pitanje=="DA" || pitanje=="Da")
   {
       srand (time(NULL));
    int zadaniBroj=rand()%100+1;
    int uneseniBroj,min=0,max=100;
       bool pogodio=false;
    for(int i=1;i<=5;i++)
    {
        cout<<i<<". pokusaj "; cin>>uneseniBroj;

        if (uneseniBroj==zadaniBroj)
            {
                cout<<"Pogodak!! Osvojili ste "<<100/i<<" bodova!!"<<endl;
                bodovi+=100/i;
                pogodio=true;
                break;
            }
            if(uneseniBroj>zadaniBroj)
        {
           if(i<5)
                cout<<"Trazeni broj je MANJI od unesenog"<<endl;
            if(uneseniBroj<max) max=uneseniBroj;
        }
        if (uneseniBroj<zadaniBroj)
           {
           if(i<5)
           cout<<"Trazeni broj je VECI od unesenog"<<endl;
            if(uneseniBroj>min) min=uneseniBroj;
    }
    }

    if(pogodio==false)
        cout<<"Trazeni broj je "<<zadaniBroj<<endl;
    cout<<"Ukupno bodova: "<<bodovi<<endl;
    cout<<"Da li zelite da nastavite? (da/ne): ";
    cin>>pitanje;
    while(pitanje != "da" && pitanje!="DA" && pitanje!="Da" && pitanje!="ne" && pitanje!="NE" && pitanje!="Ne")
    {
        cout<<"Pogresan unos! Unesite da ili ne. "<<endl;
        cin>>pitanje;
    }
    system("CLS");
   }

    f=fopen("bodovi.txt", "w");
        fprintf(f,"%d",bodovi);
        fclose(f);
}
