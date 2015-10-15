#ifndef LINE_H
#define LINE_H
#include "element.h"

class Line : public Element
{
public:
    Line();
    Line(double res,double rea,double sus,double len);
    virtual void calculate() override;
private:
    //Line parameters
    double resistancePerKm;
    double reactancePerKm;
    double susceptancePerKm;
    double lengthInKm;


};

#endif // LINE_H
