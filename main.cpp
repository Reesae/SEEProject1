#include "dialog.h"
#include <QApplication>
#include "transformer.h"
#include "line.h"
#include "node.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    Transformer* t = new Transformer(225000000,420000,200000,126300,0.15,0.005,40);
    Line * l= new Line(0.05,0.4,0.0000025,225);
    Engine * e = new Engine(500,140000,5.5,0.95,0.34,Engine::state::NORMAL);


    std::complex<double> n1p(425000000,75000000);
    Node * n1 = new Node(n1p,345000000.0,nullptr);
    n1->calculate();





    return a.exec();
}
