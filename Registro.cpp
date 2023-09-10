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

bool Registro::rimuoviAttivita(const QDate& data, const QString& descrizione, const QTime& inizio, const QTime& fine) {
    for (int i = 0; i < attivita.size(); i++) {
        if (attivita[i].getTempoInizio().date() == data && attivita[i].getDescrizione() == descrizione && attivita[i].getTempoInizio().time() == inizio && attivita[i].getTempoFine().time() == fine) {
            attivita.erase(attivita.begin() + i);
            return true;
        }
    }
    return false;
}

bool Registro::ricercaAttivitaNomeGionaliera(const QDate& data, const QString& descrizione) const {
    int count = 0;
    int tempoTotale = 0;
    bool trovata = false;
    QString dataString = data.toString("dd/MM/yyyy");
    for (const Attivita& attivita : attivita) {
        if (attivita.getTempoInizio().date() == data && attivita.getDescrizione() == descrizione) {
            count++;
            tempoTotale += attivita.getTempoInizio().secsTo(attivita.getTempoFine());
            trovata = true;
        }
    }
    tempoTotale = tempoTotale / 60;
    if(trovata)
        std::cout << "Il numero di attività: " << descrizione.toStdString() << " e' " << count << ". Il tempo totale passato a svolgere questa attivita' e': " << tempoTotale << " minuti." << std::endl;
    else
        std::cout << "Non ci sono attività con questa descrizione in questa data." << std::endl;
    return trovata;
}

bool Registro::modificareAttivita(const QDate& data, const QString& descrizione, const QTime& inizio, const QTime& fine, const QString& nuovaDescrizione, const QTime& nuovoInizio, const QTime& nuovoFine) {
    for (int i = 0; i < attivita.size(); i++) {
        if (attivita[i].getTempoInizio().date() == data && attivita[i].getDescrizione() == descrizione && attivita[i].getTempoInizio().time() == inizio && attivita[i].getTempoFine().time() == fine) {

            if (nuovoInizio >= nuovoFine) {
                std::cout << "L'orario di fine deve essere successivo all'orario di inizio." << std::endl;
                break;
            }
            if(nuovaDescrizione.isEmpty()){
                std::cout << "La descrizione non può essere vuota." << std::endl;
                break;
            }
            if(esisteAttivitaSovrapposta(QDateTime(data, nuovoInizio), QDateTime(data, nuovoFine), attivita[i])){
                std::cout << "C'è già un'attività che si sovrappone in questo intervallo di tempo." << std::endl;
                break;
            }

            attivita[i].setDescrizione(nuovaDescrizione);
            attivita[i].setTempoInizio(nuovoInizio);
            attivita[i].setTempoFine(nuovoFine);

            return true;
        }
    }
    return false;
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

bool Registro::esisteAttivitaSovrapposta(const QDateTime& inizio, const QDateTime& fine, const Attivita& attivitaDaEscludere) const {
    for (const Attivita& attivita : attivita) {
        if (attivita.getTempoInizio() >= inizio && attivita.getTempoInizio() < fine && !attivita.confronto(attivitaDaEscludere)) {
            return true;
        }
        if (attivita.getTempoFine() > inizio && attivita.getTempoFine() <= fine && !attivita.confronto(attivitaDaEscludere)) {
            return true;
        }
        if (attivita.getTempoInizio() <= inizio && attivita.getTempoFine() >= fine && !attivita.confronto(attivitaDaEscludere)) {
            return true;
        }
    }

    return false;
}