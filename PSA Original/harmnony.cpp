#include "Harmony.h"
#include <iostream>
#include <exception>


/* Important Notes
* keys are in multis of 5
* M = minor, m = major
* uppercase key = sharp - A = A#
* lowercase key = natrural - a = A
*/
//create a harmony diatonic object
Harmony_Diatonic H;

//main function -- note other algs will be in separate cpp files
QString HarmonyClass::Harmonise(QList<QString> Struct, int Choice, int NumSections, int Length, QString Key, QString Tone, const int Form, int Form_Mode, const int Quantize)
{
 //will be changed in future versions, default key of c major

    QString Chord = "";

    //manual choice for testing purposes
    //Choice = 2;

    //different harmony modules
    switch(Choice)
    {
    case 1:
        Harmony_Diatonic HD;
        Chord = HD.Harmony_Gen(Key, Tone, Struct, NumSections, Length, Form_Mode);
        break;
    case 2:
        Harmony_Jazz_Class HJ;
        Chord = HJ.Harmony_Gen(Key, Tone, Struct, NumSections, Length);
        break;
    case 3:
        Harmony_Pop HP;
        Chord = HP.Harmony_Gen(Key, Tone, Struct, NumSections, Length, Quantize);
        break;
    default:        
        Chord = H.Harmony_Gen(Key, Tone, Struct, NumSections, Length, Form);
        break;

    }
    return Chord;
}

//other important functions

//translator function

QString HarmonyClass::Chord_Convert(QString Curr_K, QString Chord, int Mode)
{
    //function to convert symbol into text
    //mode select - 1 = ionian,7 = locrian
    //0 = Harmonic minor

    switch(Mode)
    {
    case 0:
        Chord = Minor_Harmonic(Curr_K, Chord);
        break;
    case 1:
        Chord = Mode_Ionian(Curr_K, Chord);
        break;
    case 2:
        Chord = Mode_Dorian(Curr_K, Chord);
        break;
    case 3:
        Chord = Mode_Phrygian(Curr_K, Chord);
        break;
    case 4:
        Chord = Mode_Lydian(Curr_K, Chord);
        break;
    case 5:
        Chord = Mode_Mixolydian(Curr_K, Chord);
        break;
    case 6:
        Chord = Mode_Aolean(Curr_K, Chord);
        break;
    case 7:
        Chord = Mode_Locrian(Curr_K, Chord);
        break;
    default:
        Chord = Mode_Ionian(Curr_K, Chord);
        break;
    }

    return Chord;

}

//mode functions
//natural mode
QString HarmonyClass::Mode_Ionian(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        N += 0;
        Tone = "m";
    }
    else if(Numeral == "II")
    {
        N += 10;
        Tone = "M";
    }
    else if(Numeral == "III")
    {
        N += 20;
        Tone = "M";
    }
    else if(Numeral == "IV")
    {
        N += 25;
        Tone = "m";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "m";
    }
    else if(Numeral == "VI")
    {
        N += 45;
        Tone = "M";
    }
    else if(Numeral == "VII")
    {
        N += 55;
        Tone = "D";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;
}



//dorian mode
QString HarmonyClass::Mode_Dorian(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        Tone = "M";
    }
    else if(Numeral == "II")
    {
        N += 10;
        Tone = "M";
    }
    else if(Numeral == "III")
    {
        N += 15;
        Tone = "m";
    }
    else if(Numeral == "IV")
    {
        N += 25;
        Tone = "m";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "M";
    }
    else if(Numeral == "VI")
    {
        N += 45;
        Tone = "D";
    }
    else if(Numeral == "VII")
    {
        N += 55;
        Tone = "m";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;
}


//
QString HarmonyClass::Mode_Phrygian(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        Tone = "M";
    }
    else if(Numeral == "II")
    {
        N += 5;
        Tone = "m";
    }
    else if(Numeral == "III")
    {
        N += 15;
        Tone = "m";
    }
    else if(Numeral == "IV")
    {
        N += 25;
        Tone = "M";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "D";
    }
    else if(Numeral == "VI")
    {
        N += 45;
        Tone = "m";
    }
    else if(Numeral == "VII")
    {
        N += 55;
        Tone = "M";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;

}



//lydian mode
QString HarmonyClass::Mode_Lydian(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        Tone = "m";
    }
    else if(Numeral == "II")
    {
        N += 10;
        Tone = "M";
    }
    else if(Numeral == "III")
    {
        N += 20;
        Tone = "M";
    }
    else if(Numeral == "IV")
    {
        N += 30;
        Tone = "D";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "m";
    }
    else if(Numeral == "VI")
    {
        N += 45;
        Tone = "M";
    }
    else if(Numeral == "VII")
    {
        N += 55;
        Tone = "M";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;
}


