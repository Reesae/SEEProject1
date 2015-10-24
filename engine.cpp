#include "engine.h"

Engine::Engine()
{

}

Engine::Engine(double v, double p, double sCF, double cN, double cK, double eta, state s):
voltage(v),activePower(p),startCurrentFactor(sCF),cosfiN(cN),cosfiK(cK),eta(eta),st(s)
{
    calculate();
}

Engine::Engine(std::complex<double> s):apparentPower(s)
{
    calculate();
}

//Calulate apparentPower based on engine state
void Engine::calculate()
{
    if(st == state::START)
    {
        apparentPower.real(startCurrentFactor * activePower/eta);
        apparentPower.imag(apparentPower.real() * sqrt(1.0-pow(cosfiK,2)));
    }
    else if(st == state::NORMAL)
    {
        apparentPower.real(activePower/eta);
        apparentPower.imag(apparentPower.real() * sqrt(1.0-pow(cosfiN,2)));
    }

     qDebug()<<"Moc pozrona silnika ";
     qDebug()<<apparentPower.real();
     qDebug()<<apparentPower.imag();
}


