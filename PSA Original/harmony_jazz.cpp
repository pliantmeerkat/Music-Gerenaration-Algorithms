#include "Harmony.h"
#include <iostream>
#include <exception>
#include "harmony_jazz.h"

//create a harmony diatonic object for keycode and numassin

HarmonyClass H;


//main jazz harmony function
QString Harmony_Jazz_Class::Harmony_Gen(QString Key, QString Tone, QList<QString> Struct, int NumSections, int Length)
{
    //initialise and declarations
    QString Output = "";
    QList<QString> Chords;
    Chords = Chord_List_STD(Key, Tone, Struct, NumSections, Length);



    //convert out list into a displayable string
    Output = Chords.join(" ");


    return Output;
}

int Harmony_Jazz_Class::Mode_Selection(QString Curr_T)
{
    int Rand = rand()%10 + 1;
    int Mode = 0;
    if(Curr_T == "m")
    {
        if(Rand <= 2)
        {
            //ionian
            Mode = 1;

        }
        else if((Rand >2) && (Rand <= 6))
        {
            //Lydian
            Mode = 4;
        }
        else if((Rand > 6) && (Rand <= 10))
        {
            //mixolydian
            Mode = 5;
        }
        else
        {
            Mode = 1;
        }
    }
    //minor
    else if(Curr_T == "M")
    {
        if(Rand <= 3)
        {
            //dorian
            Mode = 2;

        }
        else if((Rand >3) && (Rand <= 5))
        {
            //Phrygian
            Mode = 3;
        }
        else if((Rand > 5) && (Rand <= 9))
        {
            //Aolean
            Mode = 6;
        }
        else if((Rand > 9) && (Rand <= 10))
        {
            //Locrian
            Mode = 7;
        }

    }
    return Mode;


}

QList <QString> Harmony_Jazz_Class::Chord_Select(QString Last_Chord, QString Key, QString Tone)
{

    QList <QString> Outlist;
    QString Chord = "";
    int Rand = rand() % 30 + 0;

    //cycle of II Vs and triggers modulations by tritone
    if(Rand <= 10)
    {
        if(Last_Chord != "V")
        {
            Chord = "V";
        }
        else
        {
            Chord = "II";
        }
    }
    else
    {


        //select a chord
        if(Rand <= 7)
        {
            Chord = "I";
        }
        else if((Rand >7) && (Rand <= 13))
        {
            Chord = "V";
        }
        else if((Rand > 13) && (Rand <= 18))
        {
            Chord = "II";
        }
        else if((Rand > 18) && (Rand <= 22))
        {
            Chord = "IV";
        }
        else if((Rand > 22) && (Rand <= 25))
        {
            Chord = "VI";
        }
        else if((Rand > 25 ) && (Rand <= 28))
        {
            Chord = "IV";
        }
        else if((Rand > 28) && (Rand <= 30))
        {
            Chord = "III";
        }
        else
        {
            Chord = "I";
        }
    }


    //std::cout<<Chord.toStdString()<<" "<<Last_Chord.toStdString()<<std::endl;

    //prevent repeated chords and triggers modulations
    if(Last_Chord == Chord)
    {
        if(Last_Chord != "II")
        {
            Chord = "II";
        }
        else
        {
            Chord = "V";
        }

    }
    else if(Last_Chord == "II")
    {
        Chord = "V";
    }
    else if(Last_Chord == "V")
    {
        if(Rand <=17)
        {
            Chord = "I";
        }
        else if(Rand > 17)
        {
            Chord = "I";
            //tritone sub modulation
            Key = Key_Change(Key, Tone, Rand / 8)[0];
            Tone = Key_Change(Key, Tone, Rand / 8)[1];


        }
    }


    Outlist<<Chord<<Key<<Tone;
    return Outlist;

}

