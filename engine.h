#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <complex>
#include <QDebug>
class Engine
{
public:
    enum class state : int {START = 0,NORMAL = 1};

    Engine();
    Engine(double v,double p,double sCF,double cN,double cK,double eta,state s);
    Engine(std::complex<double> s);
    void calculate();
    inline std::complex<double> getApparentPower(){return apparentPower;}
    void changeState(){st = (st == Engine::state::NORMAL) ? Engine::state::START : Engine::state::NORMAL; calculate();}
private:
    //Data
    double voltage;
    double activePower;
    double startCurrentFactor;
    double cosfiN;
    double cosfiK;
    double eta;
    //Calculated
    std::complex<double> apparentPower;
    state st;



};

#endif // ENGINE_H
