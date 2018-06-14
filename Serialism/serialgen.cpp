#include "serialgen.h"
#include <iostream>
SerialGen::SerialGen()
{

}

void SerialGen::RandomReset()
{
    srand(time(0));
}

//code to randomly generate a number, then convert it to multiples of 5 that can be read by keycode
int SerialGen::NumGen(int R)
{


    switch(R)
    {
        case 1:
            return 5;
            break;
        case 2:
            return 10;
            break;
        case 3:
            return 15;
            break;
        case 4:
            return 20;
            break;
        case 5:
            return 25;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 35;
            break;
        case 8:
            return 40;
            break;
        case 9:
            return 45;
            break;
        case 10:
            return 50;
            break;
        case 11:
            return 55;
            break;
        case 12:
            return 60;
            break;
        default:
            return 0;
            break;
    }

}

// function to check whether out numbers fit within oour range
int SerialGen::InRange(int N)
{
    if (N <5)
    {
        N += 55;
    }
    else if (N > 60)
    {
        N -=60;
    }
    else
    {
        N = N;
    }
    return N;
}

//function to assign numbers to our keys
int SerialGen::NumAssin(QString Key)
{

    if(Key == "A")
    {
        return 5;
    }

    else if(Key == "A#")
    {
        return 10;
    }

    else if(Key == "B")
    {
        return 15;
    }

    else if(Key == "C")
    {
        return 20;
    }

    else if(Key == "C#")
    {
        return 25;
    }

    else if(Key == "D")
    {
        return 30;
    }

    else if(Key == "D#")
    {
        return 35;
    }

    else if(Key == "E")
    {
        return 40;
    }

    else if(Key == "F")
    {
        return 45;
    }

    else if(Key == "F#")
    {
        return 50;
    }

    else if(Key == "G")
    {
        return 55;
    }

    else if(Key == "G#")
    {
        return 60;
    }
    else
    {
        return 0;
    }


}


//converts numbers to different keys
QString SerialGen::KeyCode(int Num)
{
    QString SNum = QString::number(Num);

    switch(Num)
    {
    case 5:
        return "A";
        break;
    case 10:
        return "A#";
        break;
    case 15:
        return "B";
        break;
    case 20:
        return "C";
        break;
    case 25:
        return "C#";
        break;
    case 30:
        return "D";
        break;
    case 35:
        return "D#";
        break;
    case 40:
        return "E";
        break;
    case 45:
        return "F";
        break;
    case 50:
        return "F#";
        break;
    case 55:
        return "G";
        break;
    case 60:
        return "G#";
        break;
    default:
        return "error";
        break;
    }



    return "";
}

//function for generating random rows
QString SerialGen::Rowify(QString Key)
{
    int Tone_R = 0;

    int counter = 0;

    QString Row = "";
    QString Total = "";

    //create booleans for each value
    bool one = true;
    bool five = true;
    bool two = true;
    bool three = true;
    bool four = true;
    bool six = true;
    bool seven = true;
    bool eight = true;
    bool nine = true;
    bool ten = true;
    bool eleven = true;
    bool twelve = true;

    //for(int i = 0; i <30; i++)
    while(counter < 12)
    {
        // using two to increase number diversity
        Tone_R = (rand() % 12) + 1 ;


        //code to only add each int once
        switch(Tone_R)
        {
            case 1:
                if ( one != true)
                {
                    Total = "";
                }
                else
                {

                    Total = QString::number(Tone_R);


                    Row = (Row + ":" + Total);
                    one = false;
                    counter += 1;

                }
                break;
            case 2:
                if ( two != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    two = false;
                    counter += 1;

                }
                break;
            case 3:
                if ( three != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    three = false;
                    counter += 1;

                }
                break;
            case 4:
                if ( four != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    four = false;
                    counter += 1;

                }
                break;
            case 5:
                if ( five != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    five = false;
                    counter += 1;

                }
                break;
            case 6:

                if ( six != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);

                    six = false;
                    counter += 1;

                }
                break;

            case 7:

                if ( seven != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    seven = false;
                    counter += 1;

                }
                break;

            case 8:

                if ( eight != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    eight = false;
                    counter += 1;

                }
                break;

            case 9:

                if ( nine != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    nine = false;
                    counter += 1;

                }
                break;

            case 10:

                if ( ten != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    ten = false;
                    counter += 1;

                }
                break;

            case 11:

                if ( eleven != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    eleven = false;
                    counter += 1;

                }
                break;

            case 12:

                if ( twelve != true)
                {
                    Total = "";
                }
                else
                {
                    Total = QString::number(Tone_R);
                    Row = (Row + ":" + Total);
                    twelve = false;
                    counter += 1;

                }
                break;

            default:
                break;
        }




        if (counter >= 12)
        {
            Row = (Row + ":");
            break;
        }
    }


    return Row;
}

//generate our random key
const QString SerialGen::KeyGen(int Rand)
{
    //parent function to generate random key
    int Start = 0;
    QString Note = "";

    Start = SerialGen::NumGen(Rand);
    Note = SerialGen::KeyCode(Start);

    return Note;
}

