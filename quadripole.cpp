#include "quadripole.h"

Quadripole::Quadripole()
{

}

Quadripole::Quadripole(Element *e, Node *n):element(e),node(n)
{
    calculate();
}

void Quadripole::calculate()
{
    std::complex<double> vNLosses;
    vNLosses.real(element->getVertical().real() * pow(node->getVoltage(),2)/2);
    vNLosses.imag((-1.0) * element->getVertical().imag() * pow(node->getVoltage(),2)/2);
    node->setVerticlalLosses(vNLosses);

    qDebug()<< "Straty poprzeczne w węźle:";
    qDebug()<<vNLosses.real();
    qDebug()<<vNLosses.imag();

    node->setNodePower(node->getNodePower() + node->getVerticlalLosses());

    qDebug()<<"Moc węzła";
    qDebug()<<node->getNodePower().real();
    qDebug()<<node->getNodePower().imag();

    horizontalVoltageLosses = ((node->getNodePower().real() * element->getHorizontal().real() +
                                node->getNodePower().imag() * element->getHorizontal().imag() )/node->getVoltage());

    verticalVoltageLosses = ((node->getNodePower().real() * element->getHorizontal().imag() -
                              node->getNodePower().imag() * element->getHorizontal().real())/node->getVoltage());

    nextNodeVoltage = sqrt(pow(node->getVoltage() + horizontalVoltageLosses,2) + pow(verticalVoltageLosses,2));

    qDebug()<<"Strata podłużna";
    qDebug()<< horizontalVoltageLosses;
    qDebug()<<"Strata poprzeczna";
    qDebug()<< verticalVoltageLosses;
    qDebug()<<"nastepne napiecie";
    qDebug()<< nextNodeVoltage;

    //Conversion from radians to degrees
    angle = atan2(verticalVoltageLosses,node->getVoltage() + horizontalVoltageLosses) * 180.0/3.14159;

    qDebug()<<"kat";
    qDebug()<<angle;

    horizontalTransmissionLosses.real(element->getHorizontal().real() * (pow(node->getNodePower().real(),2)+
                             pow(node->getNodePower().imag(),2))/pow(node->getVoltage(),2));
    horizontalTransmissionLosses.imag(element->getHorizontal().imag() * (pow(node->getNodePower().real(),2)+
                             pow(node->getNodePower().imag(),2))/pow(node->getVoltage(),2));

    qDebug()<<"Straty przesyłowe podluzne";
    qDebug()<< horizontalTransmissionLosses.real();
    qDebug()<< horizontalTransmissionLosses.imag();
    //verticalNodeLosses_2.real()

    verticalNodeLosses_2.real(element->getVertical().real() * pow(nextNodeVoltage,2)/2);
    verticalNodeLosses_2.imag((-1.0) * element->getVertical().imag() * pow(nextNodeVoltage,2)/2);

    qDebug()<<"Straty w wezle (2)";
    qDebug()<< verticalNodeLosses_2.real();
    qDebug()<< verticalNodeLosses_2.imag();

    nextNodeApparentPower = node->getNodePower() + horizontalTransmissionLosses + verticalNodeLosses_2;
    qDebug()<<"Moc plynaca z wezal next";
    qDebug()<< nextNodeApparentPower.real();
    qDebug()<< nextNodeApparentPower.imag();

    nextNode = new Node(nextNodeApparentPower,nextNodeVoltage,node);

}