//mixolydian mode
QString HarmonyClass::Mode_Mixolydian(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        Tone = "m";
    }
    else if(Numeral == "II")
    {
        N += 10;
        Tone = "M";
    }
    else if(Numeral == "III")
    {
        N += 20;
        Tone = "D";
    }
    else if(Numeral == "IV")
    {
        N += 25;
        Tone = "m";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "M";
    }
    else if(Numeral == "VI")
    {
        N += 45;
        Tone = "M";
    }
    else if(Numeral == "VII")
    {
        N += 55;
        Tone = "m";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;
}


//aeolean mode
QString HarmonyClass::Mode_Aolean(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        Tone = "M";
    }
    else if(Numeral == "II")
    {
        N += 10;
        Tone = "D";
    }
    else if(Numeral == "III")
    {
        N += 15;
        Tone = "m";
    }
    else if(Numeral == "IV")
    {
        N += 25;
        Tone = "M";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "M";
    }
    else if(Numeral == "VI")
    {
        N += 40;
        Tone = "m";
    }
    else if(Numeral == "VII")
    {
        N += 50;
        Tone = "m";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;
}



//phrygian mode
QString HarmonyClass::Mode_Locrian(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        Tone = "D";
    }
    else if(Numeral == "II")
    {
        N += 5;
        Tone = "m";
    }
    else if(Numeral == "III")
    {
        N += 15;
        Tone = "M";
    }
    else if(Numeral == "IV")
    {
        N += 25;
        Tone = "M";
    }
    else if(Numeral == "V")
    {
        N += 30;
        Tone = "m";
    }
    else if(Numeral == "VI")
    {
        N += 40;
        Tone = "m";
    }
    else if(Numeral == "VII")
    {
        N += 50;
        Tone = "M";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;
}

QString HarmonyClass::Minor_Harmonic(QString Key, QString Numeral)
{
    //declerations
    QString Chord = "";
    QString Note = "";
    QString Tone = "";
    //num assign and keycode objects
    int N = H.NumAssign(Key);
    //5 to 60 - 5 = a, 60 = G - as before caps = sharpened key, minor tonality, D = diminished, A = augmented

    if(Numeral == "I")
    {
        Tone = "M";
    }
    else if(Numeral == "II")
    {
        N += 10;
        Tone = "D";
    }
    else if(Numeral == "III")
    {
        N += 15;
        Tone = "m";
    }
    else if(Numeral == "IV")
    {
        N += 25;
        Tone = "M";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "m";
    }
    else if(Numeral == "VI")
    {
        N += 40;
        Tone = "m";
    }
    else if(Numeral == "VII")
    {
        N += 55;
        Tone = "A";
    }

    Note = H.Keycode(N);
    Chord = Note + Tone;

    return Chord;
}

QList<QString> HarmonyClass::Key_Change_Relative(QString Key, QString Tone)
{
    QList<QString> New_Key;


    int Num = H.NumAssign(Key);

    // now or conditional dependant on Tonality
    if (Tone == "M")
    {
    //relative Major
        Num += 15;
        Tone = H.Tonality(Tone);

    }
    else if(Tone == "m")
    {
        //relative Minor
        Num -= 15;
        Tone = H.Tonality(Tone);
    }

    Key = H.Keycode(Num);

    New_Key << Key<< Tone;

    return New_Key;
}

//dominante key change -- see above for more details
QList<QString> HarmonyClass::Key_Change_Dominant(QString Key, QString Tone)
{
    QList<QString> New_Key;

    int Num = H.NumAssign(Key);
    Num += 35;
    //main conditional
    if(Tone == "M")
    {
        Tone = H.Tonality(Tone);
    }
    else if(Tone == "m")
    {
        Tone = H.Tonality(Tone);
    }

    Key = H.Keycode(Num);

    New_Key << Key<< Tone;

    return New_Key;
}
//subdominant key change
QList<QString> HarmonyClass::Key_Change_SubDominant(QString Key, QString Tone)
{
    QList<QString> New_Key;

    int Num = H.NumAssign(Key);
    Num += 25;
    Key = H.Keycode(Num);

    New_Key << Key<< Tone;

    return New_Key;
}



//semitone up -- for that so clichéd hollywood ending
QList<QString> HarmonyClass::Key_Change_Cheese(QString Key, QString Tone)
{
    QList<QString> New_Key;

    int Num = H.NumAssign(Key);
    Num += 5;
    //no tonality change here!
    Key = H.Keycode(Num);

    New_Key << Key<< Tone;

    return New_Key;
}


