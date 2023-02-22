#include<fstream>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include"aspecte.h"
using namespace std;

class carte
{
public:
    aspecte book[100];

    int nrcopie;///numarul de elemente al vectorului de mai sus
    int nrb;///numarul maxim de carti de tip beletristica
    int nrm;
    int nrf;
    int nrr;
    int nri;
    int nrc;

public:
    void creere();///se creaza o baza de date noua
    void afisare();
    void initializare();
    void stocare();
    void adaugare();
    void rememorare();
    void sterge();

};


/**se poate dori ca o carte sa fie stersa din baza de date...
se alege domeniul in care se afla cartea ce se doreste a fi stearsa  apoi se scrie in fisierul
"sterge" acele elemente din book[i].<domeniu> care nu reprezinta elementul ce se doreste a fi sters
urmand ca din fisier sa se faca o noua citire, evident rezultatul va fi fara cartea ce s-a dorit stearsa
(ea ne mai fiind in fisier)*/
void carte::sterge()
{
    fstream f;
char domeniu[100],carte[100];


while(0==0)
{
system("cls");



cout<<"Domenii posibile:beletristica\nmatematica\nfizica\nromana\ninformatica\nchimie";
    cout<<"\nDin ce domeniu doriti sa stergeti cartea sau iesiti?\n\n";
        cin.getline(domeniu,100);///domeniul in care se afla cartea pe care doresc sa o sterg


if(stricmp(domeniu,"iesire")!=0)
{
    cout<<"\n\nCe carte doriti sa stergeti?\n";
        cin.getline(carte,100);///titlul cartii pe care doresc sa o sterg
}



    if(stricmp(domeniu,"iesire")==0)
    {
        break;
    }
    else
    if(stricmp(domeniu,"chimie")==0)
    {
        f.open("sterge",ios::out);
        for(int i=1;i<=nrc;i++)
        {
            if(stricmp(book[i].chimie,carte)!=0)
                f<<book[i].chimie<<'\n';
        }
        f.close();

        f.open("sterge",ios::in);

       nrc--;

        for(int i=1;i<=nrc;i++)
        {
            f.getline(book[i].chimie,100);

        }

        f.close();

    }
    else
    if(stricmp(domeniu,"fizica")==0)
    {

    f.open("sterge",ios::out);
        for(int i=1;i<=nrf;i++)
        {
            if(stricmp(book[i].fizica,carte)!=0)
                f<<book[i].fizica<<'\n';
        }
        f.close();

        f.open("sterge",ios::in);

       nrf--;

        for(int i=1;i<=nrf;i++)
        {
            f.getline(book[i].fizica,100);

        }

        f.close();
    }
    else
    if(stricmp(domeniu,"informatica")==0)
    {
        f.open("sterge",ios::out);
        for(int i=1;i<=nri;i++)
        {
            if(stricmp(book[i].informatica,carte)!=0)
                f<<book[i].informatica<<'\n';
        }
        f.close();

        f.open("sterge",ios::in);

       nri--;

        for(int i=1;i<=nri;i++)
        {
            f.getline(book[i].informatica,100);

        }

        f.close();

    }
    else
    if(stricmp(domeniu,"matematica")==0)
    {
        f.open("sterge",ios::out);
        for(int i=1;i<=nrm;i++)
        {
            if(stricmp(book[i].matematica,carte)!=0)
                f<<book[i].matematica<<'\n';
        }
        f.close();

        f.open("sterge",ios::in);

       nrm--;

        for(int i=1;i<=nrm;i++)
        {
            f.getline(book[i].matematica,100);

        }

        f.close();

    }
    else
    if(stricmp(domeniu,"romana")==0)
    {
f.open("sterge",ios::out);
        for(int i=1;i<=nrr;i++)
        {
            if(stricmp(book[i].romana,carte)!=0)
                f<<book[i].romana<<'\n';
        }
        f.close();

        f.open("sterge",ios::in);

       nrr--;

        for(int i=1;i<=nrr;i++)
        {
            f.getline(book[i].romana,100);

        }

        f.close();

    }
    else
    if(stricmp(domeniu,"beletristica")==0)
    {
        f.open("sterge",ios::out);
        for(int i=1;i<=nrb;i++)
        {
            if(stricmp(book[i].beletristica,carte)!=0)
                f<<book[i].beletristica<<'\n';
        }
        f.close();

        f.open("sterge",ios::in);

       nrb--;

        for(int i=1;i<=nrb;i++)
        {
            f.getline(book[i].beletristica,100);

        }

        f.close();
    }
    else
    {
        cout<<"Cartea nu se afla in baza de date!Asigurati-va ca ati intordus corect datele de cautare!";
    }


}

}


