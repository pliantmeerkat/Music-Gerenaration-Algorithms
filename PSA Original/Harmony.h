#pragma once

#ifndef HARMONY_H
#define HARMONY_H

#include "stdafx.h"


//this is the parent file for all harmony functions
class HarmonyClass
{
public:

    QString Harmonise(QList<QString> Struct, int Choice, int NumSections, int Length, QString Key, QString Tone, const int Form, int Form_Mode, const int Quantzie);
    //key functions


    QString Chord_Convert(QString Key, QString Chord, int Mode);

    //modes
    QString Mode_Ionian(QString Key, QString Numeral);
    QString Mode_Dorian(QString Key, QString Numeral);
    QString Mode_Phrygian(QString Key, QString Numeral);
    QString Mode_Lydian(QString Key, QString Numeral);
    QString Mode_Mixolydian(QString Key, QString Numeral);
    QString Mode_Aolean(QString Key, QString Numeral);
    QString Mode_Locrian(QString Key, QString Numeral);

    //harmonic mionor
    QString Minor_Harmonic(QString Key, QString Numeral);

    //key changes
    QList<QString> Key_Change_Relative(QString Key, QString Tone);
    QList<QString> Key_Change_Dominant(QString Key, QString Tone);
    QList<QString> Key_Change_SubDominant(QString Key, QString Tone);
    QList<QString> Key_Change_Cheese(QString Key, QString Tone);


};





#endif // !HARMONY.H
