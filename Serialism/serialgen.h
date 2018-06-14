#ifndef SERIALGEN_H
#define SERIALGEN_H
#include <QString>


class SerialGen
{
public:

    SerialGen();
    const QString SerialGen::Generate(QString Note);
    const QString SerialGen::Noteify(QString Row, QString Note);
    const QString SerialGen::KeyGen(int Rand);
    const QString SerialGen::Complete_Rows(QString Key, QString Num_Row);
    void RandomReset();
private:

    int NumAssin(QString Key);
    int InRange(int N);
    int NumGen(int R);
    QString KeyCode(int Num);
    QString Rowify(QString Key);
    QList<QString> SerialGen::Randomise_Rows();





};

#endif // SERIALGEN_H