///datele sunt in fisiere! nu mai trebuie creata o baza de date noua, trebuie doar sa o aducem pe
///cea veche inapoi in memoria RAM prin variabile!
void carte::rememorare()
{
    fstream f;

    f.open("beletristica",ios::in);
    f>>nrb;



    if(nrb!=0)
    {
        f.get();
        for(int i=1;i<=nrb;i++)
        {
            f.getline(book[i].beletristica,100);

        }
    }
    f.close();

    f.open("chimie",ios::in);
    f>>nrc;
    if(nrc!=0)
    {
        f.get();
        for(int i=1;i<=nrc;i++)
        {
            f.getline(book[i].chimie,100);
        }
    }
    f.close();

    f.open("fizica",ios::in);
    f>>nrf;
    if(nrf!=0)
    {
        f.get();
        for(int i=1;i<=nrf;i++)
        {
            f.getline(book[i].fizica,100);
        }
    }

    f.close();

    f.open("informatica",ios::in);
    f>>nri;

    if(nri!=0)
    {
        f.get();
        for(int i=1;i<=nri;i++)
        {
            f.getline(book[i].informatica,100);
        }
    }

    f.close();

    f.open("matematica",ios::in);
    f>>nrm;

    if(nrm!=0)
    {
        f.get();
        for(int i=1;i<=nrm;i++)
        {
            f.getline(book[i].matematica,100);
        }
    }
    f.close();

    f.open("romana",ios::in);
    f>>nrr;

    if(nrr!=0)
    {
        f.get();
        for(int i=1;i<=nrr;i++)
        {
            f.getline(book[i].romana,100);
        }
    }

    f.close();
}




///se adauga o noua carte sau mai multe
void carte::adaugare()
{
    char alege[100];
    int numar;


while(0==0)
{

system("cls");


cout<<"Domenii posibile:beletristica\nmatematica\nfizica\nromana\ninformatica\nchimie";
    cout<<"\n\nIn ce domeniu adaugati cartea sau iesiti?\n";
    cin>>alege;


    if(stricmp(alege,"iesire")!=0)
    {cout<<"\nCate carti adaugati?\n";
    cin>>numar;

    cout<<"Introduceti cartea:";
    }


    cin.get();
    if(stricmp(alege,"beletristica")==0)
    {

        for(int i=1;i<=numar;i++)
        {
            nrb++;
            cin.getline(book[nrb].beletristica,100);
        }
    }
    else
    if(stricmp(alege,"matematica")==0)
    {
        for(int i=1;i<=numar;i++)
        {
            nrm++;
            cin.getline(book[nrm].matematica,100);
        }
    }
    else
    if(stricmp(alege,"fizica")==0)
    {
        for(int i=1;i<=numar;i++)
        {
            nrf++;
            cin.getline(book[nrf].fizica,100);
        }
    }
    else
    if(stricmp(alege,"romana")==0)
    {
        for(int i=1;i<=numar;i++)
        {
            nrr++;
            cin.getline(book[nrr].romana,100);
        }
    }
    else
    if(stricmp(alege,"informatica")==0)
    {
        for(int i=1;i<=numar;i++)
        {
            nri++;
            cin.getline(book[nri].informatica,100);
        }
    }
    else
    if(stricmp(alege,"chimie")==0)
    {
        for(int i=1;i<=numar;i++)
        {
            nrc++;
            cin.getline(book[nrc].chimie,100);
        }
    }
    else
    if(stricmp(alege,"iesire")==0)
    {
        break;
    }


}



}




///datele citite se introduc in fisere caracteristice propietatii lor
///un fel de buton save
void carte::stocare()
{
    fstream f;

    if(nrb!=0)
    {f.open("beletristica",ios::out);
    f<<nrb<<'\n';
        for(int i=1;i<=nrb;i++)
        {
            f<<book[i].beletristica<<'\n';
        }


    f.close();
    }
    else
    {
        f.open("beletristica",ios::out);
        f<<0;
        f.close();
    }


    if(nrm!=0)
    {


    f.open("matematica",ios::out);

    f<<nrm<<'\n';
    for(int i=1;i<=nrm;i++)
    {
        f<<book[i].matematica<<'\n';
    }

    f.close();
    }
    else
    {
        f.open("matematica",ios::out);
        f<<0;
        f.close();
    }



    if(nrf!=0)
    {
    f.open("fizica",ios::out);

    f<<nrf<<'\n';
for(int i=1;i<=nrf;i++)
    f<<book[i].fizica<<'\n';
    f.close();
    }
    else
    {
        f.open("fizica",ios::out);
        f<<0;
        f.close();
    }



    if(nrr!=0)
    {
    f.open("romana",ios::out);

    f<<nrr<<'\n';
for(int i=1;i<=nrr;i++)
    f<<book[i].romana<<'\n';
    f.close();
    }
    else
    {
        f.open("romana",ios::out);
        f<<0;
        f.close();
    }


    if(nri!=0)
    {
    f.open("informatica",ios::out);

    f<<nri<<'\n';
    for(int i=1;i<=nri;i++)
        f<<book[i].informatica<<'\n';
    f.close();
    }
    else
    {
        f.open("informatica",ios::out);
        f<<0;
        f.close();
    }


    if(nrc!=0)
    {
    f.open("chimie",ios::out);

    f<<nrc<<'\n';
    for(int i=1;i<=nrc;i++)
        f<<book[i].chimie<<'\n';

    f.close();
    }
    else
    {
        f.open("chimie",ios::out);
        f<<0;
        f.close();
    }


}



