#include "poker.h"


void poker(int& stanje,int& gubitak,int &dobici)
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
        //cout<<"Dobitak:"<<dobici<<" Gubitak:"<<gubitak<<endl;
        cout<<"Trenutno stanje na racunu je "<<stanje<<" bodova"<<endl;

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

        cout<<"Unesite kombinaciju  //Primjer:(da ne da ne ne)"<<endl;
        std::getline(cin,filter);

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
                      cout<<"Neispravan unos, unesite ponovo //Primjer:(da ne da ne ne)"<<endl;
                        std::getline(cin,filter);
                   }
        for(int i=0;i<5;i++)
        {

        if(filter[i*3]=='d')
        odluke[i]="da";
        else
        odluke[i]="ne";
        }
        j=0;
        cout<<endl;
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
        cout<<endl<<"Trenutno stanje na racunu je "<<stanje<<" bodova"<<endl;
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
      cout<<"A";
      else
      if(a[i].broj==11)
      cout<<"J";
      else
      if(a[i].broj==12)
      cout<<"Q";
      else
      if(a[i].broj==13)
      cout<<"K";
      else
      cout<<a[i].broj;
      if(a[i].znak==1)
      cout<<char(3);
      if(a[i].znak==2)
      cout<<char(4);
      if(a[i].znak==3)
      cout<<char(5);
      if(a[i].znak==4)
      cout<<char(6);
      cout<<" ";
      }
      cout<<endl;
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
    //  cout<<endl;
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
        case 4000 : cout<<endl<<"Dobili ste Royal Flush"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 250  : cout<<endl<<"Dobili ste Straight Flush"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 125  : cout<<endl<<"Dobili ste Poker"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 45   : cout<<endl<<"Dobili ste Full House"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 30   : cout<<endl<<"Dobili ste Flush"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 20   : cout<<endl<<"Dobili ste Straight"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 15   : cout<<endl<<"Dobili ste Three of a Kind"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 10   : cout<<endl<<"Dobili ste Two Pairs"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 5    : cout<<endl<<"Dobili ste Jack's of Better"<<" osvojili ste "<<dobit<<" bodova"<<endl;break;
        case 0    : cout<<endl<<"Dobili ste "<<dobit<<" bodova"<<endl;break;
    }
}
