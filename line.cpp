#include "line.h"
#include <QDebug>
Line::Line()
{

}

Line::Line(double res, double rea, double sus, double len):resistancePerKm(res),reactancePerKm(rea),
susceptancePerKm(sus),lengthInKm(len)
{

}

void Line::calculate()
{
    setHorizontalReal(resistancePerKm * lengthInKm);
    setHorizontalImag(reactancePerKm * lengthInKm);
    setVerticlalReal(0.0);
    setVerticlalImag(susceptancePerKm * lengthInKm);

    qDebug()<<this->getHorizontal().real();
    qDebug()<<this->getHorizontal().imag();
    qDebug()<<this->getVertical().real();
    qDebug()<<this->getVertical().imag();
}

