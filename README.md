# 🛒 Simple Group Management System

### Il gestionale da terminale per far girare un supermercato. Veloce, leggero, tutto in C++.

```
	##############################
	## Benvenuto nel gestionale ##
	##############################
```

**👥 Personale · 📦 Magazzino · 💰 Bilancio · 🧾 Clienti**

---

## 🎯 Cos'è

**Simple Group Management System** è un gestionale completo che gira nel terminale. Con un solo programma gestisci i **dipendenti**, tieni sotto controllo le **scorte di magazzino**, registri **entrate e costi**, fidelizzi i **clienti** con card e voucher e ottieni a fine giornata un **riepilogo del patrimonio**.

Niente database da installare, niente server: avvii l'eseguibile, fai il login e lavori. I dati vengono salvati in automatico nella cartella `db/`.

---

## ✨ Funzionalità

### 👥 Personale
- ➕ Aggiungi dipendenti
- ➖ Rimuovi dipendenti
- ✏️ Modifica i dati di un dipendente
- 📋 Mostra l'elenco completo
- 💸 Trova il **dipendente più costoso**

### 📦 Prodotti e magazzino
- ➕ Aggiungi prodotti
- ➖ Rimuovi prodotti
- ✏️ Modifica i dati di un prodotto
- 📋 Mostra l'elenco dei prodotti
- 🚨 Segnala i prodotti **in esaurimento**
- 🏆 Mostra il **prodotto più venduto**

### 💰 Vendite e bilancio
- 🎯 Imposta il **budget** mensile
- 📈 Registra le **entrate** (vendite)
- 📉 Registra i **costi** (stipendi)
- 📊 Mostra il **bilancio**

### 🧾 Clienti
- 🪪 Crea la **card cliente**
- 🗑️ Elimina un cliente
- ✏️ Modifica i dati di un cliente
- 🔎 Cerca un cliente
- 📋 Mostra tutti i clienti
- 👑 Trova il **cliente che spende di più**

---

## ✏️ Cosa puoi modificare

Il gestionale è pensato per essere **adattato al tuo negozio**. Ecco tutto ciò che l'utente può inserire, cambiare e personalizzare, diviso per area.

### 👥 Dipendenti

| Campo | Tipo | Cosa rappresenta |
| --- | --- | --- |
| `nome` | testo | Nome del dipendente |
| `cognome` | testo | Cognome del dipendente |
| `eta` | numero intero | Età |
| `stipendio` | numero decimale | Stipendio mensile (conta nei costi e nel riepilogo finale) |
| `dataAssunzione` | testo | Data di assunzione |
| `ruolo` | testo | Mansione ricoperta |
| `password` | testo | Password personale per il login |

> 🔑 L'`id` viene assegnato automaticamente dal sistema (auto-incremento).

### 📦 Prodotti

| Campo | Tipo | Cosa rappresenta |
| --- | --- | --- |
| `nome` | testo | Nome del prodotto |
| `costo` | numero decimale | Costo del prodotto (determina il valore del magazzino) |
| `quantita` | numero intero | Pezzi disponibili in magazzino |
| `scortaMinima` | numero intero | Soglia sotto la quale il prodotto risulta **in esaurimento** |
| `valoreSconto` | numero intero | Sconto applicato al prodotto |

> 📌 `quantitaVenduta` parte da 0 e si aggiorna con le vendite: è ciò che permette di calcolare il prodotto più venduto.

### 💰 Banca e bilancio

| Campo | Tipo | Cosa rappresenta |
| --- | --- | --- |
| `budgetMensile` | numero decimale | Budget di partenza, impostabile dal menu *"impostare il budget"* |
| `entrateMensili` | numero decimale | Incassi registrati con *"registrare le entrate"* |
| `costoMensile` | numero decimale | Spese registrate con *"registrare i costi"* |

La formula del saldo è semplice: `saldo = budget + entrate − costi`

### 🧾 Clienti

| Campo | Tipo | Cosa rappresenta |
| --- | --- | --- |
| `nome` | testo | Nome del cliente |
| `cognome` | testo | Cognome del cliente |
| `eta` | numero intero | Età |
| `paeseResidenza` | testo | Paese di residenza |
| `numeroTelefonico` | testo | Numero di telefono |
| `email` | testo | Indirizzo email |

