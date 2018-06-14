#pragma once


#ifndef STRUCTURE_H
#define STRUCTURE_H


#include<ctime>
#include <Qstring>
#include <QList>





class StructureClass_A
{
    public:
        void random_reset();
        QString SectionGen(int Length, int NumSections);

        //alg selection
        QList<QString> Alg_Choice(int Length, int NumSections, int Choice);

        //default structure alg
        QList<QString> SectionGenList(int Length, int NumSections);



    private:
        //rondo form ABACADAEA... etc
        QList<QString> Rondo_Form(int Length, int NumSections);
        QList<QString> Verse_Chorus(int Length, int NumSections);
        QList<QString> Blues_12(int Length, int NumSections);


};




//old code!

class StructureClass_B
{

};




class StructureClass : public StructureClass_A, public StructureClass_B
{
       public:
    /*
            QString Structure(int NumSections, int Length);
            StructureClass_A Alg_Choice;
            StructureClass_A Alg_B;*/


       private:
             QString Sections(int Length, int NumSections);
             int SectionCheck(int Length, QString OUT);

};











#endif
