#include <iostream>
#include <fstream>
#include <ctime>
#include "dati.hpp"
#include "funzioni.hpp"

using namespace std;
void aggiungiProdotti()
{
    prodotti p;
    cout << "aggiungi dipendente\n";
    cout << "nome ";
    cin >> p.nome;
    cout << "prezzo ";
    cin >> p.costo;
    cout << "quantita ";
    cin >> p.quantita;
    cout << "scorta minima (sotto la quale vuoi essere avvisato) ";
    cin >> p.scortaMinima;

    groupFeliceProdotti.push_back(p);
    cout << "prodotto inserito correttamente\n\n";
}

void rimuoviProdotto()
{
    string name;
    int i = 0;
    cout << "inserisci nome prodotto ";
    cin >> name;

    while (groupFeliceProdotti.size() > i && name != groupFeliceProdotti[i].nome)
    {
        i++;
    }

    if (i == groupFeliceProdotti.size())
    {
        cout << "prodotti non presente\n\n";
    }
    else
    {
        groupFeliceProdotti.erase(groupFeliceProdotti.begin() + i);
        cout << "prodotto rimosso dall'inventario\n\n";
    }
}

void mostraProdotti()
{
    int couter = 1;
    for (int i = 0; i < groupFeliceProdotti.size(); i++)
    {
        cout << couter << " ) ";
        cout << "\t nome             \t|" << groupFeliceProdotti[i].nome << "\n";
        cout << "\t prezzo           \t|" << groupFeliceProdotti[i].costo << "\n";
        cout << "\t quantità         \t|" << groupFeliceProdotti[i].quantita << "\n";
        cout << "\t scorta minima    \t|" << groupFeliceProdotti[i].scortaMinima << "\n";
        couter++;
    }
}

void mostraScorteBasse()
{
    bool trovato = false;
    for (int i = 0; i < groupFeliceProdotti.size(); i++)
    {
        if (groupFeliceProdotti[i].quantita <= groupFeliceProdotti[i].scortaMinima)
        {
            trovato = true;
            cout << "\t ATTENZIONE: \t" << groupFeliceProdotti[i].nome
                 << " \t| quantità attuale: " << groupFeliceProdotti[i].quantita
                 << " \t| soglia minima: " << groupFeliceProdotti[i].scortaMinima << "\n";
        }
    }
    if (!trovato)
    {
        cout << "tutti i prodotti hanno una scorta sufficiente\n\n";
    }
    else
    {
        cout << "\n";
    }
}

void modificaProdotto()
{
    string name;
    int i = 0;
    cout << "inserisci nome prodotto ";
    cin >> name;

    while (groupFeliceProdotti.size() > i && name != groupFeliceProdotti[i].nome)
    {
        i++;
    }

    if (i == groupFeliceProdotti.size())
    {
        cout << "dipendente non presente\n\n";
    }
    else
    {
        int opzione;
        string nuovoNome;
        double nuovoPrezzo;
        int nuovaQuantita;
        int nuovoSconto;
        cout << "digita il campo che vuoi modificare\n";
        cout << "1) Nome\n";
        cout << "2) Prezzo\n";
        cout << "3) Quantita\n";
        cout << "4) Sconto\n";
        cin >> opzione;
        switch (opzione)
        {
        case 1:
            cin >> nuovoNome;
            groupFeliceProdotti[i].nome = nuovoNome;
            break;
        case 2:
            cin >> nuovoPrezzo;
            groupFeliceProdotti[i].costo = nuovoPrezzo;
            break;
        case 3:
            cin >> nuovaQuantita;
            groupFeliceProdotti[i].quantita = nuovaQuantita;
            break;
        case 4:
            cin >> nuovoSconto;
            groupFeliceProdotti[i].valoreSconto = nuovoSconto;
            break;
        default:
            break;
        }
        cout << "\t nome             \t|" << groupFeliceProdotti[i].nome << "\n";
        cout << "\t prezzo           \t|" << groupFeliceProdotti[i].costo << "\n";
        cout << "\t quantità         \t|" << groupFeliceProdotti[i].quantita << "\n";
    }
}