> 📌 `spesaTotaleCliente` e `voucher` partono da 0 e crescono con gli acquisti del cliente.

---

## 🧭 Come si naviga

Si usa solo la tastiera: digiti il numero dell'opzione e premi invio.

```
🔐 Login
 └── Menu principale
      ├── 1 → 👥 Personale
      │        └── Aggiungi · Rimuovi · Mostra · Modifica · Più costoso
      ├── 2 → 📦 Prodotti
      │        └── Aggiungi · Rimuovi · Mostra · Modifica · Scorte basse · Più venduto
      ├── 3 → 💰 Gestore vendita
      │        └── Budget · Entrate · Costi · Bilancio
      ├── 4 → 🧾 Gestore clienti
      │        └── Crea · Elimina · Mostra · Modifica · Cerca · Top cliente
      └── 5 → 💾 Salva ed esci
```

Ogni sottomenu ha un tasto per tornare al menu principale. **Esci sempre con il tasto 5**: è l'unico modo per salvare i dati e vedere il riepilogo finale.

---

## 📊 Riepilogo finale

Quando chiudi il programma ottieni una fotografia di tutta l'attività:

```
riepilogo finale:
	 totale stipendi dipendenti 	| ...
	 valore magazzino 	        | ...
	 saldo banca 	                | ...
	 patrimonio totale 	        | ...
```

| Voce | Come viene calcolata |
| --- | --- |
| Totale stipendi | Somma degli stipendi di tutti i dipendenti |
| Valore magazzino | Somma di `costo × quantità` di ogni prodotto |
| Saldo banca | `budget + entrate − costi` |
| **Patrimonio totale** | Stipendi + magazzino + saldo banca |

---

## 🔐 Sicurezza e dati

- 🔑 **Login obbligatorio** a ogni avvio.
- 🛡️ Se non esiste un utente amministratore, il programma lo **crea automaticamente** al primo avvio.
- 💾 I dati vengono **caricati all'avvio** e **salvati all'uscita** nella cartella `db/`, che viene creata da sola se manca.
- 📦 Dipendenti, prodotti, banca e clienti hanno ciascuno il proprio salvataggio.

---

## 🚀 Installazione in 30 secondi

### Requisiti
Un compilatore C++ con supporto **C++17** (serve per `<filesystem>`): `g++`, `clang++` o MSVC.

### Compila

```bash
git clone https://github.com/Valeteam/simple-group-management-system.git
cd simple-group-management-system

g++ -std=c++17 main.cpp dati.cpp personale.cpp magazzino.cpp banca.cpp clienti.cpp -o gestionale
```

### Avvia

```bash
./gestionale        # Linux / macOS
gestionale.exe      # Windows
```

---

## 🗂️ Struttura del progetto

```
simple-group-management-system/
├── 📄 main.cpp          # Ingresso, login e menu
├── 📄 dati.hpp / .cpp   # Classi dati e variabili globali
├── 📄 funzioni.hpp      # Dichiarazione delle funzioni
├── 👥 personale.cpp     # Gestione dipendenti
├── 📦 magazzino.cpp     # Gestione prodotti e scorte
├── 💰 banca.cpp         # Budget, entrate, costi, bilancio
├── 🧾 clienti.cpp       # Gestione clienti
└── 💾 db/               # File di salvataggio
```

---

## 🛠️ Tecnologie

![C++17](https://img.shields.io/badge/Linguaggio-C%2B%2B17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Piattaforme](https://img.shields.io/badge/Piattaforme-Windows%20%7C%20Linux%20%7C%20macOS-2ea44f?style=for-the-badge)
![Interfaccia](https://img.shields.io/badge/Interfaccia-Terminale-6e40c9?style=for-the-badge)
![Dati](https://img.shields.io/badge/Dati-Salvati%20su%20file-e5732c?style=for-the-badge)
![Libreria](https://img.shields.io/badge/Libreria-STL%20%2B%20filesystem-0366d6?style=for-the-badge)

---

## 👤 Autore

Sviluppato da **[Valeteam](https://github.com/Valeteam)**.

⭐ Se il progetto ti piace, lascia una stella al repository!
