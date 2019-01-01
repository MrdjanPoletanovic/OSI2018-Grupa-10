#include "poker.h"
#include "baza.h"
#include <iostream>


int poker(int& stanje,int& gubitak,int &dobici)
{
        struct karta a[10];
        struct karta ispis[5];
        std::string smece;
        bool stela=false;
        std::string odluke[5];
        std::string filter;

        int  dobit,j;
        srand(time(NULL));
        do
        {
        stela=(rand()%3)==0;///
        clear_screen();

        stanje=stanje-5;
        gubitak+=5;
        //std::cout<<"Dobitak:"<<dobici<<" Gubitak:"<<gubitak<<std::endl;
        std::cout<<"Trenutno stanje na racunu je "<<stanje<<" bodova"<<std::endl;

        j=0;
        do
        {
            j++;
        dobijanjeKarata(a);
        for(int i=0;i<5;i++)
            ispis[i]=a[i];
        sortiranjeKarata(a-5);
        if(dobitak(a-5)==0)
            break;
        }while(NamjestanjePoker(stela,dobici+dobitak(a-5),gubitak) && j<30);
        ispisKarata(ispis,0);
        for(int i=0;i<5;i++)
            a[i]=ispis[i];

        std::cout<<"Unesite kombinaciju  //Primjer:(da ne da ne ne)"<<std::endl;
        std::getline(std::cin,filter);

        while(!( ((filter[0]=='d' && filter[1]=='a') || (filter[0]=='n' && filter[1]=='e'))
               && filter[2]==' '
               && ((filter[3]=='d' && filter[4]=='a') || (filter[3]=='n' && filter[4]=='e'))
               && filter[5]==' '
               && ((filter[6]=='d' && filter[7]=='a') || (filter[6]=='n' && filter[7]=='e'))
                   && filter[8]==' '
                   && ((filter[9]=='d' && filter[10]=='a') || (filter[9]=='n' && filter[10]=='e'))
                   && filter[11]==' '
                   && ((filter[12]=='d' && filter[13]=='a') || (filter[12]=='n' && filter[13]=='e'))
                   && filter[14]==0))
                   {
                      std::cout<<"Neispravan unos, unesite ponovo //Primjer:(da ne da ne ne)"<<std::endl;
                        std::getline(std::cin,filter);
                   }
        for(int i=0;i<5;i++)
        {

        if(filter[i*3]=='d')
        odluke[i]="da";
        else
        odluke[i]="ne";
        }
        j=0;
        std::cout<<std::endl;
        do
        {
        j++;
        mjenjanjeKarata(a,odluke);

        for(int i =0;i<5;i++)
            ispis[i]=a[i+5];
        sortiranjeKarata(a);
        if(dobitak(a)==0)
            break;
        }while(NamjestanjePoker(stela,dobici+dobitak(a),gubitak) && j<30);

        ispisKarata(ispis,0);
        sortiranjeKarata(a);
        dobit=dobitak(a);
        stanje=stanje+dobit;
        dobici=dobici+dobit;
        ispisDobitka(dobit);
        std::cout<<std::endl<<"Trenutno stanje na racunu je "<<stanje<<" bodova"<<std::endl;
        } while(igraj_ponovo());
}

void dobijanjeKarata(karta a[10])
{
    int i,j;
    for(i=0;i<5;i++)
    {
	    a[i].broj=rand()%13+1;
	    a[i].znak=rand()%4+1;
	    for(j=0;j<i;j++)
		    if(a[i].broj==a[j].broj && a[i].znak==a[j].znak)
		    {
			    i=i-1;
			    break;
		    }
    }
}

void ispisKarata(karta a[10],int pd)
{
    int i;
    for(i=0+pd;i<5+pd;i++)
      {
      if(a[i].broj==1)
      std::cout<<"A";
      else
      if(a[i].broj==11)
      std::cout<<"J";
      else
      if(a[i].broj==12)
      std::cout<<"Q";
      else
      if(a[i].broj==13)
      std::cout<<"K";
      else
      std::cout<<a[i].broj;
      if(a[i].znak==1)
      std::cout<<char(3);
      if(a[i].znak==2)
      std::cout<<char(4);
      if(a[i].znak==3)
      std::cout<<char(5);
      if(a[i].znak==4)
      std::cout<<char(6);
      std::cout<<" ";
      }
      std::cout<<std::endl;
}

