#pragma once
#include <string>

void login();

void aggiungiDipendente();
void rimuoviDipendente();
void mostraDipendente();
void modificaDipendente();
void modificaProdotto();
void introtext();
void outrotext();
void aggiungiProdotti();
void rimuoviProdotto();
void mostraProdotti();
void mostraScorteBasse();
void salvaProdotti(); 
void caricaProdotti();
void inizializzaBanca();
void salvaBanca(); 
void caricaBanca(); 
void dipendenteAdmin();
void salvaDipendenti();
void caricaDipendenti();
void mostraBanca();
void costi();
void entrate();
void lavoriBanca();
void salvaScontrino(std::string nomeCliente, std::string dettaglio, float totale);
void creaCliente();
void eliminaCliente();
void mostraClienti();
void modificaCliente();
void cercaCliente();
void prodottoPiuVenduto();
void clientePiuPresente();
void dipendendePiuCostoso();