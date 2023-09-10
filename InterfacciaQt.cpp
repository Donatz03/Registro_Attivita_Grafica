//
// Created by Mattia Donadoni on 25/08/23.
//

#include "InterfacciaQt.h"

InterfacciaQt::InterfacciaQt(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout;

    dateEdit = new QDateEdit(QDate::currentDate());
    layout->addWidget(dateEdit);

    aggiungiButton = new QPushButton("Aggiungi Attività");
    stampaButton = new QPushButton("Stampa Attività");

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(aggiungiButton);
    buttonLayout->addWidget(stampaButton);
    layout->addLayout(buttonLayout);

    attivitaListWidget = new QListWidget;
    layout->addWidget(attivitaListWidget);

    connect(aggiungiButton, &QPushButton::clicked, this, &InterfacciaQt::aggiungiAttivita);
    connect(stampaButton, &QPushButton::clicked, this, &InterfacciaQt::stampaAttivitaGiornaliera);

    setLayout(layout);
}

void InterfacciaQt::aggiungiAttivita() {
    QDialog dialog(this);
    dialog.setWindowTitle("Aggiungi Attività");

    QVBoxLayout layout(&dialog);

    QLabel* descrizioneLabel = new QLabel("Descrizione:");
    QLineEdit* descrizioneEdit = new QLineEdit;
    layout.addWidget(descrizioneLabel);
    layout.addWidget(descrizioneEdit);

    QLabel* inizioLabel = new QLabel("Orario di Inizio:");
    QDateTimeEdit* inizioEdit = new QDateTimeEdit(QDateTime::currentDateTime());
    QTime nuovoOrario;
    nuovoOrario.setHMS(inizioEdit->time().hour(), inizioEdit->time().minute(), 0);
    inizioEdit->setTime(nuovoOrario);
    layout.addWidget(inizioLabel);
    layout.addWidget(inizioEdit);

    QLabel* fineLabel = new QLabel("Orario di Fine:");
    QDateTimeEdit* fineEdit = new QDateTimeEdit(QDateTime::currentDateTime().addSecs(900));
    nuovoOrario.setHMS(fineEdit->time().hour(), fineEdit->time().minute(), 0);
    fineEdit->setTime(nuovoOrario);
    layout.addWidget(fineLabel);
    layout.addWidget(fineEdit);

    QPushButton* confermaButton = new QPushButton("Conferma");
    layout.addWidget(confermaButton);

    connect(confermaButton, &QPushButton::clicked, [&]() {
        QString descrizione = descrizioneEdit->text();
        QDateTime inizio = inizioEdit->dateTime();
        QDateTime fine = fineEdit->dateTime();

        if (registro.esisteAttivitaSovrapposta(inizio, fine)) {
            QMessageBox::warning(this, "Errore", "C'è già un'attività che si sovrappone in questo intervallo di tempo.");
            return;
        }

        try{
            Attivita nuovaAttivita(descrizione, inizio, fine);
            registro.aggiungiAttivita(nuovaAttivita);
            stampaAttivitaGiornaliera();
            dialog.accept();
        } catch (const std::runtime_error& e) {
            QMessageBox::critical(&dialog, "Errore", e.what());
            return;
        }

    });

    dialog.exec();
}

void InterfacciaQt::stampaAttivitaGiornaliera() {
    attivitaListWidget->clear();

    QDate giorno = dateEdit->date();
    std::vector<Attivita> attivitaDelGiorno = registro.getAttivitaPerGiorno(giorno);

    for (const Attivita& attivita : attivitaDelGiorno) {
        QString descrizione = attivita.getDescrizione();
        QDateTime inizio = attivita.getTempoInizio();
        QDateTime fine = attivita.getTempoFine();

        QString testo = QString("%1: dalle %2 alle %3").arg(descrizione.replace(0, 1, descrizione.at(0).toUpper())).arg(inizio.time().toString().left(5)).arg(fine.time().toString().left(5));
        attivitaListWidget->addItem(testo);
    }
}