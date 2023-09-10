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
    std::vector<Attivita> getAttivitaPerGiorno(const QDate& data) const;
    bool esisteAttivitaSovrapposta(const QDateTime& inizio, const QDateTime& fine) const;


private:
    std::vector<Attivita> attivita;
};


#endif //REGISTRO_ATTIVITA_GRAFICA_REGISTRO_H
