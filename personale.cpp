#include <iostream>
#include <fstream>
#include "dati.hpp"
#include "funzioni.hpp"

using namespace std;

void dipendenteAdmin()
{
    dipendenti d;
    d.id = prossimoIdDipendente++;
    d.nome = "admin";
    d.cognome = "admin";
    d.eta = 16;
    d.dataAssunzione = "08-09-2026";
    d.ruolo = "CEO";
    d.stipendio = 5000;
    d.password = "AdminAcces2020";
    groupFelice.push_back(d);
}

void salvaDipendenti()
{
    ofstream file("db/dipendenti.txt");

    for (int i = 0; i < groupFelice.size(); i++)
    {
        file << groupFelice[i].id << " "
             << groupFelice[i].nome << " "
             << groupFelice[i].cognome << " "
             << groupFelice[i].eta << " "
             << groupFelice[i].stipendio << " "
             << groupFelice[i].dataAssunzione << " "
             << groupFelice[i].ruolo << " "
             << groupFelice[i].password << "\n";
    }

    file.close();
}

void caricaDipendenti()
{
    ifstream file("db/dipendenti.txt");

    if (!file)
    {
        return;
    }

    dipendenti d;
    while (file >> d.id >> d.nome >> d.cognome >> d.eta >> d.stipendio >> d.dataAssunzione >> d.ruolo >> d.password)
    {
        groupFelice.push_back(d);
        if (d.id >= prossimoIdDipendente)
        {
            prossimoIdDipendente = d.id + 1;
        }
    }

    file.close();
}

void login()
{
    string psw;
    string cgn;
    bool accessoRiuscito = false;
    int i;

    do
    {
        i = 0;
        cout << "inserisci cognome ";
        cin >> cgn;

        while (i < groupFelice.size() && groupFelice[i].cognome != cgn)
        {
            i++;
        }

        if (i != groupFelice.size())
        {
            cout << "inserisci password ";
            cin >> psw;
            if (groupFelice[i].password == psw)
            {
                accessoRiuscito = true;
                cout << "accesso riuscito, buon lavoro\n";
            }
            else
            {
                accessoRiuscito = false;
                cout << "credenziali errate\n";
            }
        }
        else
        {
            accessoRiuscito = false;
            cout << "credenziali errate\n";
        }
    } while (accessoRiuscito == false);
}

void aggiungiDipendente()
{
    dipendenti d;
    d.id = prossimoIdDipendente++;
    cout << "aggiungi dipendente\n ";
    cout << "nome ";
    cin >> d.nome;
    cout << "cognome ";
    cin >> d.cognome;
    cout << "eta ";
    cin >> d.eta;
    cout << "stipendio ";
    cin >> d.stipendio;
    cout << "data di assunzione ";
    cin >> d.dataAssunzione;
    cout << "ruolo ricoperto ";
    cin >> d.ruolo;
    cout << "crea una password per l'accesso ";
    cin >> d.password;

    groupFelice.push_back(d);
    cout << "dipendende inserito correttamente\n\n";
}

void rimuoviDipendente()
{
    string name;
    int i = 0;
    cout << "inserisci nome dipendente ";
    cin >> name;

    while (groupFelice.size() > i && name != groupFelice[i].nome)
    {
        i++;
    }

    if (i == groupFelice.size())
    {
        cout << "dipendente non presente\n\n";
    }
    else
    {
        groupFelice.erase(groupFelice.begin() + i);
        cout << "dipendente rimosso dal database aziendale\n\n";
    }
}

void mostraDipendente()
{
    int couter = 1;
    for (int i = 0; i < groupFelice.size(); i++)
    {
        cout << couter << " ) ";
        cout << "\t id              \t|" << groupFelice[i].id << "\n";
        cout << "\t nome            \t|" << groupFelice[i].nome << "\n";
        cout << "\t cognome         \t|" << groupFelice[i].cognome << "\n";
        cout << "\t eta             \t|" << groupFelice[i].eta << "\n";
        cout << "\t data Assunzione \t|" << groupFelice[i].dataAssunzione << "\n";
        cout << "\t stipendio       \t|" << groupFelice[i].stipendio << "\n";
        cout << "\t ruolo           \t|" << groupFelice[i].ruolo << "\n\n";
        couter++;
    }
}

void modificaDipendente()
{
    string name;
    int i = 0;
    cout << "inserisci nome dipendente ";
    cin >> name;

    while (groupFelice.size() > i && name != groupFelice[i].nome)
    {
        i++;
    }

    if (i == groupFelice.size())
    {
        cout << "dipendente non presente\n\n";
    }
    else
    {
        int opzione;
        string nuovoNome;
        string nuovoCognome;
        int nuovaEta;
        double nuovoStipendio;
        string nuovoRuolo;
        string nuovaDataAssunzione;
        cout << "digita il campo che vuoi modificare\n";
        cout << "1) Nome\n";
        cout << "2) cognome\n";
        cout << "3) eta\n";
        cout << "4) stipendio\n";
        cout << "5) data Assunzione\n";
        cout << "6) ruolo\n";
        cin >> opzione;
        switch (opzione)
        {
        case 1:
            cin >> nuovoNome;
            groupFelice[i].nome = nuovoNome;
            break;
        case 2:
            cin >> nuovoCognome;
            groupFelice[i].cognome = nuovoCognome;
            break;
        case 3:
            cin >> nuovaEta;
            groupFelice[i].eta = nuovaEta;
            break;
        case 4:
            cin >> nuovoStipendio;
            groupFelice[i].stipendio = nuovoStipendio;
            break;
        case 5:
            cin >> nuovaDataAssunzione;
            groupFelice[i].dataAssunzione = nuovaDataAssunzione;
            break;
        case 6:
            cin >> nuovoRuolo;
            groupFelice[i].ruolo = nuovoRuolo;
            break;

        default:
            break;
        }

        cout << "\t nome \t" << groupFelice[i].nome << "\n";
        cout << "\t cognome \t" << groupFelice[i].cognome << "\n";
        cout << "\t eta \t" << groupFelice[i].eta << "\n";
        cout << "\t data Assunzione \t" << groupFelice[i].dataAssunzione << "\n";
        cout << "\t stipendio \t" << groupFelice[i].stipendio << "\n";
        cout << "\t ruolo \t" << groupFelice[i].ruolo << "\n\n";
    };
};

void dipendendePiuCostoso()
{
    double max = 0;
    string nameDipendente;

    for (int i = 0; i < groupFelice.size(); i++)
    {
        if (groupFelice[i].nome != "admin" && groupFelice[i].stipendio > max)
        {
            max = groupFelice[i].stipendio;
            nameDipendente = groupFelice[i].nome;
        }
    }
    cout << "il dipendete che guadagna di più è: " << nameDipendente << "\n";
}
