#ifndef HARMONY_POP_H
#define HARMONY_POP_H
#include "stdafx.h"




class Harmony_Pop
{
public:

    QString Harmony_Gen(const QString Key, const QString Tone, QList<QString> Struct, int NumSections, int Length, const int Quantize);

protected:
    QString Chord_Picker(QString Key, QString Tone, const QString Last_Chord);
    int Mode_Select(QString Curr_Tone);

};

#endif // HARMONY_POP_H
