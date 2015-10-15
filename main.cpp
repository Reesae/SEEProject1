#include "dialog.h"
#include <QApplication>
#include "transformer.h"
#include "line.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    Transformer* t = new Transformer(225000000,420000,200000,126300,0.15,0.005,40);
    t->calculate();

    Line * l= new Line(0.05,0.4,0.0000025,225);
    l->calculate();


    return a.exec();
}
