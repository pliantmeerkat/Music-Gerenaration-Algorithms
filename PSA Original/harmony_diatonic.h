#ifndef HARMONY_DIATONIC_H
#define HARMONY_DIATONIC_H

#include <QString>
#include <ctime>
#include <QList>
#include "stdafx.h"




//diatonic harmony alg
class Harmony_Diatonic
{
public:

    QString Keycode(int Num);

    int NumAssign(QString Key);

    QString Tonality(QString Tone);

    QString Harmony_Gen(const QString Key, const QString Tone, QList<QString> Struct, int NumSections, int Length, const int Form);
    QString test();


private:
    //our chord and key change functions
    QString Chord_1(QString Key, QString Tone);
    QString Chord_2(QString Key, QString Tone);
    QString Chord_3(QString Key, QString Tone);
    QString Chord_4(QString Key, QString Tone);
    QString Chord_5(QString Key, QString Tone);
    QString Chord_6(QString Key, QString Tone);
    QString Chord_7(QString Key, QString Tone);



    //cadences
    QString Cadence_Perfect(QString Key, QString Tone);

    QString Cadence_Plagal(QString Key, QString Tone);

    QString Cadence_Imperfect(QString Key, QString Tone);

    QString Cadence_Interrupted(QString Key, QString Tone);

    //our different harmony sub-algs

    QString Harmon_A_Major_Alg(QString Key, QString Tone);

    QString Harmon_A_Minor_Alg(QString Key, QString Tone);

    QList <QString> Harmon_A_Cycle_Fifths(QString Key, QString Tone);

    QList <QString> Sections_Modifiers(QString Curr_Key, QString Curr_Tone);

    //reppetition functions
    QString Reppetition(QString Key, QString Tone, int Bars, QList<QString> Music);


};

#endif // HARMONY_DIATONIC_H
