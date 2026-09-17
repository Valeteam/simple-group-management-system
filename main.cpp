#include <iostream>
#include <filesystem>
#include "dati.hpp"
#include "funzioni.hpp"

using namespace std;

int main()
{
    int firstOption;
    introtext();

    filesystem::create_directories("db");

    caricaDipendenti();

    bool trovatoAdmin = false;
    for (int i = 0; i < groupFelice.size(); i++)
    {
        if (groupFelice[i].cognome == "admin")
        {
            trovatoAdmin = true;
            break;
        }
    }
    if (!trovatoAdmin)
    {
        dipendenteAdmin();
    }

    login();

    caricaProdotti();
    caricaBanca();

    do
    {
        cout << "\t Tasto 1 per gestire il personale\n";
        cout << "\t Tasto 2 per gestire i prodotti\n";
        cout << "\t Tasto 3 per accedere al gestore vendita\n";
        cout << "\t Tasto 4 per accedere al gestore clienti\n";
        cout << "\t Tasto 5 per uscire dal programma\n";
        cin >> firstOption;
        switch (firstOption)
        {
        case 1:
            int secondOption;
            do
            {
                cout << "\t Tasto 1 per aggiungere dipendente\n";
                cout << "\t Tasto 2 per rimuovere dipendente\n";
                cout << "\t Tasto 3 per mostrare lista dipendenti\n";
                cout << "\t Tasto 4 per modificare dipendente\n";
                cout << "\t Tasto 5 per visualizzare dipendente più costoso\n";
                cout << "\t Tasto 6 per tornare al menu principale\n";
                cin >> secondOption;

                switch (secondOption)
                {
                case 1:
                    aggiungiDipendente();
                    break;
                case 2:
                    rimuoviDipendente();
                    break;
                case 3:
                    mostraDipendente();
                    break;
                case 4:
                    modificaDipendente();
                    break;
                case 5:
                    dipendendePiuCostoso();
                    break;
                default:
                    break;
                }
            } while (secondOption < 6);
            break;

        case 2:
            int thirtOption;
            do
            {
                cout << "\t Tasto 1 per aggiungere prodotto\n";
                cout << "\t Tasto 2 per rimuovere prodotto\n";
                cout << "\t Tasto 3 per mostrare lista prodotti\n";
                cout << "\t Tasto 4 per modificare prodotto\n";
                cout << "\t Tasto 5 per mostrare prodotti in esaurimento\n";
                cout << "\t Tasto 6 per mostrare prodotto più venduto\n";
                cout << "\t Tasto 7 per tornare al menu principale\n";
                cin >> thirtOption;
                switch (thirtOption)
                {
                case 1:
                    aggiungiProdotti();
                    break;
                case 2:
                    rimuoviProdotto();
                    break;
                case 3:
                    mostraProdotti();
                    break;
                case 4:
                    modificaProdotto();
                    break;
                case 5:
                    mostraScorteBasse();
                    break;
                case 6:
                    prodottoPiuVenduto();
                    break;
                default:
                    break;
                }
            } while (thirtOption < 7);
            break;

        case 3:
            int fourthOption;
            do
            {
                cout << "\t Tasto 1 per impostare il budget\n";
                cout << "\t Tasto 2 per registrare le entrate (vendite)\n";
                cout << "\t Tasto 3 per registrare i costi (stipendi)\n";
                cout << "\t Tasto 4 per mostrare il bilancio\n";
                cout << "\t Tasto 5 per tornare al menu principale\n";
                cin >> fourthOption;
                switch (fourthOption)
                {
                case 1:
                    lavoriBanca();
                    break;
                case 2:
                    entrate();
                    break;
                case 3:
                    costi();
                    break;
                case 4:
                    mostraBanca();
                    break;
                default:
                    break;
                }
            } while (fourthOption < 5);
            break;
        case 4:
            int fifthoption;
            do
            {
                cout << "\t Tasto 1 per creare card cliente\n";
                cout << "\t Tasto 2 per eliminare cliente\n";
                cout << "\t Tasto 3 per mostrare tutti i clienti\n";
                cout << "\t Tasto 4 per modificare cliente\n";
                cout << "\t Tasto 5 per cercare cliente\n";
                cout << "\t Tasto 6 per mostrare cliente che spende di più\n";
                cout << "\t Tasto 7 per tornare al menu principale\n";
                cin >> fifthoption;
                switch (fifthoption)
                {
                case 1:
                    creaCliente();
                    break;
                case 2:
                    eliminaCliente();
                    break;
                case 3:
                    mostraClienti();
                    break;
                case 4:
                    modificaCliente();
                    break;
                case 5:
                    cercaCliente();
                    break;
                case 6:
                    clientePiuPresente();
                    break;
                default:
                    break;
                }
            } while (fifthoption < 7);
            break;

        default:
            break;
        }
    } while (firstOption <= 4);

    salvaDipendenti();
    salvaProdotti();
    salvaBanca();
    cout << "\ndati salvati su file, arrivederci!\n";

    double somma1 = 0;
    double somma2 = 0;
    double sommaTotale = 0;
    int inter = 0;
    int interaction = 0;
    while (groupFelice.size() > inter)
    {
        somma1 = somma1 + groupFelice[inter].stipendio;
        inter++;
    }
    while (groupFeliceProdotti.size() > interaction)
    {
        double valore;
        valore = groupFeliceProdotti[interaction].costo * groupFeliceProdotti[interaction].quantita;
        somma2 = somma2 + valore;
        interaction++;
    }
    double saldoBanca = bancaGroupFelice[0].budgetMensile + bancaGroupFelice[0].entrateMensili - bancaGroupFelice[0].costoMensile;
    sommaTotale = somma1 + somma2 + saldoBanca;

    cout << "\nriepilogo finale:\n";
    cout << "\t totale stipendi dipendenti \t|" << somma1 << "\n";
    cout << "\t valore magazzino           \t|" << somma2 << "\n";
    cout << "\t saldo banca                \t|" << saldoBanca << "\n";
    cout << "\t patrimonio totale          \t|" << sommaTotale << "\n\n";

    outrotext();
}

void introtext()
{
    cout << "\t##############################\n";
    cout << "\t##############################\n";
    cout << "\t## Benvenuto nel gestionale ##\n";
    cout << "\t##                          ##\n";
    cout << "\t## Group Felice Supermarket ##\n";
    cout << "\t##############################\n";
    cout << "\t##############################\n\n\n"
         << endl;
};

void outrotext()
{
    cout << "\t##############################\n";
    cout << "\t##############################\n";
    cout << "\t##        Arrivederci       ##\n";
    cout << "\t##                          ##\n";
    cout << "\t## Group Felice Supermarket ##\n";
    cout << "\t##############################\n";
    cout << "\t##############################\n\n\n"
         << endl;
};
