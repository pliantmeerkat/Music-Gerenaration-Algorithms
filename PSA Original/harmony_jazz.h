#ifndef HARMONY_JAZZ_H
#define HARMONY_JAZZ_H

#include <QString>
#include <ctime>
#include <QList>
#include "stdafx.h"

class Harmony_Jazz_Class
{
public:

    QString Harmony_Gen(QString Key, QString Tone, QList<QString> Struct, int NumSections, int Length);

private:

    QList<QString> Chord_List_STD(QString Key, QString Tone, QList<QString> Struct, int NumSections, int Length);
    int Mode_Selection(QString Curr_Tone);

    //pick chords
    QList <QString> Chord_Select(QString Last_Chord, QString Key, QString Tone);


    //translator function


    //key changes

    QList <QString> Key_Change (QString Key, QString Tone, int Choice);


};

#endif // HARMONY_JAZZ_H
