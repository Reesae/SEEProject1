#ifndef ELEMENT_H
#define ELEMENT_H
#include <utility>
#include <complex>


class Element
{
public:
    virtual void calculate()=0;

    inline void setVerticlalReal(const double & p){vertical.real(p);}
    inline void setVerticlalImag(const double & p){vertical.imag(p);}
    std::complex<double> getVertical(){return vertical;}

    inline void setHorizontalReal(const double & p){horizontal.real(p);}
    inline void setHorizontalImag(const double & p){horizontal.imag(p);}
    std::complex<double> getHorizontal(){return horizontal;}
private:
    //Equivalent Circuit parameters
    std::complex<double> vertical;
    std::complex<double> horizontal;

};

#endif // ELEMENT_H
