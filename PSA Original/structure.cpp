#include "Structure.h"
#include <iostream>


// first algorithm
//uses random numbers to create totally random structures that fit within classic lengths


//reset seed for rand



void StructureClass_A::random_reset()
{
    srand(time(0));
}


QList<QString> StructureClass_A::Alg_Choice(int Length, int NumSections, int Choice)
{

    QList<QString> Sections;
    //Sections = SectionGenList(Length, NumSections); //debug code

    try
    {
        switch(Choice)
        {
        //default alg
        case 1:
            Sections = SectionGenList(Length, NumSections);
            break;
        //rondo form
        case 2:
            if(NumSections <= 2)
            {
                throw std::invalid_argument("E100");

            }
            else
            {
                Sections = Rondo_Form(Length, NumSections);

            }
            break;

        //verse + chorus
        case 3:
            Sections = Verse_Chorus(Length, NumSections);
            break;
        //12 bar blues
        case 4:
            Sections = Blues_12(Length, NumSections);
            break;
        //default alg
        default:
            Sections = SectionGenList(Length, NumSections);
            break;


        }
    }
    catch(std::exception& e)
    {
        Sections.push_back(e.what());
        Sections.push_back("hello");

    }





    return Sections;
}

QList<QString> StructureClass_A::Rondo_Form(int Length, int NumSections)
{
    QList<QString> Sections;
    try
    {

        float IsEven = 0.00; //to check for odd sections
        int Section_Count = 1; //section counter
        int Section_Main = 0; //our A section initialised
        int Total_Length = 0; //total length counter
        int Section_Length = 0; //length of current section
        int Rand = 0; //creation of random variable for later use


        //code copied from default alg for easy use
        //min and max length calulations - length to the power of ns - 1
        int Max_L= 0;
        int Min_L = Length/ pow(2, NumSections - 1);
        //keeps minL at value of 4 for large ratios
        //values where l / n <4 are already filtered out
        if(Min_L < 4)
        {
            Min_L = 4;
        }

        //max length conditional - did design a formula but was simpler to use this instead
        if(4 * (NumSections - 1) <= Length / 2)
        {
            Max_L = Length / 2;

        }
        else if((4 * (NumSections - 1) >= Length / 2) && (4 * (NumSections - 1) < Length/ 1.25))
        {
            Max_L = Length / 4;

        }
        else if((4 * (NumSections - 1) > Length/ 1.25) && (4 * (NumSections - 1) < Length/ 1.125))
        {
            Max_L = Length / 8;
        }
        else if ((4 * (NumSections - 1) > Length/ 1.125) && (4 * (NumSections - 1) < Length/ 1.0625))
        {
            Max_L = Length / 16;
        }
        else
        {
            Max_L = Length / 32;
        }


        //first section calculation
        Rand = rand() % 4 + 1;
        if(Rand == 1)
        {
            Section_Main = Min_L;
        }
        else if(Rand == 2)
        {
            Section_Main = Min_L * 2;
        }
        else if(Rand == 3)
        {
            Section_Main = Max_L / 4;
        }
        else if(Rand == 4)
        {
            Section_Main = Max_L / 2;
        }


        for(int i = 0; i< NumSections; i++)
        {
            //determine odd numbered sections
            IsEven = Section_Count / 2.00;

            //for all but final section
            if(Section_Count < NumSections)
            {



                //odd numbered bars
                if(floor(floor(IsEven) == IsEven))
                {
                    Rand = rand() % 4 + 1;
                    if(Rand == 1)
                    {
                        if(Rand == 1)
                        {
                            Rand = 2;
                        }
                        else
                        {
                            Section_Length = Rand / 2;
                        }
                    }
                    else if(Rand == 2)
                    {
                        Section_Length = Max_L / Rand;
                    }
                    else if(Rand == 3)
                    {
                        Section_Length = Min_L * 2;
                    }
                    else if(Rand == 4)
                    {
                        Section_Length =Min_L;
                    }



                }
                //odd sections will always be section a
                else if(floor(floor(IsEven) != IsEven))
                {

                    Section_Length = Section_Main;
                }
            }
            //so final section is always the rondo
            else
            {
                Section_Length = Section_Main;
            }

            Total_Length += Section_Length;
            Sections.push_back(QString::number(Section_Length));
            Section_Count += 1;

        }

    }
    catch(std::exception& e)
    {
        Sections.push_back(e.what());
    }


    return Sections;
}

QList<QString> StructureClass_A::Verse_Chorus(int Length, int NumSections)
{
    QList<QString> Sections;




    return Sections;
}

