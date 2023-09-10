//
// Created by Mattia Donadoni on 22/08/23.
//

#include "Attivita.h"

Attivita::Attivita(const QString& descrizione, const QDateTime& inizio, const QDateTime& fine) : descrizione(descrizione), tempoInizio(inizio), tempoFine(fine) {
    controllo();
}

QString Attivita::getDescrizione() const {
    return descrizione;
}

QDateTime Attivita::getTempoInizio() const {
    return tempoInizio;
}

QDateTime Attivita::getTempoFine() const {
    return tempoFine;
}

void Attivita::controllo() const {
    if(tempoInizio.date() != tempoFine.date()){
        throw std::runtime_error("L'orario di inizio/fine deve essere nello stesso giorno di quello di inizio/fine.");
    }
    if (tempoInizio >= tempoFine) {
        throw std::runtime_error("L'orario di fine deve essere successivo all'orario di inizio.");
    }
    if(descrizione.isEmpty()){
        throw std::runtime_error("La descrizione non può essere vuota.");
    }
}

void Attivita::setDescrizione(const QString &descrizione) {
    Attivita::descrizione = descrizione;
}

void Attivita::setTempoInizio(const QTime &tempoInizio) {
    Attivita::tempoInizio.setTime(tempoInizio);
}

void Attivita::setTempoFine(const QTime &tempoFine) {
    Attivita::tempoFine.setTime(tempoFine);
}

bool Attivita::confronto(const Attivita& attivita) const {
    if (tempoInizio == attivita.getTempoInizio() && tempoFine == attivita.getTempoFine() && descrizione == attivita.getDescrizione()) {
        return true;
    }
    return false;
}