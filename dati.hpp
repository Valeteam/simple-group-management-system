#pragma once
#include <vector>
#include <string>
using namespace std;

class dipendenti
{
public:
    int id;
    string nome;
    string cognome;
    int eta;
    double stipendio;
    string dataAssunzione;
    string ruolo;
    string password;

    int autoIncrement()
    {
        id++;
        return id;
    }
};

class prodotti
{
public:
    string nome;
    double costo;
    int quantita;
    int scortaMinima;
    int quantitaVenduta;
    int valoreSconto;
};

class banca
{
public:
    float budgetMensile;
    float costoMensile;
    float entrateMensili;
};

class clienti
{
public:
    string nome;
    string cognome;
    int eta;
    string paeseResidenza;
    string numeroTelefonico;
    string email;
    int spesaTotaleCliente = 0;
    int voucher = 0;
};

extern vector<dipendenti> groupFelice;
extern int prossimoIdDipendente;
extern vector<prodotti> groupFeliceProdotti;
extern vector<banca> bancaGroupFelice;
extern vector<clienti> groupFeliceCliente;