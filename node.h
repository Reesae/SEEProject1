#ifndef NODE_H
#define NODE_H
#include "engine.h"


class Node
{
public:
    Node();
    void calculate();
private:
    Node * prev;
    double nominalVoltage;
    double voltage;
    double voltageVar;
    double angle;

    std::vector<Engine *> engines;
    std::vector<Engine *> generator;



};

#endif // NODE_H
