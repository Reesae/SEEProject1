#ifndef QUADRIPOLE_H
#define QUADRIPOLE_H
#include "transformer.h"
#include "line.h"
#include "node.h"

class Quadripole
{
public:
    Quadripole();
    Quadripole(Transformer & t,Node & n);
    Quadripole(Line & l,Node & n);

    void calculate();
private:
    Element * element;
    Node * node;



};

#endif // QUADRIPOLE_H
