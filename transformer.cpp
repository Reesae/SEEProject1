#include "transformer.h"
#include <QDebug>
Transformer::Transformer(double aP, double v , double iL, double cL, double sCV, double nLC):
apparentPower(aP),voltage(v),ironLosses(iL),copperLosses(cL),shortCircuitVoltage(sCV),noLoadCurrent(nLC)
{
    calculate();
}

void Transformer::calculate()
{
    //This works fine, tested with lecture 3 example.
    setHorizontalReal((copperLosses/apparentPower) * (pow(voltage,2)/apparentPower));
    setHorizontalImag(sqrt(pow(shortCircuitVoltage,2)-pow((copperLosses/apparentPower),2)) * (pow(voltage,2)/apparentPower));
    setVerticlalReal(ironLosses/pow(voltage,2));
    setVerticlalImag((-1.0) * (noLoadCurrent * apparentPower)/pow(voltage,2));

    qDebug()<<"Parametry zastępcze transformatora";
    qDebug()<<this->getHorizontal().real();
    qDebug()<<this->getHorizontal().imag();
    qDebug()<<this->getVertical().real();
    qDebug()<<this->getVertical().imag();
}

