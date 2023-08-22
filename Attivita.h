//
// Created by Mattia Donadoni on 22/08/23.
//

#ifndef REGISTRO_ATTIVITA_GRAFICA_ATTIVITA_H
#define REGISTRO_ATTIVITA_GRAFICA_ATTIVITA_H

#include <QString>
#include <QDateTime>
#include <stdexcept>

class Attivita {
public:
    Attivita(const QString& descrizione, const QDateTime& inizio, const QDateTime& fine);
    QString getDescrizione() const;
    QDateTime getTempoInizio() const;
    QDateTime getTempoFine() const;
    void controllo() const;

private:
    QString descrizione;
    QDateTime tempoInizio;
    QDateTime tempoFine;
};

#endif //REGISTRO_ATTIVITA_GRAFICA_ATTIVITA_H