//main class function
const QString SerialGen::Generate(QString Note)
{
    //initialising our variables

    //int Number = 0;

    QString T_Row = "";
    QString N_Row = "";
    QString N_Total = "";
    QString T_Total = "";


    //QString Check = QString::number(Rand);

    T_Row = SerialGen::Rowify(Note);


    T_Total = (Note + "\n " + T_Row);
    return T_Total;

}
const QString SerialGen::Noteify(QString Row, QString Note)
{
    //function to turn our number based row into letters!
    int Multi = (NumAssin(Note) / 5);
    int Note_Int = 0;
    QString Read = "";
    QString Tone_Row = "";
    QString Calc_Note = "";
    QString Read_Note = "";
    QString Output = "";

    std::string Note_Test = "";

    bool reading = false;

    //reading out our row char by char
    for(int i = 0; i<32; i++)
    {

        Read = Row[i];

        if(Read != ":")
        {
            reading = true;
        }
        else
        {
            reading = false;
        }



        if(reading == true)
        {
            Read_Note += Read;
            Note_Int = Read_Note.toInt();

        }
        else if(reading == false)
        {
            if (Note_Int != 0)
            {
                Note_Int = ((Note_Int + Multi) - 1) * 5;

                Note_Int = InRange(Note_Int);
                Calc_Note = KeyCode(Note_Int);
                /*Note_Test = Calc_Note.toStdString();
                std::cout<<Note_Test<<std::endl;*/
                Output = (Output + Calc_Note + "::");
                //Note_Int = Read.toInt();
                //std::cout<<Note_Int<<std::endl;

            }
            Read_Note = "";

        }

    }

    return Output;
}

