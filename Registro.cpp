//
// Created by Mattia Donadoni on 25/08/23.
//

#include "Registro.h"

void Registro::aggiungiAttivita(const Attivita& attivita) {
    this->attivita.push_back(attivita);
}

std::vector<Attivita> Registro::getAttivitaPerGiorno(const QDate& data) const {
    std::vector<Attivita> attivitaDelGiorno;

    for (const Attivita& attivita : attivita) {
        if (attivita.getTempoInizio().date() == data) {
            attivitaDelGiorno.push_back(attivita);
        }
    }

    return attivitaDelGiorno;
}

void Registro::rimuoviAttivita(const QDate& data, const QString& Descrizione, const QTime& inizio, const QTime& fine) {
    for (int i = 0; i < attivita.size(); i++) {
        if (attivita[i].getTempoInizio().date() == data && attivita[i].getDescrizione() == Descrizione && attivita[i].getTempoInizio().time() == inizio && attivita[i].getTempoFine().time() == fine) {
            attivita.erase(attivita.begin() + i);
        }
    }
}

bool Registro::esisteAttivitaSovrapposta(const QDateTime& inizio, const QDateTime& fine) const {
    for (const Attivita& attivita : attivita) {
        if (attivita.getTempoInizio() >= inizio && attivita.getTempoInizio() < fine) {
            return true;
        }
        if (attivita.getTempoFine() > inizio && attivita.getTempoFine() <= fine) {
            return true;
        }
        if (attivita.getTempoInizio() <= inizio && attivita.getTempoFine() >= fine) {
            return true;
        }
    }

    return false;
}