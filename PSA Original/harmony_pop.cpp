#include "Harmony.h"
//main function to choose appropriate chords
QString Harmony_Pop::Chord_Picker(QString Key, QString Tone, const QString Last_Chord)
{
    QString Chord = "";
    //first generate random value
    int Rand = rand() % 28 + 1;

    //chord bias - I V IV VI II VII III
    //first pick a chord at random
    if(Rand <= 3) // I
    {
        Chord = "I";
    }
    else if((Rand > 4) && (Rand  <= 10)) // V
    {
        Chord = "V";
    }
    else if((Rand > 10) && (Rand  <= 17)) // IV
    {
        Chord = "IV";
    }
    else if((Rand > 17) && (Rand  <= 21)) // VI
    {
        Chord = "VI";
    }
    else if((Rand > 21) && (Rand  <= 24)) // II
    {
        Chord = "II";
    }
    else if((Rand > 24) && (Rand  <= 26)) // VII
    {
        Chord = "VII";
    }
    else if(Rand > 26) // III
    {
        Chord = "III";
    }

    //next performmovments off last chord doubles
    if((Last_Chord == "II") && (Chord == "II"))
    {
        Chord = "V";
    }
    else if((Last_Chord == "IV") && (Chord == "IV"))
    {
        Chord = "II";
    }
    else if ((Last_Chord == "V") && (Chord == "V"))
    {
        Chord = "IV";
    }
    else if(Last_Chord == "V")
    {
        Rand = rand() % 8 + 1; // randomise a cadence
        if(Rand <= 4)
        {
            Chord = "I"; //perfect cadence
        }
        else if((Rand > 4) && (Rand <= 7))
        {
            Chord = "VI"; // interrupted cadence
        }
        else
        {
            Chord = "IV"; //imperfect cadence
        }

    }
    else if(Last_Chord == "I") // I - III bias in Major keys
    {
        Rand = rand() % 3 + 1; //33% chance of I - III 33 % chance of I - VI
        if(Rand <= 1)
        {
            Chord = "III";
        }
        else if (Rand == 2)
        {
            Chord = "VI";
        }
    }


    return Chord;
}

int Harmony_Pop::Mode_Select(QString Curr_Tone)
{
    //int declarations
    int mode = 0;
    int Rand = 0;

    if(Curr_Tone == "M")
    {
        Rand = rand() % 8 + 1;
        if(Rand <= 3)
        {
            mode = 0; //harmonic minor
        }
        else if((Rand >3) && (Rand <= 8))
        {
            mode = 6; //aeolian
        }
        else
        {
            mode = 2; //dorian removed by default
        }


    }
    //may later include other major modes
    else if(Curr_Tone == "m")
    {
        Rand = rand() % 8 + 1;

        if(Rand <= 3)
        {
            mode = 4; //Lydian
        }
        else if((Rand >3) && (Rand <= 7))
        {
            mode = 1; //ionian
        }
        else
        {
            mode = 5; //Mixolydian
        }
    }

    return mode;
}

