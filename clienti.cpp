#include <iostream>
#include <fstream>
#include "dati.hpp"
#include "funzioni.hpp"

using namespace std;

void creaCliente()
{
    clienti c;
    cout << "inserire nome cliente ";
    cin >> c.nome;
    cout << "inserire cognome cliente ";
    cin >> c.cognome;
    cout << "inserire età cliente ";
    cin >> c.eta;
    cout << "inserire paese di residenza cliente ";
    cin >> c.paeseResidenza;
    cout << "inserire recapito telefonico cliente ";
    cin >> c.numeroTelefonico;
    cout << "inserire indirizzo mail cliente ";
    cin >> c.email;

    groupFeliceCliente.push_back(c);
}

void eliminaCliente()
{
    string name;
    int position = 0;
    cout << "nome cliente da eliminare ";
    cin >> name;
    while (position < groupFeliceCliente.size() && name != groupFeliceCliente[position].nome)
    {
        position++;
    }
    if (position == groupFeliceCliente.size())
    {
        cout << "cliente inesistente";
    }
    else
    {
        groupFeliceCliente.erase(groupFeliceCliente.begin() + position);
        cout << "cliente eliminato con successo";
    }
}

void mostraClienti()
{
    for (int i = 0; i < groupFeliceCliente.size(); i++)
    {
        cout << "nome " << groupFeliceCliente[i].nome << "\n";
        cout << "cognome " << groupFeliceCliente[i].cognome << "\n";
        cout << "eta " << groupFeliceCliente[i].eta << "\n";
        cout << "paese di residenza " << groupFeliceCliente[i].paeseResidenza << "\n";
        cout << "numero telefono " << groupFeliceCliente[i].numeroTelefonico << "\n";
        cout << "email " << groupFeliceCliente[i].email << "\n";
        cout << "spesa totale effetuata " << groupFeliceCliente[i].spesaTotaleCliente << "\n";
        cout << "voucher " << groupFeliceCliente[i].voucher << "\n";
    }
}

void cercaCliente()
{
    string name;
    int position = 0;
    cout << "nome cliente da cercare ";
    cin >> name;
    while (position < groupFeliceCliente.size() && name != groupFeliceCliente[position].nome)
    {
        position++;
    }
    if (position != groupFeliceCliente.size())
    {
        cout << "nome " << groupFeliceCliente[position].nome;
        cout << "cognome " << groupFeliceCliente[position].cognome << "\n";
        cout << "eta " << groupFeliceCliente[position].eta << "\n";
        cout << "paese di residenza " << groupFeliceCliente[position].paeseResidenza << "\n";
        cout << "numero telefono " << groupFeliceCliente[position].numeroTelefonico << "\n";
        cout << "email " << groupFeliceCliente[position].email << "\n";
        cout << "spesa totale effetuata " << groupFeliceCliente[position].spesaTotaleCliente << "\n";
        cout << "voucher " << groupFeliceCliente[position].voucher << "\n";
    }
    else
    {
        cout << "non esiste il cliente, riprovare\n\n";
    }
}

void modificaCliente()
{
    string name;
    int position = 0;
    cout << "nome cliente da modificare ";
    cin >> name;
    while (position < groupFeliceCliente.size() && name != groupFeliceCliente[position].nome)
    {
        position++;
    }
    if (position != groupFeliceCliente.size())
    {
        int option;
        cout << "cosa vuoi modificare?\n";
        cout << "1) nome\n";
        cout << "2) cognome\n";
        cout << "3) eta\n";
        cout << "4) telefono\n";
        cout << "5) residenza\n";
        cout << "6) email\n";
        cin >> option;
        string newName;
        string newSurname;
        int newEta;
        string newPhone;
        string newMail;
        string newResidence;
        switch (option)
        {
        case 1:
            printf("inserisci nuovo nome ");
            cin >> newName;
            groupFeliceCliente[position].nome = newName;
            break;
        case 2:
            printf("inserisci nuovo cognome ");
            cin >> newSurname;
            groupFeliceCliente[position].cognome = newSurname;
            break;
        case 3:
            printf("inserisci nuovo eta ");
            cin >> newEta;
            groupFeliceCliente[position].eta = newEta;
            break;
        case 4:
            printf("inserisci nuovo telefono ");
            cin >> newPhone;
            groupFeliceCliente[position].numeroTelefonico = newPhone;
            break;
        case 5:
            printf("inserisci nuovo residenza ");
            cin >> newResidence;
            groupFeliceCliente[position].paeseResidenza = newResidence;
            break;
        case 6:
            printf("inserisci nuovo email ");
            cin >> newMail;
            groupFeliceCliente[position].email = newMail;
            break;
        default:
            break;
        }
        cout << "i nuovi dati del cliente sono: \n";
        cout << "nome " << groupFeliceCliente[position].nome;
        cout << "cognome " << groupFeliceCliente[position].cognome << "\n";
        cout << "eta " << groupFeliceCliente[position].eta << "\n";
        cout << "paese di residenza " << groupFeliceCliente[position].paeseResidenza << "\n";
        cout << "numero telefono " << groupFeliceCliente[position].numeroTelefonico << "\n";
        cout << "email " << groupFeliceCliente[position].email << "\n";
    }
    else
    {
        cout << "utente non esistente\n";
    }
}

void clientePiuPresente()
{
    int max = 0;
    string nomeCliente;

    for (int i = 0; i < groupFeliceCliente.size(); i++)
    {
        if (groupFeliceCliente[i].spesaTotaleCliente > max)
        {
            max = groupFeliceCliente[i].spesaTotaleCliente;
            nomeCliente = groupFeliceCliente[i].nome;
        }
    }
    cout << "il cliente che spende di più nel nostro punto vendita è: " << nomeCliente << "\n"
         << endl;
}

void salvaClienti()
{
    ofstream file("db/clienti.txt");

    for (int i = 0; i < groupFeliceCliente.size(); i++)
    {
        file << groupFeliceCliente[i].nome << " "
             << groupFeliceCliente[i].cognome << " "
             << groupFeliceCliente[i].email << " "
             << groupFeliceCliente[i].eta << " "
             << groupFeliceCliente[i].numeroTelefonico << " "
             << groupFeliceCliente[i].paeseResidenza << " "
             << groupFeliceCliente[i].spesaTotaleCliente << " "
             << groupFeliceCliente[i].voucher << "\n";
    }

    file.close();
}

void caricaClienti()
{
    ifstream file("db/clienti.txt");

    if (!file)
    {
        return;
    }

    clienti c;
    while (file >> c.cognome >> c.email >> c.eta >> c.nome >> c.numeroTelefonico >> c.paeseResidenza >> c.spesaTotaleCliente >> c.voucher)
    {
        groupFeliceCliente.push_back(c);
    }

    file.close();
}