QList<QString> StructureClass_A::Blues_12(int Length, int NumSections)
{
    QList<QString> Sections;




    return Sections;
}

//default alg
//note this alg will ONLY create sections of multiples of 4 bars.
QList<QString> StructureClass_A::SectionGenList(int Length, int NumSections)
{
    //create our list and random objects
    QList<QString> Sections;
    int Rand = 0;
    //iterator creation
    QList<QString>::iterator IT;
    IT = Sections.begin();
    //other int objects
    int Section_Length = 0;
    int Rand_Multi = 1;
    int Rand_Mod = 1;
    int Total_Length = 0;
    int RM = 0;
    //bool to check if output is suitable
    bool is_solved = false;

    //min and max length calulations - length to the power of ns - 1
    int Max_L= 0;
    int Min_L = Length/ pow(2, NumSections - 1);
    //keeps minL at value of 4 for large ratios
    //values where l / n <4 are already filtered out
    if(Min_L < 4)
    {
        Min_L = 4;
    }

    //max length conditional - did design a formula but was simpler to use this instead
    if(4 * (NumSections - 1) <= Length / 2)
    {
        Max_L = Length / 2;

    }
    else if((4 * (NumSections - 1) >= Length / 2) && (4 * (NumSections - 1) < Length/ 1.25))
    {
        Max_L = Length / 4;

    }
    else if((4 * (NumSections - 1) > Length/ 1.25) && (4 * (NumSections - 1) < Length/ 1.125))
    {
        Max_L = Length / 8;
    }
    else if ((4 * (NumSections - 1) > Length/ 1.125) && (4 * (NumSections - 1) < Length/ 1.0625))
    {
        Max_L = Length / 16;
    }
    else
    {
        Max_L = Length / 32;
    }





    //maths to determine appropraite section lengths.
    Rand_Multi = 4;
    RM = Length / 8;


    /*final Alg!!! not bugfree but based on a series of conditionals and checks to ensure that randomised values are applicable.
     *may still be subject to change, the previous version can be found below!
     * */
    try
    {
        //new alg
        while(is_solved != true)
        {
            for(int i = 0; i < NumSections; i++)
            {
                Rand = rand() % Rand_Multi + 1;

                //std::cout<<Rand<<std::endl;
                //this code ensures that if length / sections = 4 then all sections are the same length
                if(Length / NumSections == 4)
                {
                    Section_Length = Min_L; //will always be 4
                }


                //main section alg

                else if(i < NumSections - 1)
                {
                    //so that both sections are same length if numsections = 2 etc.
                    if (Min_L == Max_L)
                    {
                        Section_Length = Min_L;

                    }
                    //main alg for randomised sections
                    //penultiamte section check for undesirable values
                    //prevent too large values
                    else if((i >= NumSections - 2) && (Length - Total_Length > Max_L))
                    {

                        //to cater for really large values!
                        if(Length - Total_Length > Max_L + Min_L)
                        {
                            Section_Length = Max_L;
                        }
                        else
                        {
                            Section_Length = Max_L / 2;
                        }


                        //std::cout<<"big check 1"<<std::endl; // debug code

                    }
                    //prevent too small values
                    else if((i >= NumSections - 2) && (Length - Total_Length <= Min_L * 2))
                    {

                        Section_Length = Min_L;
                        //std::cout<<"small check 1"<<std::endl; // debug code


                    }
                    //rand gets learger for more sections
                    else
                    {
                        //will be based on powers of 2
                        Rand_Mod = rand() % RM + 1;
                        //this evens out undesirable values and corrects probabiltiy of low values!
                        if(Rand_Mod <= 8)
                        {
                            switch(Rand_Mod)
                            {
                            case 3:
                                Rand_Mod = 2;
                                break;
                            case 5:
                                Rand_Mod = 4;
                                break;
                            case 6:
                                Rand_Mod = 4;
                                break;
                            case 7:
                                Rand_Mod = 4;
                                break;
                            }
                        }
                        else
                        {
                            Rand_Mod = 4;
                        }

                        Section_Length = Min_L * Rand_Mod;
                        //to ensure that max_L is not used more than once
                        if((Section_Length == Max_L) && (Length - Total_Length > 0))
                        {
                            Section_Length = Min_L * Rand_Mod;
                            //to ensure that section is smaller than Maxl
                            if(Section_Length == Max_L)
                            {
                                Section_Length = Min_L;
                            }
                        }

                        //to check that no sections are bigger than max_l!
                        else if((Section_Length > Max_L) && ((Length - Total_Length) <= Length / 2))
                        {
                            Section_Length = Max_L / 2;
                        }
                        //main alg!
                        else if((Section_Length > Max_L) && ((Length - Total_Length) > Length / 2))
                        {


                            Section_Length = Min_L * Rand_Mod / 2;


                            //to prevent values of fewer than 4
                            if (Section_Length < Min_L)
                            {
                                Section_Length = Min_L;
                            }
                        }
                    }
                }



                //final section
                else if(i >= NumSections - 1)
                {
                    Section_Length = Length - Total_Length;
                    if(Section_Length < 4)
                    {


                        Sections.clear();
                        throw std::exception("E151");


                        is_solved = false;

                        for(int i = 0; i < NumSections; i++)
                        {
                            Sections.push_back("");
                        }
                    }
                    else
                    {
                        is_solved = true;
                    }

                }

                Sections.push_back(QString::number((Section_Length)));
                Total_Length += Section_Length;


            }
            if (Total_Length != Length)
            {

                throw(std::exception("E150"));
            }
        return Sections;
        }
    }

    catch(std::exception& e)
    {
        Sections.clear();

        //to prevent index out of range errors!!
        for(int i = 1; i < NumSections; i++)
        {
            Sections.push_back(e.what());
        }
        Sections.push_back(e.what());

        return Sections;
    }


    //Sections << "4" << "8";


}



