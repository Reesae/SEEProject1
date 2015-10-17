#ifndef NODE_H
#define NODE_H
#include "engine.h"
#include "element.h"

class Node
{
public:
    Node(std::complex<double> & aP,double v,Node * n);
    Node(std::vector<Engine *>  eng,std::vector<Engine *>  gen,double v,Node * n);
    void calculate();
    inline std::complex<double> & getNodePower(){return apparentNodePower;}
private:
    std::complex<double> apparentNodePower;
    std::complex<double> verticalLosses;

    //Power supply and consumption
    std::vector<Engine *> engines;
    std::vector<Engine *> generator;

    double nominalVoltage;
    double voltage;
    double voltageVar;
    double angle;

    Node * prev;







};

#endif // NODE_H
