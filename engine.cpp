#include "engine.h"

Engine::Engine()
{

}

Engine::Engine(double v, double p, double sCF, double cN, double cK, state s):
voltage(v),activePower(p),startCurrentFactor(sCF),cosfiN(cN),cosfiK(cK),st(s)
{
    calculate();
}

Engine::Engine(std::complex<double> s):apparentPower(s)
{

}

//Calulate apparentPower based on engine state
void Engine::calculate()
{
    if(st == state::START)
    {
        //TODO how to get power during start ????
        //apparentPower = activePower/
    }
    else if(st == state::NORMAL)
    {
        apparentPower.real(activePower);
        apparentPower.imag(activePower * sqrt(1.0-pow(cosfiN,2)));
    }

     qDebug()<<"Moc pozrona silnika ";
     qDebug()<<apparentPower.real();
     qDebug()<<apparentPower.imag();
}


