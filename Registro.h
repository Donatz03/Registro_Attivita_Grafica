//
// Created by Mattia Donadoni on 25/08/23.
//

#ifndef REGISTRO_ATTIVITA_GRAFICA_REGISTRO_H
#define REGISTRO_ATTIVITA_GRAFICA_REGISTRO_H


#include "Attivita.h"
#include <vector>
#include <iostream>

class Registro {
public:
    void aggiungiAttivita(const Attivita& attivita);
    bool rimuoviAttivita(const QDate &data, const QString &descrizione, const QTime &inizio, const QTime &fine);
    bool ricercaAttivitaNomeGionaliera(const QDate& data, const QString &descrizione) const;
    bool modificareAttivita(const QDate& data, const QString& descrizione, const QTime& inizio, const QTime& fine, const QString& nuovaDescrizione, const QTime& nuovoInizio, const QTime& nuovoFine);
    std::vector<Attivita> getAttivitaPerGiorno(const QDate& data) const;
    bool esisteAttivitaSovrapposta(const QDateTime& inizio, const QDateTime& fine) const;
    bool esisteAttivitaSovrapposta(const QDateTime& inizio, const QDateTime& fine, const Attivita& attivitaDaEscludere) const;


private:
    std::vector<Attivita> attivita;
};


#endif //REGISTRO_ATTIVITA_GRAFICA_REGISTRO_H
