#include "dialog.h"
#include <QApplication>
#include "transformer.h"
#include "line.h"
#include "node.h"
#include "quadripole.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

//    Transformer* t = new Transformer(225000000,420000,200000,126300,0.15,0.005);
//    Line * l= new Line(0.05,0.4,0.0000025,225);
//    Engine * e = new Engine(500,140000,5.5,0.95,0.34,Engine::state::NORMAL);


//    std::complex<double> n1p(425000000,75000000);
//    Node * n1 = new Node(n1p,345000.0,nullptr);
//    Quadripole * q = new Quadripole(l,n1);
//    Node * n2 = q->getNextNode();

//    std::complex<double> e2(800000000,-100000000);
//    std::complex<double> g2(600000000,100000000);

//    Engine* eng = new Engine(e2);
//    Engine* gen = new Engine(g2);
//    std::vector<Engine *> engines;
//    std::vector<Engine *> gens;
//    engines.push_back(eng);
//    gens.push_back(gen);

//    n2->addEngines(engines,gens);
//    Quadripole * q2 = new Quadripole(t,n2);






    return a.exec();
}