//main pop harmony function
//this function will be focused on phrasing based reppetiton adn a modifiable quantize variable that controlls chord frequency
//1 - bar, 2 - 2bars, 2 - minim, 4 - crotchet
QString Harmony_Pop::Harmony_Gen(const QString Key, const QString Tone, QList<QString> Struct, int NumSections, int Length, const int Quantize)
{
    //object declarations
    QString Output = ""; //output additive string
    QString Chord = ""; // main chord variable
    QString Curr_Key = Key; //create changable key and tonality values for modulation
    QString Curr_Tone = Tone;
    QString Last_Key = ""; //used to keep tract of previous key changes

    //harmony class value
    HarmonyClass H;


    //section length list
    QList<int> Section_Length;
    //obtain section length values
    for(int i = 0; i < NumSections; i++)
    {
        Section_Length.push_back(Struct[i].toInt());
    }

    //integer and counter declarations
    const int Phrasing = 4; //phrase length in bars, default is 4
    //const int Quantize = 1; //controlls chord selection frequency
    int Main_Counter = 0; // main counter for additive arry
    int QCount = 0; //allows for more or less barlines
    float Section_Bar = 0.00; //so we know waht bar of the section we are in
    int Rand = 0; //random variable for later use
    float Phrase_Length = 0.00; //additive phrase length to allow for reppetition
    int Current_Section = 0; // so we know what section it currently is

    int QFloor = 1; //used if quantize is set to 1

    float isQuad = 0.00; //so program knows when a quadbar occurs and can trigger cadences

    int mode; //default ionian mode
    //default mode assign ionian and harmonic minor, dorian or aeolian
    mode = Mode_Select(Tone);

    //changes QFloor to 4 with 1 Quantize
    if(Quantize == 1)
    {
        QFloor = 4;
    }



    //boolean creation

    bool New_Section = false; // to allow for output change on new section
    bool Start_Phrase = false;
    bool First_Bar = true; //to keep track of first bars of piece / section
    bool Final_Section = false; //final section bool


    //additive list for reppetition
    std::vector<std::vector<QString>> Chord_History;
    Chord_History.resize(NumSections);
    //set chord list 2d size
    for(auto &i : Chord_History)
    {
        i.resize(Length * Quantize); //larger size at higher quantize values
    }



    try
    {
        //main function loop
        for(int i = 0; i < Length * Quantize; i++)
        {
            //add our counters
            Section_Bar += (1.00 / Quantize); //in order to account for higher quantize values
            Phrase_Length += (1.00 / Quantize);
            //quadbar calculations
            isQuad += (1.00 / Quantize);
            Main_Counter += 1; //always adds 1 as stores all chords regardless of quantize is reset at the end of each section
            //quatize counter calculations
            QCount += (4 / Quantize);


            //conditional is written so that chords may be assigned multiple times, but will be overwritten by a better value!
            //main generations for non quadbars this will be triggered for EVERY chord, and may be overwritten

            if (isQuad <= 3)
            {



                if(floor(Section_Bar / QFloor) != Section_Bar)
                {


                    //to prevent from running on first bar
                    if(!First_Bar)
                    {
                        Chord = Chord_Picker(Key, Tone, Chord_History[Current_Section][Main_Counter - (1 * Quantize)]);


                    }
                    else if(First_Bar)
                    {
                        Chord = "I"; // always I for now, will be changed later

                        First_Bar = false;
                    }
                }
                else
                {

                    Rand = rand() % 4 + 1; //will be linked to a variable later
                    if(Rand <=3)
                    {
                        Chord = Chord_History[Current_Section][Main_Counter -(1 * Quantize)];//chord is last chord

                    }
                    else
                    {
                        //picks new chord on weak beats
                        Chord = Chord_Picker(Key, Tone, Chord_History[Current_Section][Main_Counter - (1 * Quantize)]);
                    }



                }


            }
            //quadbar calculations
            else if ((isQuad > 3) && (isQuad <4))
            {

                //Chord = "V";
                Chord = Chord_Picker(Key, Tone, Chord_History[Current_Section][Main_Counter - (1 * Quantize)]);
            }
            else if(isQuad >=4)
            {
                //end of phrase always V or I

                Chord = Chord_History[Current_Section][Main_Counter - (1 * Quantize)]; //find out last chord
                if((Chord == "VI") || (Chord == "IV")) //nicer sounding to V than to I
                {
                    Chord = "V";
                }
                else
                {
                    Chord = "I";
                }




                isQuad = 0;
            }
            //second conditional - may be altered for form considerations
            //if phrase is complete and section is incomplete

            if((Phrase_Length == Phrasing ) && (Section_Bar != Section_Length[Current_Section]))
            {
                Start_Phrase = true; //trigger new phrase in section

            }
            else if((Start_Phrase) && (Section_Bar != Section_Length[Current_Section]))
            {
                if(Final_Section)
                {
                    Current_Section = 0; //resets the section to 0
                }
                //potential variations on weak beats slim chance on strong beats
                if(floor(Section_Bar) != Section_Bar)
                {

                    Rand = rand() % 8 + 1;
                    if(Rand <=7)
                    {
                        Chord = Chord_History[Current_Section][Main_Counter - 1 - (Phrasing * Quantize)]; // same chord from phrase
                    }
                    else //1/8th chance of new chord
                    {
                        Chord = Chord_Picker(Key, Tone, Chord_History[Current_Section][Main_Counter - 2]);
                    }
                }
                else
                {
                    Rand = rand() % 5 + 1;
                    if(Rand <= 2) //  chance variation -- may be increasable in future
                    {
                        Chord = Chord_Picker(Key, Tone, Chord_History[Current_Section][Main_Counter - 2]);
                    }
                    else
                    {
                        Chord = Chord_History[Current_Section][Main_Counter - 1 - (Phrasing * Quantize)]; // same chord from phrase
                    }
                }
                if(Final_Section)
                {
                    Current_Section = NumSections - 1; //resets the section to correct value
                }
            }
            //new section --- not final section --- triggers key changes

            else if((Section_Bar == Section_Length[Current_Section]) && (Current_Section != NumSections - 2))
            {
                //chord change funation
                Rand = rand()% 10 + 1;
                if(Rand <= 5) //60% chance of relative
                {
                    Curr_Key = H.Key_Change_Relative(Curr_Key, Curr_Tone)[0];
                    Curr_Tone = H.Key_Change_Relative(Curr_Key, Curr_Tone)[1];
                }
                else if((Rand >5) && (Rand <= 8))
                {
                    Curr_Key = H.Key_Change_Dominant(Curr_Key, Curr_Tone)[0];
                    Curr_Tone = H.Key_Change_Dominant(Curr_Key, Curr_Tone)[1];
                }
                else if((Rand > 8) && (Rand <= 10))
                {
                    Curr_Key = H.Key_Change_SubDominant(Curr_Key, Curr_Tone)[0];
                    Curr_Tone = H.Key_Change_SubDominant(Curr_Key, Curr_Tone)[1];
                }

                //to change mode accordingly
                mode = Mode_Select(Curr_Tone);


                New_Section = true;

            }
            //new section AND final section -- reverts to home key and possible section replication
            else if((Section_Bar == Section_Length[Current_Section]) && (Current_Section == NumSections - 2))
            {
                New_Section = true;
                Final_Section = true; //inform the program that last section is active so can potentially repeat parts of section  1
                Start_Phrase = true; //triggers reppetition of first phrase

                //resets to home key
                Rand = rand()% 10 + 1;
                if(Rand <=7) //70 % chance of home key -- may be user adjustable
                {
                    Curr_Key = Key;
                    Curr_Tone = Tone;
                }
                else if(Rand >7)// 30 % chance of cheesy semitone change!
                {
                    Curr_Key = H.Key_Change_Cheese(Key, Tone)[0];
                    Curr_Tone = Tone;
                }

            }
            //makes last chord of piece ALWAYS I or V
            else if((Section_Bar == Section_Length[Current_Section] - 1) && (Current_Section == NumSections - 1))
            {
                Chord = "I";

            }







            Chord_History[Current_Section][Main_Counter - 1] = Chord;
            //translate chord
            //modes 1 ionian, 2 dorian etc...

            Chord = H.Chord_Convert(Curr_Key, Chord, mode);



            //quatize output
            if(QCount == 4)
            {
                //add to our output string
                Output += Chord + " || ";


                QCount = 0; //intialise QCount
            }
            //only print chord, no new bar
            else
            {
                Output += Chord + " : ";
            }

            //add new line to new section and reset section based counters

            if(New_Section)
            {
                Output += "\n";
                Section_Bar = 0;
                Main_Counter = 0;
                Current_Section += 1;
                New_Section = false;
                First_Bar = true;
                Start_Phrase = false; //starts a new phrase on new section
            }
        }

    }
    //exception handler
    catch(std::exception& e)
    {
        return e.what();
    }








    return Output;
}
