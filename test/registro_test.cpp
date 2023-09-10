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

TEST_F(RegistroTest, TestRimuoviAttivita) {
    Attivita attivita(QString("Calcio"), QDateTime(QDate(2023, 8, 29), QTime(10, 0)), QDateTime(QDate(2023, 8, 29), QTime(11, 0)));
    registro.aggiungiAttivita(attivita);
    registro.rimuoviAttivita(QDate(2023, 8, 29), QString("Calcio"), QTime(10, 0), QTime(11, 0));
    ASSERT_EQ(registro.getAttivitaPerGiorno(QDate(2023, 8, 29)).size(), 0);
}

TEST_F(RegistroTest, TestRicercaAttivitaNomeGiornaliera) {
    Attivita attivita1(QString("Calcio"), QDateTime(QDate(2023, 8, 29), QTime(10, 0)), QDateTime(QDate(2023, 8, 29), QTime(11, 0)));
    registro.aggiungiAttivita(attivita1);
    ASSERT_TRUE(registro.ricercaAttivitaNomeGionaliera(QDate(2023, 8, 29), QString("Calcio")));
    ASSERT_FALSE(registro.ricercaAttivitaNomeGionaliera(QDate(2023, 8, 29), QString("Pallavolo")));
}

TEST_F(RegistroTest, TestModificareAttivita) {
    Attivita attivita1(QString("Calcio"), QDateTime(QDate(2023, 8, 29), QTime(10, 0)), QDateTime(QDate(2023, 8, 29), QTime(11, 0)));
    Attivita attivita2(QString("Hokey"), QDateTime(QDate(2023, 8, 29), QTime(16, 30)), QDateTime(QDate(2023, 8, 29), QTime(17, 35)));
    registro.aggiungiAttivita(attivita1);
    registro.aggiungiAttivita(attivita2);
    registro.modificareAttivita(QDate(2023, 8, 29), QString("Calcio"), QTime(10, 0), QTime(11, 0), QString("Pallavolo"), QTime(10, 10), QTime(11, 0));
    ASSERT_TRUE(registro.ricercaAttivitaNomeGionaliera(QDate(2023, 8, 29), QString("Pallavolo")));
    ASSERT_FALSE(registro.ricercaAttivitaNomeGionaliera(QDate(2023, 8, 29), QString("Calcio")));
}