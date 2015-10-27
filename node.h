#ifndef NODE_H
#define NODE_H
#include "engine.h"
#include "element.h"

class Node
{
public:
    Node(std::complex<double> aP,double v,Node * n);

    void addEngines(std::vector<Engine *>  &eng,std::vector<Engine *> &gen);
    void calculate();

    inline void setNodePower(std::complex<double> p){apparentNodePower = p;}
    inline std::complex<double> getNodePower(){return apparentNodePower;}

    inline void setVerticlalLosses(std::complex<double> p){verticalLosses = p;}
    inline std::complex<double> getVerticlalLosses(){return verticalLosses;}

    inline double getVoltage(){return voltage;}
    inline void setNominalVoltage(double v){nominalVoltage = v;}
    inline double getNominalVoltage(){return nominalVoltage;}

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