//this is old code -- will ultimately be removed!
QString StructureClass_A::SectionGen(int Length, int NumSections)
{
    //reference and assignments of variables


    int LMin = 0;
    int SectL = 0;
    int LTot = 0;
    int LM = 0;
    int Counter = 1;
    int RND = 0;
    QString S = "";

    //todo; different numbres of sections dependant on user choice
    //initially will use length / 4.

    //CODE TO CALCULATE LENGTHS OF SECTION
    //min length relative to total length
    LMin = Length / 8;

    if(LMin <= 1)
    {
        LMin = 1;
    }
    //modifier for length dependant on number of sections
    LM = Length / NumSections;


    for (int i = 0; i < NumSections; i++)
    {
            if (Counter < NumSections)
            {
                SectL = LM;

                SectL = (SectL / 4);
                SectL = (SectL * 4);
                if(SectL <= 1)
                {
                    SectL = 1;
                }
                //randomiser to lengthern or shortern sections
                RND = rand() % 3 + 1;

                if (RND == 2)
                {
                    SectL = SectL * 2;
                }
                else if (RND == 3)
                {
                    SectL = SectL / 2;
                }
                else
                {
                    SectL = SectL;
                }

                LTot += SectL;
                Counter += 1;
            }

            else if (Counter >= NumSections)
            {
                SectL = Length - LTot;
                LTot += SectL;
                Counter += 1;
            }
            else if (NumSections <= i)
            {
                std::cout<<"critical error"<<std::endl;
            }
            S = S  + QString::number(SectL) + ";";
    }

    //std::cout << "total is " << LTot << std::endl;
    return S;


}






// basic template alg for calculating structure

/*
QString StructureClass::Structure(int NumSections, int Length)
{

    //total length of music

    // old code - QString Sect = Sections(Length, NumSections);
    QString Sect = SectionGen()



    return Sect;
}



//function to select deisrable outcomes from sectiongen function
// also selects from availible algs

QString StructureClass::Sections(int Length, int NumSections)
{
    //initialise our alg choice object, will add switch in future!


    //create a solved var for our loop
    int Is_Solved = 0;


    //initalise OUT value with sectiongen string
    QString OUT = Alg_Choice.SectionGen(Length, NumSections);
    //loop to test if our string is suitible

    while(Is_Solved <= 1)
    {
        Is_Solved = SectionCheck(Length, OUT);
        //std::cout << Is_Solved << std::endl;


        if (Is_Solved == 1)
        {

            OUT = Alg_Choice.SectionGen(Length, NumSections);
            //std::cout << Is_Solved << std::endl;


        }
        else
        {

            break;
        }
    }



    return OUT;
}



int StructureClass::SectionCheck(int Length, QString OUT)
{
    int Result = 0;
    for (QChar& c : OUT)
    {
        //unnaceptable characters- to be filtered out
        if ((c == '0') || (c == '5') || (c == '7') || (c == '9') || (c == '-'))

        {
            //std::string OUT = Alg_Choice.SectionGen(Length);
            //std::cout << "fail " << c << std::endl;
            Result += 1;
            //std::cout << Result << std::endl;

        }
        else
        {

            Result += 0;
            //std::cout << Result << std::endl;

        }

    }

    if (Result != 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
*/








