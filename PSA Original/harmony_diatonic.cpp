#include "Harmony_Diatonic.h"
#include <vector>


//diatonic alg

QString Harmony_Diatonic::Keycode(int Num)
{
QString K = "";

//our inrange function
if (Num <= 4)
{
Num += 60;
}
else if (Num >= 61)
{
Num -= 60;
}
//switch to assign keys to our number..
switch (Num)
{
case 5:
  K = "a";
  break;
case 10:
  K = "A";
  break;
case 15:
  K = "b";
  break;
case 20:
  K = "c";
  break;
case 25:
  K = "C";
  break;
case 30:
  K = "d";
  break;
case 35:
  K = "D";
  break;
case 40:
  K = "e";
  break;
case 45:
  K = "f";
  break;
case 50:
  K = "F";
  break;
case 55:
  K = "g";
  break;
case 60:
  K = "G";
  break;
default:
  break;

}
return K;
}

int Harmony_Diatonic::NumAssign(QString Key)
{
int Num = 0;

if(Key == "a")
{
Num = 5;
}
else if(Key == "A")
{
Num = 10;
}
else if(Key == "b")
{
Num = 15;
}
else if(Key == "c")
{
Num = 20;
}
else if(Key == "C")
{
Num = 25;
}
else if(Key == "d")
{
Num = 30;
}
else if(Key == "D")
{
Num = 35;
}
else if(Key == "e")
{
Num = 40;
}
else if(Key == "f")
{
Num = 45;
}
else if(Key == "F")
{
Num = 50;
}
else if(Key == "g")
{
Num = 55;
}
else if(Key == "G")
{
Num = 60;
}
return Num;
}

QString Harmony_Diatonic::Tonality(QString Tone)
{
if(Tone == "M")
{
Tone = "m";

}

else if (Tone == "m")
{
Tone = "M";

}
return Tone;



}

//our class assignment




//our initial chords availible

QString Harmony_Diatonic::Chord_1(QString Key, QString Tone)
{
    //chord = input key.
    QString Chord = (Key + Tone);

    return Chord;
}
QString Harmony_Diatonic::Chord_2(QString Key, QString Tone)
{
    QString Chord = "";
    int N = NumAssign(Key);



    //conditionals to split based on tone
    if(Tone == "m")
    {
        N += 10;
        Tone = Tonality(Tone);
    }
    else if(Tone == "M")
    {
        N += 10;
        Tone = "D";

    }
    Key = Keycode(N);
    Chord = (Key +Tone);

    return Chord;
}
QString Harmony_Diatonic::Chord_3(QString Key, QString Tone)
{
    QString Chord = "";
    int N = NumAssign(Key);
    if(Tone == "m")
    {
        N += 20;
        Tone = Tonality(Tone);
    }
    else if(Tone == "M")
    {
        N += 15;
        Tone = Tonality(Tone);
    }


    Key = Keycode(N);
    Chord = (Key +Tone);

    return Chord;
}
QString Harmony_Diatonic::Chord_4(QString Key, QString Tone)
{
    QString Chord = "";
    int N = NumAssign(Key);
    N += 25;
    Key = Keycode(N);
    Chord = (Key +Tone);

    return Chord;
}
QString Harmony_Diatonic::Chord_5(QString Key, QString Tone)
{
    QString Chord = "";
    int N = NumAssign(Key);
    N += 35;
    Key = Keycode(N);
    if(Tone == "M")
    {
        Tone = Tonality(Tone);
    }
    Chord = (Key +Tone);


    return Chord;
}
QString Harmony_Diatonic::Chord_6(QString Key, QString Tone)
{
    QString Chord = "";
    int N = NumAssign(Key);
    Tone = Tonality(Tone);
    if(Tone == "m")
    {

       N += 50;
    }
    else if(Tone == "M")
    {

        N += 45;
    }


    Key = Keycode(N);
    Chord = (Key +Tone);

    return Chord;
}
QString Harmony_Diatonic::Chord_7(QString Key, QString Tone)
{
    QString Chord = "";
    int N = NumAssign(Key);



    if(Tone == "m")
    {
        N += 45;
        Tone = Tone = "D";
    }
    else if(Tone == "M")
    {
        N += 50;
        Tone = Tonality(Tone);
    }

    Key = Keycode(N);
    Chord = (Key +Tone);

    return Chord;
}


