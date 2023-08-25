//
// Created by Mattia Donadoni on 25/08/23.
//

#ifndef REGISTRO_ATTIVITA_GRAFICA_INTERFACCIAQT_H
#define REGISTRO_ATTIVITA_GRAFICA_INTERFACCIAQT_H


#include <QWidget>
#include <QDateEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QDialog>
#include "Registro.h"

class InterfacciaQt : public QWidget {
Q_OBJECT

public:
    InterfacciaQt(QWidget* parent = nullptr);

private slots:
    void aggiungiAttivita();
    void stampaAttivitaGiornaliera();

private:
    Registro registro;
    QDateEdit* dateEdit;
    QListWidget* attivitaListWidget;
    QPushButton* aggiungiButton;
    QPushButton* stampaButton;
};


#endif //REGISTRO_ATTIVITA_GRAFICA_INTERFACCIAQT_H
