#ifndef TRANSFORMER_H
#define TRANSFORMER_H
#include "element.h"

class Transformer : public Element
{

public:
    Transformer();
    Transformer(double aP, double v , double iL, double cL, double sCV, double nLC);
    virtual void calculate() override;
private:
    //Transformer data
    double apparentPower;
    double voltage;
    double ironLosses;
    double copperLosses;
    double shortCircuitVoltage;
    double noLoadCurrent;






};

#endif // TRANSFORMER_H
