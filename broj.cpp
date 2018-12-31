#include "broj.h"


int unos(int i)
{
	int j;
	std::string unos;
	bool dobar;
	int broj;
	do
	{
		cout << i << ". pokusaj: ";
		std::getline(cin, unos);
		for(j = 0; unos[j] == ' '; j++);
		for(broj=0, dobar=true; unos[j]!='\0' && unos[j]!=' '; j++)
		{
			if (unos[j] >= '0' && unos[j] <= '9')
			{
				if (broj > 0)
					broj *= 10;
				broj += unos[j] - 0x30;
				if (broj > 100)
				{
					dobar = false;
					break;
				}
			}
			else
			{
				dobar = false;
				break;
			}
		}
		if (dobar)
			return broj;
		else
			cout << "Neispravan unos! Unesite broj izmedju 1 i 100." << endl;
	}
	while(true);
}



void broj(int& stanje, int& dobitak, int& pokusaj)
{
	do
	{
		clear_screen();
		srand (time(0));
		int zadaniBroj=rand()%100+1;
		int s=rand()%5+1; //s je slucajan broj od 1 do 5 koji odlucuje u kojem pokusaju ce igra omoguciti pogodak (za prva 3 igranja)
		int uneseniBroj,min=0,max=100; //granice opsega koje se odredjuju tokom igranja
		bool pogodio=false;
		for(int i=1;i<=5;i++)
		{
			uneseniBroj = unos(i);
			if(pokusaj<3 && s==i && s<5 && (uneseniBroj<min || uneseniBroj> max)) s++;
			if (uneseniBroj==zadaniBroj || (pokusaj<=3 && s==i && uneseniBroj>min && uneseniBroj<max))
			{
				cout<<"Pogodak!! Osvojili ste "<<100/i<<" bodova!!"<<endl;
				stanje+=100/i;
				dobitak += 100/i;
				pogodio=true;
				pokusaj++;
				break;
			}
			else if(uneseniBroj>zadaniBroj)
			{
				if(i<5)
					cout<<"Trazeni broj je MANJI od unesenog"<<endl;
				if(uneseniBroj<max) max=uneseniBroj;
			}
			else if (uneseniBroj<zadaniBroj)
			{
				if(i<5)
					cout<<"Trazeni broj je VECI od unesenog"<<endl;
				if(uneseniBroj>min) min=uneseniBroj;
			}
		}
		if(pogodio==false)
			cout<<"Trazeni broj je "<< zadaniBroj << endl;
	}
	while(igraj_ponovo());
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