void salvaProdotti()
{
    ofstream file("db/prodotti.txt");

    for (int i = 0; i < groupFeliceProdotti.size(); i++)
    {
        file << groupFeliceProdotti[i].nome << " "
             << groupFeliceProdotti[i].costo << " "
             << groupFeliceProdotti[i].quantita << " "
             << groupFeliceProdotti[i].scortaMinima << "\n"
             << groupFeliceProdotti[i].quantitaVenduta << "\n"
             << groupFeliceProdotti[i].valoreSconto << "\n";
    }

    file.close();
}

void caricaProdotti()
{
    ifstream file("db/prodotti.txt");

    if (!file)
    {
        return;
    }

    prodotti p;
    while (file >> p.nome >> p.costo >> p.quantita >> p.scortaMinima >> p.quantitaVenduta >> p.valoreSconto)
    {
        groupFeliceProdotti.push_back(p);
    }

    file.close();
}
// fatta ia qui
void salvaScontrino(string nomeCliente, string dettaglio, float totale)
{
    ofstream file("db/scontrini.txt", ios::app);

    time_t adesso = time(0);
    tm *dataOra = localtime(&adesso);

    file << "======================================\n";
    file << "SCONTRINO n. " << numeroScontrino << "\n";
    file << "data: " << dataOra->tm_mday << "/" << (dataOra->tm_mon + 1) << "/" << (dataOra->tm_year + 1900) << "\n";
    file << "cliente: " << nomeCliente << "\n";
    file << dettaglio;
    file << "TOTALE: €" << totale << "\n";
    file << "======================================\n\n";

    file.close();
    numeroScontrino++;
}
void entrate()
{
    float costiEntrate = 0;
    string named;
    int quantity;
    string scelta = "YES";
    string tessera;
    int i = 0;

    // inserimento tessera cliente ( da sistemare con if iniziale)
    cout << "inserisci nome priprietario tessera ";
    cin >> tessera;

    while (i < groupFeliceCliente.size() && tessera != groupFeliceCliente[i].nome)
    {
        i++;
    }

    if (i == groupFeliceCliente.size())
    {
        cout << "cliente non trovato, impossibile registrare la vendita\n\n";
        return;
    }
    int numeroUsers = i;

    // inizio spesa

    float Spesa = 0;
    string dettaglioScontrino = "";

    while (scelta == "YES")
    {
        float valoreParziale = 0;
        int interdex = 0;
        int number = -1;

        cout << "inserisci nome prodotto venduto: ";
        cin >> named;
        cout << "inserisci quantità: ";
        cin >> quantity;

        // ricerca prodotto
        while (interdex < groupFeliceProdotti.size())
        {
            if (named == groupFeliceProdotti[interdex].nome)
            {
                number = interdex;
                break;
            }
            interdex++;
        }

        if (number == -1)
        {
            cout << "prodotto non trovato\n";
        }
        else if (quantity > groupFeliceProdotti[number].quantita)
        {
            cout << "quantità in magazzino insufficiente! disponibili: " << groupFeliceProdotti[number].quantita << "\n";
        }
        else
        {
            //? controllo se prodotto ha sconto
            if (groupFeliceProdotti[number].valoreSconto > 0)
            {
                // calcolo costo spesa di prodotto specifico con sconto
                valoreParziale = (quantity * groupFeliceProdotti[number].costo) - (((quantity * groupFeliceProdotti[number].costo) * groupFeliceProdotti[number].valoreSconto) / 100);
            }
            else
            {
                // calcolo costo spesa di prodotto specifico senza sconto
                valoreParziale = quantity * groupFeliceProdotti[number].costo;
            }
            // calcolo costo spesa totale x scontrino
            Spesa = Spesa + valoreParziale;
            // calcolo costo spesa x banca
            costiEntrate = costiEntrate + valoreParziale;
            // aggiungo per statistiche
            groupFeliceProdotti[number].quantitaVenduta += quantity;
            // rimuovo per scorte
            groupFeliceProdotti[number].quantita -= quantity;
            // dettaglio del scontrino
            dettaglioScontrino += "- " + groupFeliceProdotti[number].nome + " x" + to_string(quantity) + " = €" + to_string(valoreParziale) + "\n";
            //! riconoscimento soglia minima prodotti
            if (groupFeliceProdotti[number].quantita <= groupFeliceProdotti[number].scortaMinima)
            {
                cout << "attenzione: " << groupFeliceProdotti[number].nome << " è sceso sotto la scorta minima (" << groupFeliceProdotti[number].quantita << " rimasti)\n";
            }
        }
        cout << "altro prodotto? YES / NO ";
        cin >> scelta;
    }

    string scelta2;
    cout << "il valore della tua spesa è di: €" << Spesa << "\n";

    // gestione voucher
    if (groupFeliceCliente[numeroUsers].voucher > 0)
    {
        cout << "il cliente ha un voucher di €: " << groupFeliceCliente[numeroUsers].voucher << "\n";
        cout << "desidera usarlo? YES/NO ";
        cin >> scelta2;
        if (scelta2 == "YES")
        {
            if (Spesa >= 100)
            {
                int sconto = (groupFeliceCliente[numeroUsers].voucher < 20) ? groupFeliceCliente[numeroUsers].voucher : 20;
                if (sconto > 0)
                {
                    Spesa -= sconto;
                    costiEntrate -= sconto;
                    groupFeliceCliente[numeroUsers].voucher -= sconto;
                    cout << "dai tuoi voucher sono stati scalati €" << sconto << " di spesa\n";
                }
                else
                {
                    cout << "non avevi nessun voucher disponibile da scalare\n";
                }
                groupFeliceCliente[numeroUsers].voucher += 15;
                cout << "ti è stato accreditato un nuovo voucher da €15 per la prossima spesa\n";
            }
            else if (Spesa >= 50)
            {
                int sconto = (groupFeliceCliente[numeroUsers].voucher < 10) ? groupFeliceCliente[numeroUsers].voucher : 10;
                if (sconto > 0)
                {
                    Spesa -= sconto;
                    costiEntrate -= sconto;
                    groupFeliceCliente[numeroUsers].voucher -= sconto;
                    cout << "dai tuoi voucher sono stati scalati €" << sconto << " di spesa\n";
                }
                else
                {
                    cout << "non avevi nessun voucher disponibile da scalare\n";
                }
                groupFeliceCliente[numeroUsers].voucher += 10;
                cout << "ti è stato accreditato un nuovo voucher da €10 per la prossima spesa\n";
            }
            else
            {
                cout << "per la spesa che hai fatto non è previsto l'utilizzo di un voucher, eseguila da almeno €50\n";
                cout << "ti sono però stati accreditati altri €5 di voucher che potrai usare nella prossima spesa\n";
                groupFeliceCliente[numeroUsers].voucher = groupFeliceCliente[numeroUsers].voucher + 5;
            }
        }
    }
    else
    {
        if (Spesa >= 100)
        {
            groupFeliceCliente[numeroUsers].voucher += 15;
            cout << "ti è stato accreditato un nuovo voucher da €15 per la prossima spesa\n";
        }
        else if (Spesa >= 50)
        {
            groupFeliceCliente[numeroUsers].voucher += 10;
            cout << "ti è stato accreditato un nuovo voucher da €10 per la prossima spesa\n";
        }
        else
        {
            cout << "ti sono però stati accreditati altri €5 di voucher che potrai usare nella prossima spesa\n";
            groupFeliceCliente[numeroUsers].voucher = groupFeliceCliente[numeroUsers].voucher + 5;
        }
    }
    // aggiunto valore spesa al cliente x statistiche
    groupFeliceCliente[numeroUsers].spesaTotaleCliente += Spesa;
    // inserimento nella banca del gruppo
    bancaGroupFelice[0].entrateMensili = bancaGroupFelice[0].entrateMensili + costiEntrate;

    if (dettaglioScontrino != "")
    {
        salvaScontrino(groupFeliceCliente[numeroUsers].nome, dettaglioScontrino, Spesa);
        cout << "scontrino salvato in scontrini.txt\n\n";
    }
}
// visualizzazione del prodotto più venduto
void prodottoPiuVenduto()
{
    string piuVenduto;
    int max = 0;
    for (int i = 0; i < groupFeliceProdotti.size(); i++)
    {
        if (groupFeliceProdotti[i].quantitaVenduta > max)
        {
            max = groupFeliceProdotti[i].quantitaVenduta;
            piuVenduto = groupFeliceProdotti[i].nome;
        }
    }
    cout << "il prodotto più venduto è: " << piuVenduto << "\n"
         << endl;
}