///se initializeaza campurile de la clasa aspecte cu 0, iar in fisiere se va afisa 0 pe prima linie
void carte::initializare()
{
    nrb=nrm=nrf=nrr=nri=nrc=0;

fstream f;
    f.open("matematica",ios::out);
    f<<nrm<<'\n';
    f.close();

    f.open("beletristica",ios::out);
    f<<nrb<<'\n';
    f.close();

    f.open("fizica",ios::out);
    f<<nrf<<'\n';
    f.close();

    f.open("chimie",ios::out);
    f<<nrc<<'\n';
    f.close();

    f.open("romana",ios::out);
    f<<nrr<<'\n';
    f.close();

    f.open("informatica",ios::out);
    f<<nri<<'\n';
    f.close();

}



///se afiseaza continutul din campurile de mai sus
void carte::afisare()
{
    system("cls");
char tasta;

    cout<<"Aveti cartile:";

    if(nrb!=0)
    {
        cout<<"\nbeletristica\n";
        for(int i=1;i<=nrb;i++)
        cout<<book[i].beletristica<<'\n';
    }

    if(nrm!=0)
    {cout<<"\nmatematica:\n";
    for(int i=1;i<=nrm;i++)
            cout<<book[i].matematica<<'\n';
    }

    if(nrf!=0)
    {
    cout<<"\nfizica\n";
    for(int i=1;i<=nrf;i++)
        cout<<book[i].fizica<<'\n';
    }


    if(nrr!=0)
    {
    cout<<"\nromana\n";
    for(int i=1;i<=nrr;i++)
        cout<<book[i].romana<<'\n';
    }

    if(nri!=0)
    {
    cout<<"\ninformatica\n";
    for(int i=1;i<=nri;i++)
        cout<<book[i].informatica<<'\n';
    }

    if(nrc!=0)
    {
    cout<<"\nchimie\n";
    for(int i=1;i<=nrc;i++)
        cout<<book[i].chimie<<'\n';
    }

    cout<<"\n\nApasati o tasta apoi enter pentru a continua...";cin>>tasta;

}







///se creaza pentru prima data o baza de date
void carte::creere()
{
    char alegere[100];

while(0==0)
{

    system("cls");

cout<<"Ce carti doriti sa/sa mai introduceti sau iesiti?\n(beletristica)\n(matematica)\n(fizica)\n(romana)\n(informatica)\n(chimie)\n(iesire)\n\n";


cin>>alegere;
if(stricmp(alegere,"beletristica")==0)///daca doresti sa introduci carti de beletristica...
{
    cout<<"Cate carti doriti sa introduceti?\n";
    cin>>nrb;

cout<<"Introduceti cartile:";
    cin.get();
    for(int i=1;i<=nrb;i++)
    {
        cin.getline(book[i].beletristica,100);
    }
}
else
if(stricmp(alegere,"matematica")==0)
{
 cout<<"cate carti doriti sa introduceti?";
 cin>>nrm;

 cout<<"Introduceti cartile:";
    cin.get();

    for(int i=1;i<=nrm;i++)
    {
        cin.getline(book[i].matematica,100);
    }
}
else
if(stricmp(alegere,"fizica")==0)
{
    cout<<"Cate carti doriti sa introduceti?";
    cin>>nrf;
    cout<<"Introduceti cartile:";
    cin.get();
    for(int i=1;i<=nrf;i++)
    {
        cin.getline(book[i].fizica,100);
    }

}
else
if(stricmp(alegere,"romana")==0)
{
cout<<"Cate carti doriti sa introduceti?";
cin>>nrr;
cout<<"Introduceti cartile:";
cin.get();
for(int i=1;i<=nrr;i++)
{
    cin.getline(book[i].romana,100);
}
}
else
if(stricmp(alegere,"informatica")==0)
{
cout<<"Cate carti doriti sa introduceti?";
cin>>nri;
cout<<"Introduceti cartile:";
cin.get();
for(int i=1;i<=nri;i++)
{
    cin.getline(book[i].informatica,100);
}

}
else
if(stricmp(alegere,"chimie")==0)
{
cout<<"Cate carti doriti sa introduceti?";
cin>>nrc;
cout<<"Introduceti cartile:";
cin.get();
for(int i=1;i<=nrc;i++)
    {
    cin.getline(book[i].chimie,100);
    }
}
else
if(stricmp(alegere,"iesire")==0)
    break;

}

}

