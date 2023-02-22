#include"carte.h"
#include<iostream>
using namespace std;


int main()
{
char s[100];

carte R;///R vine de la Rosiori, adica de la mine de acasa :)

/**din acest moment caramizile sunt create dar trebuie sa le imbinam astfel in cat sa ridicam zidul, ceea
ce urmeaza se va comporta ca un meniu ce va respecta precizarile utilizatorului.*/


R.rememorare();/**daca exista deja o baza de date se va rememora, indiferent de deciziile utilizatorului |||
prima data baza de date nu exista, se creaza una, apoi se eventual este distrusa, se creaza o alta
si tot asa...*/


while(0==0)
{
system("cls");

cout<<"creere baza de date noua\n";
cout<<"afisare\n";
cout<<"distruge baza de date curenta\n";///(inizializare)
cout<<"salvare\n";///(stocare)
cout<<"adaugare\n";
cout<<"sterge\n";
cout<<"inchide program\n\n";

cin.getline(s,255);

if(stricmp(s,"creere")==0)
{
    R.creere();
}
else
if(stricmp(s,"afisare")==0)
{
    R.afisare();
}
else
if(stricmp(s,"distruge")==0)
{
    R.initializare();
}
else
if(stricmp(s,"salvare")==0)
{
    R.stocare();
}
else
if(stricmp(s,"adaugare")==0)
{
    R.adaugare();
}
else
if(stricmp(s,"sterge")==0)
{
    R.sterge();
}
else
if(stricmp(s,"inchide")==0)
{
    break;
}

}

    return 0;
}
