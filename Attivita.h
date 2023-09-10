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

    void setDescrizione(const QString &descrizione);
    void setTempoInizio(const QTime &tempoInizio);
    void setTempoFine(const QTime &tempoFine);

    bool confronto(const Attivita& attivita) const;

private:
    QString descrizione;
    QDateTime tempoInizio;
    QDateTime tempoFine;

    void controllo() const;
};

#endif //REGISTRO_ATTIVITA_GRAFICA_ATTIVITA_H
