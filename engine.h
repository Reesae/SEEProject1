#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
public:
    Engine();
    Engine(double v,double p,double sCF,double cN,double cK);
private:
    double voltage;
    double power;
    double startCurrentFactor;
    double cosfiN;
    double cosfiK;
};

#endif // ENGINE_H
