#include <iostream>
#include <fstream>
#include "dati.hpp"
#include "funzioni.hpp"

using namespace std;

void inizializzaBanca()
{
    banca b;
    b.budgetMensile = 0;
    b.costoMensile = 0;
    b.entrateMensili = 0;
    bancaGroupFelice.push_back(b);
}

void mostraBanca()
{
    cout << "\t budget mensile  \t|" << bancaGroupFelice[0].budgetMensile << "\n";
    cout << "\t entrate mensili \t|" << bancaGroupFelice[0].entrateMensili << "\n";
    cout << "\t costo mensile   \t|" << bancaGroupFelice[0].costoMensile << "\n";
    cout << "\t saldo           \t|" << (bancaGroupFelice[0].budgetMensile + bancaGroupFelice[0].entrateMensili - bancaGroupFelice[0].costoMensile) << "\n\n";
}

//?costi da sistemare

void costi()
{
    float totaleCosti = 0;
    int i = 0;
    while (i < groupFelice.size())
    {
        totaleCosti = totaleCosti + groupFelice[i].stipendio;
        i++;
    }
    bancaGroupFelice[0].costoMensile = bancaGroupFelice[0].costoMensile + totaleCosti;
}

void salvaBanca()
{
    ofstream file("db/banca.txt");
    file << bancaGroupFelice[0].budgetMensile << " "
         << bancaGroupFelice[0].costoMensile << " "
         << bancaGroupFelice[0].entrateMensili << "\n";
    file.close();
}

void caricaBanca()
{
    ifstream file("db/banca.txt");

    if (!file)
    {
        inizializzaBanca();
        return;
    }

    banca b;
    if (file >> b.budgetMensile >> b.costoMensile >> b.entrateMensili)
    {
        bancaGroupFelice.push_back(b);
    }
    else
    {
        inizializzaBanca();
    }

    file.close();
}

void lavoriBanca()
{
    float prezzo;
    cout << "Inserisci il budget per l'azienda: ";
    cin >> prezzo;
    bancaGroupFelice[0].budgetMensile = prezzo;
}