//key change functions

//our reppetition function
QString Harmony_Diatonic::Reppetition(QString Key, QString Tone, int Bars, QList<QString> Music)
{
    QString Output = "";



    return Output;
}

//cadences
//will include various versions
QString Harmony_Diatonic::Cadence_Perfect(QString Key, QString Tone)
{
    QString Output = "";
    //object declerations
    QString C_1 = Chord_1(Key, Tone);
    QString C_2 = Chord_2(Key, Tone);
    QString C_3 = Chord_3(Key, Tone);
    QString C_4 = Chord_4(Key, Tone);
    QString C_5 = Chord_5(Key, Tone);
    QString C_6 = Chord_6(Key, Tone);


    //our random object to select our variation
    int Rand = rand() % 7 + 1;

    if(Rand <= 3)
    {
        //variation 1 - 2: 5: 1
        Output = (C_2 + ";" + C_5 + ";" + C_1 + ";");
    }
    else if((Rand >= 4) && (Rand <= 6))
    {
        //variation 2 - 2 - 4: 5: 1
        Output = (C_4 + ";" + C_5 + ";" + C_1 + ";");
    }
    else if(Rand >= 7)
    {
        //variation 3 - 6 : 5 : 1
        Output = (C_6 + ";" + C_5 + ";" + C_1 + ";");
    }

    return Output;
}
QString Harmony_Diatonic::Cadence_Plagal(QString Key, QString Tone)
{
    QString Output = "";
    QString C_1 = Chord_1(Key, Tone);
    QString C_2 = Chord_2(Key, Tone);
    QString C_3 = Chord_3(Key, Tone);
    QString C_4 = Chord_4(Key, Tone);
    QString C_5 = Chord_5(Key, Tone);
    QString C_6 = Chord_6(Key, Tone);



    Output = (C_4 + ";" + C_1 + ";");


    return Output;

}
QString Harmony_Diatonic::Cadence_Imperfect(QString Key, QString Tone)
{
    QString Output = "";
    QString C_1 = Chord_1(Key, Tone);
    QString C_2 = Chord_2(Key, Tone);
    QString C_3 = Chord_3(Key, Tone);
    QString C_4 = Chord_4(Key, Tone);
    QString C_5 = Chord_5(Key, Tone);
    QString C_6 = Chord_6(Key, Tone);



    Output = (C_4 + ";" + C_5 + ";");

    return Output;
}
QString Harmony_Diatonic::Cadence_Interrupted(QString Key, QString Tone)
{
    QString Output = "";
    QString C_1 = Chord_1(Key, Tone);
    QString C_2 = Chord_2(Key, Tone);
    QString C_3 = Chord_3(Key, Tone);
    QString C_4 = Chord_4(Key, Tone);
    QString C_5 = Chord_5(Key, Tone);
    QString C_6 = Chord_6(Key, Tone);



    Output = (C_5 + ";" + C_6 + ";");

    return Output;
}

QString Harmony_Diatonic::Harmon_A_Major_Alg(QString Key, QString Tone)
{
    QString Chord = "";
    QString Output = "";

    //our multiple chord modifier, will later be lined to rhythms generated
    int Repeat_rand = rand() % 9 + 1;
    int Repeats = 0;

    if((Repeat_rand >= 0) && (Repeat_rand <= 4))
    {
        Repeats = 1;
    }
    else if((Repeat_rand >= 5) && (Repeat_rand <= 6))
    {
        Repeats = 2;
    }
    else if((Repeat_rand >= 7) && (Repeat_rand <= 8))
    {
        Repeats = 4;
    }
    else if((Repeat_rand == 9))
    {
        Repeats = 3;
    }


    //loop to generate correct number of chords
    for (int i = 0; i < Repeats; i ++)
    {
        int Rand = rand() % 35 + 1;
        if (Tone == "D")
        {

            Tone = "M";
        }


        //conditionals are ranked in order of probablilty, with highest first


        if ((Rand >= 0) && (Rand <= 8))
        {
            //will later include catch to prevent multiple chords
            Chord = Chord_5(Key, Tone);
            Output +=Chord + ";";
        }
        else if ((Rand >= 9) && (Rand <= 16))
        {
            Chord = Chord_4(Key, Tone);
            Output +=Chord + ";";
        }
        else if ((Rand >= 17) && (Rand <= 22))
        {
            Chord = Chord_1(Key, Tone);
            Output += Chord + ";";
        }
        else if ((Rand >= 23) && (Rand <= 30))
        {
            Chord = Chord_6(Key, Tone);
            Output += Chord + ";";
        }
        else if ((Rand >= 30) && (Rand <= 34))
        {
            Chord = Chord_2(Key, Tone);
            Output += Chord + ";";
        }
        else if ((Rand == 35))
        {
            Chord = Chord_3(Key, Tone);
            Output += Chord + ";";
        }

    }
    Output += ("||");
    return Output;

}

