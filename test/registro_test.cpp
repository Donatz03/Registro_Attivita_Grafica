//
// Created by Mattia Donadoni on 01/09/23.
//
#include "gtest/gtest.h"
#include "../Registro.h"

class RegistroTest : public ::testing::Test {

protected:
    Registro registro;

};

TEST_F(RegistroTest, TestAggiungiAttivita) {
Attivita attivita(QString("Calcio"), QDateTime(QDate(2023, 8, 29), QTime(10, 0)), QDateTime(QDate(2023, 8, 29), QTime(11, 0)));
registro.aggiungiAttivita(attivita);
std::vector<Attivita> attivitaGiornaliere = registro.getAttivitaPerGiorno(QDate(2023, 8, 29));
ASSERT_EQ(attivitaGiornaliere.size(), 1);
ASSERT_EQ(attivitaGiornaliere[0].getDescrizione(), QString("Calcio"));
ASSERT_EQ(attivitaGiornaliere[0].getTempoInizio(), QDateTime(QDate(2023, 8, 29), QTime(10, 0)));
ASSERT_EQ(attivitaGiornaliere[0].getTempoFine(), QDateTime(QDate(2023, 8, 29), QTime(11, 0)));
}

TEST_F(RegistroTest, TestAggiungiAttivitaConStessoOrario) {
Attivita attivita1(QString("Calcio"), QDateTime(QDate(2023, 8, 29), QTime(10, 0)), QDateTime(QDate(2023, 8, 29), QTime(11, 0)));
Attivita attivita2(QString("Pallavolo"), QDateTime(QDate(2023, 8, 29), QTime(10, 0)), QDateTime(QDate(2023, 8, 29), QTime(11, 0)));
registro.aggiungiAttivita(attivita1);
registro.esisteAttivitaSovrapposta(attivita2.getTempoInizio(), attivita2.getTempoFine());
ASSERT_EQ(registro.esisteAttivitaSovrapposta(attivita2.getTempoInizio(), attivita2.getTempoFine()), true);
}