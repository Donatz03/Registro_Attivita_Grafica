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