QString Harmony_Diatonic::Harmon_A_Minor_Alg(QString Key, QString Tone)
{
    QString Output = "";


    return Output;
}

//this function will create a cycle of fifths style of harmony -- will likely form the basis of the jazz alg
//still a WIP
QList <QString> Harmony_Diatonic::Harmon_A_Cycle_Fifths(QString Key, QString Tone)
{

    //initialise and define our variables
    QList <QString> Output;
    QString Chords = "";

    int Num = 0;
    float Beat_Count = 0.00;
    QString Note = "";

    //will be between 2 and 8 bars long
    int lengthRand = (rand() % 4 +1) * 2;
    /*this will determine the freqeuncy of our chords
     * eg quaver, crotchet, dotted crotchet, minim*/
    float Length_Multi = rand() % 4 + 1;
    Length_Multi *= 0.5;
    //to assign 1.5 to one per bar and increase probibility
    if(Length_Multi == 1.5)
    {
        Length_Multi = 1;
    }
    //code to set bc to lm due to multiplier bug
    else if (Length_Multi >= 2)
    {
        Beat_Count = Length_Multi;
    }


    QString Total_Legnth = QString::number(lengthRand);

    //for now there will be no change in tonality/key for the chords
    Num = NumAssign(Key);
    for(int i = 0; i<= Length_Multi * lengthRand; i++)
    {
        /*length mods are as follows:
         * 0.5 = minim
         * 1 = one per bar
         * 2 = one per 2 bars
         * */

        Num -= 35;
        //to keep num inrange
        if(Num < 0)
        {
            Num += 60;
        }

        //early length mod conditional, may be changed


        Note = Keycode(Num);
        Note += Tone;





        if(Beat_Count < 1)
        {
            //test code

        }
        if (Beat_Count == 1)
        {
            Chords += "||";
            Beat_Count = 0;
        }
        else if(Beat_Count >= 2)
        {
            Chords += "||" + Note + ";" + "||";


            Beat_Count = 0;
        }

        Chords += Note + ";";

        Beat_Count += Length_Multi;

        std::cout<<Length_Multi<< " "<<Beat_Count<<std::endl;


    }



    Output << Chords<< Total_Legnth;



    return Output;
}

//this function processessection change modifiers
QList <QString> Harmony_Diatonic::Sections_Modifiers(QString Curr_Key, QString Curr_Tone)
{
    HarmonyClass HC; //harmony class object

    QList<QString> Output_List;
    QString Chord = "";


    //random int object
    int Random = rand() % 6 + 1;

    //conditional for key change
    //relative:
    if (Random <= 3)
    {
        //our final chords to end the section
        Chord = Cadence_Perfect(Curr_Key, Curr_Tone) + "||";
        //assignment of new key and tonality
        Curr_Key = HC.Key_Change_Relative(Curr_Key, Curr_Tone)[0];
        Curr_Tone = HC.Key_Change_Relative(Curr_Key, Curr_Tone)[1];
        //std::cout<<Curr_Key.toStdString()<<std::endl;
    }
    else if (Random >= 4 && Random <= 6)
    {
        /*this code will change our final chord if modulating to the dominant
         *first the tonality must be reversed if the tonality is minor
         */
        if (Curr_Tone == "M")
        {
            Curr_Tone = Tonality(Curr_Tone);
        }
        //our final chord - modified if nescesarry
        Chord = Cadence_Perfect(Curr_Key, Curr_Tone) + "||";

        //assignment of new key and tonality
        Curr_Key = HC.Key_Change_Dominant(Curr_Key, Curr_Tone)[0];
        Curr_Tone = HC.Key_Change_Dominant(Curr_Key, Curr_Tone)[1];

    }

    //create our output list -- Key, Tone, Chord
    Output_List.push_back(Curr_Key);
    Output_List.push_back(Curr_Tone);
    Output_List.push_back(Chord);


    return Output_List;



}

