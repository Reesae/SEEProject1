#include "node.h"

Node::Node(std::complex<double> &aP, double v,Node * n):apparentNodePower(aP),voltage(v),prev(n)
{

}

Node::Node(std::vector<Engine *> eng, std::vector<Engine *> gen,double v,Node * n):engines(std::move(eng)),
generator(std::move(gen)),voltage(v),prev(n)
{

}

void Node::calculate()
{
    //Caluclates apparentPower
    for(auto itm : engines)
    {
        apparentNodePower+=itm->getApparentPower();
    }

    for(auto itm : generator)
    {
        apparentNodePower-=itm->getApparentPower();
    }

    qDebug()<<"Moc węzła";
    qDebug()<<apparentNodePower.real();
    qDebug()<<apparentNodePower.imag();


}