//further class functions
//retrograde, inversions and transposition generation.
QList<QString> SerialGen::Randomise_Rows()
{   //our output till contain a transposition number AND a transformation, eg 2RI
    QList<QString> Output;

    QString Gen_Row = "";

    //loop to generate list of rows
    for(int i = 0; i < 42; i++)
    {
        Gen_Row = "";
        //todo code to select transformations
        //these will allow us to only generate each transformation once
        bool R_1 = false;   //1
        bool I_1 = false;   //2
        bool RI_1 = false;  //3
        bool P_2 = false;   //4
        bool R_2 = false;   //5
        bool I_2 = false;   //6
        bool RI_2 = false;  //7
        bool P_3 = false;   //8
        bool R_3 = false;   //9
        bool I_3 = false;   //10
        bool RI_3 = false;  //11
        bool P_4 = false;   //12
        bool R_4 = false;   //13
        bool I_4 = false;   //14
        bool RI_4 = false;  //15
        bool P_5 = false;   //16
        bool R_5 = false;   //17
        bool I_5 = false;   //18
        bool RI_5 = false;  //19
        bool P_6 = false;   //20
        bool R_6 = false;   //21
        bool I_6 = false;   //22
        bool RI_6 = false;  //23
        bool P_7 = false;   //24
        bool R_7 = false;   //25
        bool I_7 = false;   //26
        bool RI_7 = false;  //27
        bool P_8 = false;   //28
        bool R_8 = false;   //29
        bool I_8 = false;   //30
        bool RI_8 = false;  //31
        bool P_9 = false;   //32
        bool R_9 = false;   //33
        bool I_9 = false;   //34
        bool RI_9 = false;  //35
        bool P_10 = false;  //36
        bool R_10 = false;  //37
        bool I_10 = false;  //38
        bool RI_10 = false; //39
        bool P_11 = false;  //40
        bool R_11 = false;  //41
        bool I_11 = false;  //42
        bool RI_11 = false; //43

        //code to generate our string of unique transformations

        for(int i = 0; i < 42; i++)
        {
            int RChoice = rand() % 43 + 1;
            switch(RChoice)
            {
            case 1:
                if (R_1 != true)
                {
                    Gen_Row = "R_1";
                    R_1 = true;
                }
                break;
            case 2:
                if (I_1 != true)
                {
                    Gen_Row = "I_1";
                    I_1 = true;
                }
                break;
            case 3:
                if (RI_1 != true)
                {
                    Gen_Row = "RI_1";
                    RI_1 = true;
                }
                break;
            case 4:
                if (P_2 != true)
                {
                    Gen_Row = "P_2";
                    P_2 = true;
                }
                break;
            case 5:
                if (R_2 != true)
                {
                    Gen_Row = "R_2";
                    R_2 = true;
                }
                break;
            case 6:
                if (I_2 != true)
                {
                    Gen_Row = "I_2";
                    I_2 = true;
                }
                break;
            case 7:
                if (RI_2 != true)
                {
                    Gen_Row = "RI_2";
                    RI_2 = true;
                }
                break;
            case 8:
                if (P_3 != true)
                {
                    Gen_Row = "P_3";
                    P_3 = true;
                }
                break;
            case 9:
                if (R_3 != true)
                {
                    Gen_Row = "R_3";
                    R_3 = true;
                }
                break;
            case 10:
                if (I_3 != true)
                {
                    Gen_Row = "I_3";
                    I_3 = true;
                }
                break;
            case 11:
                if (RI_3 != true)
                {
                    Gen_Row = "RI_3";
                    RI_3 = true;
                }
                break;
            case 12:
                if (P_4 != true)
                {
                    Gen_Row = "P_4";
                    P_4 = true;
                }
                break;
            case 13:
                if (R_4 != true)
                {
                    Gen_Row = "R_4";
                    R_4 = true;
                }
                break;
            case 14:
                if (I_4 != true)
                {
                    Gen_Row = "I_4";
                    I_4 = true;
                }
                break;
            case 15:
                if (RI_4 != true)
                {
                    Gen_Row = "RI_4";
                    RI_4 = true;
                }
                break;
            case 16:
                if (P_5 != true)
                {
                    Gen_Row = "P_5";
                    P_5 = true;
                }
                break;
            case 17:
                if (R_5 != true)
                {
                    Gen_Row = "R_5";
                    R_5 = true;
                }
                break;
            case 18:
                if (I_5 != true)
                {
                    Gen_Row = "I_5";
                    I_5 = true;
                }
                break;
            case 19:
                if (RI_5 != true)
                {
                    Gen_Row = "RI_5";
                    RI_5 = true;
                }
                break;
            case 20:
                if (P_6 != true)
                {
                    Gen_Row = "P_6";
                    P_6 = true;
                }
                break;
            case 21:
                if (R_6 != true)
                {
                    Gen_Row = "R_6";
                    R_6 = true;
                }
                break;
            case 22:
                if (I_6 != true)
                {
                    Gen_Row = "I_6";
                    I_6 = true;
                }
                break;
            case 23:
                if (RI_6 != true)
                {
                    Gen_Row = "RI_6";
                    RI_6 = true;
                }
                break;
            case 24:
                if (P_7 != true)
                {
                    Gen_Row = "P_7";
                    P_7 = true;
                }
                break;
            case 25:
                if (R_7 != true)
                {
                    Gen_Row = "R_7";
                    R_7 = true;
                }
                break;
            case 26:
                if (I_7 != true)
                {
                    Gen_Row = "I_7";
                    I_7 = true;
                }
                break;
            case 27:
                if (RI_7 != true)
                {
                    Gen_Row = "RI_7";
                    RI_7 = true;
                }
                break;
            case 28:
                if (P_8 != true)
                {
                    Gen_Row = "P_8";
                    P_8 = true;
                }
                break;
            case 29:
                if (R_8 != true)
                {
                    Gen_Row = "R_8";
                    R_8 = true;
                }
                break;
            case 30:
                if (I_8 != true)
                {
                    Gen_Row = "I_8";
                    I_8 = true;
                }
                break;
            case 31:
                if (RI_8 != true)
                {
                    Gen_Row = "RI_8";
                    RI_8 = true;
                }
                break;
            case 32:
                if (P_9 != true)
                {
                    Gen_Row = "P_9";
                    P_9 = true;
                }
                break;
            case 33:
                if (R_9 != true)
                {
                    Gen_Row = "R_9";
                    R_9 = true;
                }
                break;
            case 34:
                if (I_9 != true)
                {
                    Gen_Row = "I_9";
                    I_9 = true;
                }
                break;
            case 35:
                if (RI_9 != true)
                {
                    Gen_Row = "RI_9";
                    RI_9 = true;
                }
                break;
            case 36:
                if (P_10 != true)
                {
                    Gen_Row = "P_10";
                    P_10 = true;
                }
                break;
            case 37:
                if (R_10 != true)
                {
                    Gen_Row = "R_10";
                    R_10 = true;
                }
                break;
            case 38:
                if (I_10 != true)
                {
                    Gen_Row = "I_10";
                    I_10 = true;
                }
                break;
            case 39:
                if (RI_10 != true)
                {
                    Gen_Row = "RI_10";
                    RI_10 = true;
                }
                break;
            case 40:
                if (P_11 != true)
                {
                    Gen_Row = "P_11";
                    P_11 = true;
                }
                break;
            case 41:
                if (R_11 != true)
                {
                    Gen_Row = "R_11";
                    R_11 = true;
                }
                break;
            case 42:
                if (I_11 != true)
                {
                    Gen_Row = "I_11";
                    I_11 = true;
                }
                break;
            case 43:
                if (RI_11 != true)
                {
                    Gen_Row = "RI_11";
                    RI_11 = true;
                }
                break;
            default:
                break;
            }




        }



        Output.append(Gen_Row);
    }





    return Output;
}

//there will be two types, random and complete, with complete using all availible rows once.

const QString SerialGen::Complete_Rows(QString Key, QString Num_Row)
{
    QString Output = "";
    QString C_Row = "";

    QList<QString> Future_Rows = SerialGen::Randomise_Rows();
    int K_Num = NumAssin(Key);

    //main loop
    for(int i = 0; i < 42; i++)
    {


        C_Row = Future_Rows[i];




        //create our output string
        Output += (C_Row + "||");
    }



    return Output;
}



