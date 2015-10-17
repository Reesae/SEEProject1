#ifndef QUADRIPOLE_H
#define QUADRIPOLE_H
#include "transformer.h"
#include "line.h"
#include "node.h"

class Quadripole
{
public:
    Quadripole();
    Quadripole(Element * e, Node *n);
    void calculate();
    inline Node * getNextNode(){return nextNode;}
private:
    Element * element;
    Node * node;
    Node * nextNode;

    double verticalVoltageLosses;
    double horizontalVoltageLosses;
    double nextNodeVoltage;
    double angle;
    std::complex<double> horizontalTransmissionLosses;
    std::complex<double> verticalNodeLosses_2;
    std::complex<double> nextNodeApparentPower;

};

#endif // QUADRIPOLE_H