//main chord list gen
//std jazz mode
QList<QString> Harmony_Jazz_Class::Chord_List_STD(QString Key, QString Tone, QList<QString> Struct, int NumSections, int Length)
{
    //create list and iterator objects for list processing
    QList<QString> Output;
    QList<QString>::iterator IT;
    QList<QString> Sub_Struct;
    //list will be split into indexes based on section - eg Output[1, 3] = section 2 chord 3

    //counters
    int Section = 0;
    int Bar = 0;

    //other variables
    QString Chord = "";
    int Rand = 0;
    QString Sectl;
    int Sect_i;

    //subsection counter and number
    int NumSub = 0;
    int Curr_Sub = 0;
    int Mode = 1; //ionian by default
    //key and tonality values
    QString Curr_K = Key;
    QString Curr_T = Tone;
    QString Last_Chord;
    QString OUT_Chord;

    //booleans
    bool New_Section = false;

    //calculate modes and key changes



    try
    {
        Mode = Mode_Selection(Tone); //assign a mode based on tonlatiy
        //substructure calculations
        for(int i = 0; i< NumSections; i++)
        {
            //obtain our section length
            Sectl = Struct[i];
            Sect_i = Sectl.toInt();
            //assign single substructs for short sections
            if (Sect_i <= 8)
            {
                Sub_Struct.push_back(Sectl);
            }
            //assign two sets of 8 or 4 sets of 4
            else if(Sect_i == 16)
            {
                Rand = rand() % 4 + 1;
                if(Rand <= 3)
                {
                    for(int i = 0; i < 2; i++)
                    {
                        Sub_Struct.push_back("8");
                        NumSub += 1;
                    }
                }
                else
                {
                    for(int i = 0; i < 4; i++)
                    {
                        Sub_Struct.push_back("4");
                        NumSub += 1;
                    }
                }
            }
            else if(Sect_i >= 32)
            {

                for(int i = 0; i< Sect_i;)
                {
                    //assign a value of 4 if no other values are 4
                    if(i >= Sect_i - 4)
                    {
                        Sub_Struct.push_back("4");
                        i += 4;
                    }


                    Rand = rand() % 4 + 1;
                    if(Rand <= 3)
                    {
                        Sub_Struct.push_back("8");
                        i+= 8;
                    }
                    else
                    {
                        Sub_Struct.push_back("4");
                        i += 4;
                    }
                    NumSub += 1;
                }

            }

            //testing output
            //QString Sub_int = " hh";
            //Sub_int = Sub_Struct.join(",");
            //std::cout<<Sub_int.toStdString()<<std::endl; sub struct testing


        }
        //end of substructure
        //main loop
        Section = 0;
        for(int i = 0; i <Length; i++)
        {
            Last_Chord = Chord;

            //to prevent index out of range errors
            if(Section < NumSections)
            {
                Sect_i = Struct[Section].toInt();
            }
            Bar += 1;

            //function to generate random chord
            //default function with no modifiers
            //chords are ranked in order of probablility
            //to assign a chord 1 or v to bar 1
            if(Bar == 1)
            {
                Rand = rand() % 5 + 1;
                if(Rand <= 4)
                {
                    Chord = "I";
                }
                else
                {
                    Chord = "V";
                }
            }

            //substructure calculations
            //pre new sub
            if(Bar == Sub_Struct[Curr_Sub].toInt())
            {
                //chords will be II V I for now
                Chord = "II";
                Chord = H.Chord_Convert(Curr_K, Chord, Mode);
                Output.push_back(Chord);

                Chord = "V";
                Chord = H.Chord_Convert(Curr_K, Chord, Mode);
                Output.push_back(Chord);

                Chord = "I";
                //no output to prevent chord doubline
                //in future will have a conditional to dictate final chords
                //New_Section = true;


            }
            else if(Bar == Sub_Struct[Curr_Sub].toInt() + 1)
            {
                //chord will always be I
                Chord = "I";
                //key change choice
                //key change if required
                Rand = rand()% 4 + 1;

                Mode = Mode_Selection(Tone);

                //trigger new subsection
                Curr_Sub += 1;

            }

            //more conditionals
            else if(Bar != 1)
            {
                Chord = Chord_Select(Last_Chord, Curr_K, Curr_T)[0];
                Curr_K = Chord_Select(Last_Chord, Curr_K, Curr_T)[1];
                Curr_T = Chord_Select(Last_Chord, Curr_K, Curr_T)[2];
                Mode = Mode_Selection(Curr_T);



            }
            if(Bar == Sect_i)
            {
                New_Section = true;
            }


            //last bar of section II V I




            //to filter out repeated chords



            //roman numeral write -- Output.push_back(Chord);
            //this assigns IIs and VI Dim chords either as flat 5, major or minor
            if((Chord != "II") && (Chord != "VI") && (Chord != "V"))
            {
                Chord = H.Chord_Convert(Curr_K, Chord, Mode);
            }
            else
            {
                Chord = H.Chord_Convert(Curr_K, Chord, Mode);
                //retrieve only first char
                for(QChar &c : Chord)
                {
                    Chord = c;
                    break;
                }
                Rand = rand()% 10 + 1;
                {
                    if(Rand <= 4)
                    {
                        Chord += "m";
                    }
                    else if((Rand >4) && (Rand <= 8))
                    {
                        Chord += "M";
                    }
                    else
                    {
                        Chord += "b5";
                    }
                }
            }

            OUT_Chord = Chord + "||";

            if(New_Section)
            {
                OUT_Chord += "\n"; //add new line on new section
                New_Section = false;
                Bar = 0; //reset bar counter
                Section += 1;
                Curr_K = Key_Change(Curr_K, Curr_T, Rand)[0];
                Curr_T = Key_Change(Curr_K, Curr_T, Rand)[1];
                //Curr_Sub += 1;
            }



            Output.push_back(OUT_Chord);
        }
    }


    catch(std::exception& e)
    {
        Output.clear();
        Output.push_back(e.what());
    }




    return Output;
}
//translator function
/*
QString Harmony_Jazz_Class::Chord_Convert(QString Curr_K, QString Chord, int Mode)
{
    //function to convert symbol into text
    //mode select - 1 = ionian,7 = locrian

    switch(Mode)
    {
    //ionian
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
QString Harmony_Jazz_Class::Mode_Ionian(QString Key, QString Numeral)
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
QString Harmony_Jazz_Class::Mode_Dorian(QString Key, QString Numeral)
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
QString Harmony_Jazz_Class::Mode_Phrygian(QString Key, QString Numeral)
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
QString Harmony_Jazz_Class::Mode_Lydian(QString Key, QString Numeral)
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
QString Harmony_Jazz_Class::Mode_Mixolydian(QString Key, QString Numeral)
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
QString Harmony_Jazz_Class::Mode_Aolean(QString Key, QString Numeral)
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
        Tone = "M";
    }
    else if(Numeral == "V")
    {
        N += 35;
        Tone = "M";
    }
    else if(Numeral == "VI")
    {
        N += 45;
        Tone = "m";
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


//phrygian mode
QString Harmony_Jazz_Class::Mode_Locrian(QString Key, QString Numeral)
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
*/
//key Changes
QList <QString> Harmony_Jazz_Class::Key_Change(QString Key, QString Tone, int Choice)
{
    //crete a new key list : index 0 - Key; index 1 - Tone
    QList<QString> New_Key;
    Harmony_Diatonic HD;
    int Num = HD.NumAssign(Key);

    //choice info -- 1 = relative : 2 = dominant : 3 = subdominant : 4 = tritone
    //choice switch
    switch(Choice)
    {
    case 1:
        //relative
        //major
        if(Tone == "m")
        {
            Num -= 15;
            Tone = "M";
        }
        //minor
        else if(Tone == "M")
        {
            Num += 15;
            Tone = "m";
        }
        break;

    case 2:
        //dominant
        Num += 35;
        if(Tone == "M")
        {
            Tone = "m";
        }
        break;

    case 3:
        //subdominant
        Num += 35;
        break;

    case 4:
        //tritone
        Num += 30;
        if(Tone == "M")
        {
            Tone = "m";
        }
        break;

    default:
        break;
    }

    Key = HD.Keycode(Num);

    New_Key.push_back(Key);
    New_Key.push_back(Tone);


    return New_Key;
}