void mjenjanjeKarata(karta a[10],std::string odluke[5])
{
    int i,j,u;
    std::string l;

    for(i=0;i<5;i++)
      {

      l=odluke[i];

      if(l=="ne")
      {
      u=2;
      while(u>=2)
      {
      u=0;
      a[i+5].broj=rand()%13+1;
      a[i+5].znak=rand()%4+1;
      for(j=0;j<=5+i;j++)
      if(a[i+5].broj==a[j].broj && a[i+5].znak==a[j].znak)
      u++;
      }
      }
      if(l=="da")
      a[i+5]=a[i];
      }
    //  std::cout<<std::endl;
}

void sortiranjeKarata(karta a[10])
{
    int i,j;
    for(i=5;i<9;i++)
      for(j=i+1;j<10;j++)
      if(a[i].broj>a[j].broj)
      std::swap(a[i],a[j]);
}

int dobitak(karta a[10])
{
    if((a[5].broj==1 && a[6].broj==10 && a[7].broj==11 && a[8].broj==12 && a[9].broj==13)
             && (a[5].znak==a[6].znak && a[5].znak==a[7].znak && a[5].znak==a[8].znak &&
             a[5].znak==a[9].znak))
             return 4000;

             else
             if((a[5].broj==a[6].broj-1 && a[5].broj==a[7].broj-2 && a[5].broj==a[8].broj-3 &&
             a[5].broj==a[9].broj-4) && (a[5].znak==a[6].znak && a[5].znak==a[7].znak && a[5].znak==a[8].znak &&
             a[5].znak==a[9].znak))
             return 250;

             else
             if((a[5].broj==a[6].broj && a[5].broj==a[7].broj && a[5].broj==a[8].broj) ||
             (a[6].broj==a[7].broj && a[6].broj==a[8].broj && a[6].broj==a[9].broj))
             return 125;
             else
             if( ((a[5].broj==a[6].broj && a[5].broj==a[7].broj) &&  a[8].broj==a[9].broj) ||
             (a[5].broj==a[6].broj && (a[7].broj==a[8].broj && a[7].broj==a[9].broj)) )
             return 45;

             else
             if(a[5].znak==a[6].znak && a[5].znak==a[7].znak && a[5].znak==a[8].znak &&
             a[5].znak==a[9].znak)
             return 30;

             else
             if((a[5].broj==a[6].broj-1 && a[5].broj==a[7].broj-2 && a[5].broj==a[8].broj-3 &&
             a[5].broj==a[9].broj-4) || (a[5].broj==1 && a[6].broj==10 && a[7].broj==11 &&
             a[8].broj==12 && a[9].broj==13))
             return 20;

             else
             if((a[5].broj==a[6].broj && a[5].broj==a[7].broj) ||
             (a[6].broj==a[7].broj && a[6].broj==a[8].broj) ||
             (a[7].broj==a[8].broj && a[7].broj==a[9].broj))
             return 15;

             else
             if((a[5].broj==a[6].broj && a[7].broj==a[8].broj) ||
             (a[5].broj==a[6].broj && a[8].broj==a[9].broj) ||
             (a[6].broj==a[7].broj && a[8].broj==a[9].broj))
             return 10;

             else
             if((a[5].broj==a[6].broj && (a[5].broj==11 || a[5].broj==12 || a[5].broj==13 ||
             a[5].broj==1)) || (a[6].broj==a[7].broj && (a[6].broj==11 || a[6].broj==12 || a[6].broj==13 ||
             a[6].broj==1)) ||
             (a[7].broj==a[8].broj && (a[7].broj==11 || a[7].broj==12 || a[7].broj==13 ||
             a[7].broj==1)) ||
             (a[8].broj==a[9].broj && (a[8].broj==11 || a[8].broj==12 || a[8].broj==13 ||
             a[8].broj==1)))
             return 5;

             else
             return 0;

}
void ispisDobitka(int dobit)
{
    switch(dobit)
    {
        case 4000 : std::cout<<std::endl<<"Dobili ste Royal Flush"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 250  : std::cout<<std::endl<<"Dobili ste Straight Flush"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 125  : std::cout<<std::endl<<"Dobili ste Poker"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 45   : std::cout<<std::endl<<"Dobili ste Full House"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 30   : std::cout<<std::endl<<"Dobili ste Flush"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 20   : std::cout<<std::endl<<"Dobili ste Straight"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 15   : std::cout<<std::endl<<"Dobili ste Three of a Kind"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 10   : std::cout<<std::endl<<"Dobili ste Two Pairs"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 5    : std::cout<<std::endl<<"Dobili ste Jack's of Better"<<" osvojili ste "<<dobit<<" bodova"<<std::endl;break;
        case 0    : std::cout<<std::endl<<"Dobili ste "<<dobit<<" bodova"<<std::endl;break;
    }
}


bool NamjestanjePoker(bool stela,int ukupna_dobit,int gubitak)
{
    return (stela && ((14*ukupna_dobit)>(10*gubitak)));
}