//baroque Harmony Function
QString Harmony_Diatonic::Harmony_Gen(const QString Key, const QString Tone, QList<QString> Struct, int NumSections, int Length, const int Form)
{   //definitions
    //create our chord variable

    try{



        int Random = 0;
        QString Curr_Key = Key;

        QString Curr_Tone = Tone;

        QString Chord = "";


        //for final section calculations
        int Bar_Init = 0; //intitalises final bar counter

        //our float divisor variable
        float isQuad = 0.00;
        //code to calculate section
        int Section_Counter = 0;
        //create our bar counter int
        int Bar = 0;
        int Section_Bar = 0;
        //create our output variable
        QString Output = "";
        //int Bar_Increase = 0;
        QList<int> Section_Length;
        for(int i = 0; i < NumSections; i++)
        {
            Section_Length.push_back(Struct[i].toInt());
        }

        //creation and allocation of our 2d array for reppetition
        std::vector<std::vector<QString>> str_vect;
        str_vect.resize(NumSections);
        for(auto &i : str_vect)
        {
            i.resize(Length);
        }

        //Section_Length = new int[NumSections - 1];
        //debug output toffle
        bool Is_Out = false;



        //checks that our sectionlength pointer is suitible
        /*
        if ((Section_Length == nullptr) || (Section_List == nullptr))
        {
            throw std::exception("Memmory Allocation Failiure, please restart program");
        }*/




        //our early use loop
        //conditional for Major tonality
        for(int i = 0; i<(Length); i++)
        {

            //initialise our string vect variable


            //code to obtain our new section modifier
            Bar += 1;
            Section_Bar += 1;

            isQuad = (Bar/ 4.00);
            //reppetition in final section


            //this code sets the chords to exactly match the first on certain uses and manages reppetition
            //to filter out tew few sections

            //main generation for non quadbars
            if ((floor(floor(isQuad) != isQuad)))
            {
                //code to ensure that first chord is tonic chord -- may be updated earlier
                if (Bar == 1)
                {
                    Chord = Chord_1(Curr_Key, Curr_Tone) + "||";
                }
                //main alg for chord generation
                else
                {

                    Chord = Harmon_A_Major_Alg(Curr_Key, Curr_Tone);


                }


            }
            //this marks the end of 4 bar patterns, with a cadence and bar ending symbol
            //will not run when in penultiamte bar of section, which will ALWAYS be perfect
            else if ((isQuad == isQuad) && (Section_Bar != Section_Length[Section_Counter]))
            {

                Random = rand() % 9 + 1;

                if (Random <= 3)
                {
                    Chord = Cadence_Perfect(Curr_Key, Curr_Tone) + "||";

                }
                else if((Random >= 4) && (Random <= 5))
                {
                    Chord = Cadence_Interrupted(Curr_Key, Curr_Tone) + "||";


                }
                else if(Random >= 6 && Random <= 7)
                {
                    Chord = Cadence_Imperfect(Curr_Key, Curr_Tone) + "||";

                }
                else if (Random >= 8 && Random <= 9)
                {

                    Chord = Cadence_Plagal(Curr_Key, Curr_Tone) + "||";

                }


            }
             str_vect[Section_Counter ][Section_Bar - 1] = Chord;


             //form dependant generation

             //rondo form removed for now
             if(Form == 0)
             {

             }
             //pop
             else if(Form == 3)
             {

             }
             //jazz
             else if(Form == 4)
             {

             }
             //diatonic
             else
             {

                 //final section code
                 if ((Section_Counter >= NumSections - 1))
                 {


                     //reppetition only on longer works
                     if(NumSections > 2)
                     {

                         Curr_Key = Key;
                         Curr_Tone = Tone;

                         //generate rand value
                         int Rand = 2;//rand() % 6 + 1;






                         //only final 4 bars repeated

                         if(Rand <= 2)
                         {
                             //to ensure that only the last 4 bars are repeated
                             if(Section_Bar >= Section_Length[Section_Counter] - 3)
                             {


                                 Chord = (str_vect[0][Bar_Init]);
                                 str_vect[Section_Counter ][Section_Bar - 1] = Chord;

                                 Bar_Init += 1;

                             }


                         }
                         //final 2 bar or 8 bar reppetition dependant on size
                         else if(Rand == 3)
                         {
                             //to check that sections are appropriate lengths
                             if((Section_Length[0] >= 8) && (Section_Length[Section_Counter] >= 8))
                             {


                                 if(Section_Bar >= Section_Length[Section_Counter] - 7)
                                 {
                                     Chord = (str_vect[0][Section_Length[0] + (Bar_Init - 8)]);
                                     str_vect[Section_Counter ][Section_Bar - 1] = Chord;

                                     Bar_Init += 1;

                                 }

                             }
                             else
                             {

                                 if(Section_Length[0] >= Section_Length[Section_Counter])
                                 {
                                     throw std::exception("E201 - too long first section");
                                 }

                                 else if((Section_Bar >= Section_Length[Section_Counter] - 1) && (Section_Length[0] < Section_Length[Section_Counter]))
                                 {

                                     Chord = (str_vect[0][Section_Length[0] - (Bar_Init - 1)]);
                                     str_vect[Section_Counter ][Section_Bar - 1] = Chord;

                                     Bar_Init -= 1;


                                 }



                             }

                         }
                         //first 2 or 4 bars repeated
                         else if(Rand == 4)
                         {

                             //first 4 bars repeated
                             if((Section_Length[Section_Counter] > 8) && (Section_Bar <= 4))
                             {


                                 Chord = (str_vect[0][Bar_Init]);
                                 str_vect[Section_Counter ][Section_Bar - 1] = Chord;

                                 Bar_Init += 1;
                             }
                             //first 2 bars repeated
                             else if((Section_Length[Section_Counter] <= 8) && (Section_Bar <= 2))
                             {


                                 Chord = (str_vect[0][Bar_Init]);
                                 str_vect[Section_Counter ][Section_Bar - 1] = Chord;

                                 Bar_Init += 1;

                             }


                         }
                         //complete section replication
                         else if(Rand >= 5)
                         {
                             //start counting again if section 1 < final section
                             if(Bar_Init >= Section_Length[0])
                             {
                                 Bar_Init = 0;
                             }

                            Chord = (str_vect[0][Bar_Init]);

                            str_vect[Section_Counter ][Section_Bar - 1] = Chord;


                            Bar_Init += 1;


                         }
                         else
                         {
                             throw std::invalid_argument("ER01 Repp rand value out of range");
                         }


                        str_vect[Section_Counter ][Section_Bar - 1] = Chord;





                     }
                     if ((Section_Bar == Section_Length[Section_Counter]) && (Section_Counter == NumSections - 1))
                     {
                        Chord = Cadence_Perfect(Key, Tone);
                        str_vect[Section_Counter ][Section_Bar - 1] = Chord;
                        Section_Counter += 1;
                        Section_Bar = 0;
                     }

                     //add to our output string

                     Output += (" " + Chord);

                     Is_Out = true;


                 }



                //our code for key modulations and section modifiers for all but last section

                else if ((Section_Bar == Section_Length[Section_Counter]) && (Section_Counter < NumSections - 1))
                {
                    //access values from section modifiers function
                    Curr_Key = Sections_Modifiers(Curr_Key, Curr_Tone)[0];
                    Curr_Tone = Sections_Modifiers(Curr_Key, Curr_Tone)[1];
                    Chord = Sections_Modifiers(Curr_Key, Curr_Tone)[2];

                    //code to write end of section symbol
                    Output += (" " + Chord + " \n");
                    //reppetition code
                    str_vect[Section_Counter ][Bar - 1] = Chord;
                    Is_Out = true;

                    //code to initialise / modify our counters
                     str_vect[Section_Counter ][Section_Bar - 1] = Chord;
                    Section_Counter += 1;
                    Section_Bar = 0;
                }
             }


        //our additive output code
            if(Is_Out == false)
            {
                Output += (" " + Chord + " ");
                //std::cout<<str_vect[Section_Counter ][Section_Bar-1].toStdString()<<std::endl;

            }
            else if(Is_Out == true)
            {
                //std::cout<<"false"<<std::endl;
                Is_Out = false;
            }

    }








        return Output;
    }
    //exception handler
    catch(std::exception& e)
    {
        return e.what();
    }
}


