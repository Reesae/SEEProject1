#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <memory>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::calculate()
{
    if(quadripoles.size() != 0) eraseContainers();

    //Creates element derived elements and add them to container
    Transformer * t1 = new Transformer(40000000.0,10000.0,33000.0+1000.0 * static_cast<double>(index/10),
    205000.0 + 1000.0 * static_cast<double>(index),0.10+static_cast<double>(index/10000),0.005+static_cast<double>(index/10000));

    Transformer * t2 = new Transformer(3000000.0,10000.0,2000.0+1000.0 * static_cast<double>(index/100),
    10000.0 + 1000.0 * static_cast<double>(index/100),0.06 + static_cast<double>(index/10000),0.01 + static_cast<double>(index/10000));

    Line * l1 = new Line(0.44,0.37,0.0000032,5 + static_cast<double>(index/10));
    Line * l2 = new Line(0.255,0.085,0.000080,2 + static_cast<double>(index/10));

    elements.push_back(t1);
    elements.push_back(l1);
    elements.push_back(l2);
    elements.push_back(t2);

    std::vector<Engine *> engines_1;
    std::vector<Engine *> engines_2;
    std::vector<Engine *> generator;
    std::vector<Engine *> eee;
    Engine e1(500.0,100000.0 + 1000.0 * index,5.0 + static_cast<double>(index/100),0.83 + static_cast<double>(index/1000),0.30 + static_cast<double>(index/1000),0.90,Engine::state::NORMAL);

    for(int i= 0;i<6;i++)
    {
        engines_1.push_back(&e1);
    }

    Engine e2(std::complex<double>(2000000.0 + 10000 * index,(2000000.0 + 10000 * index) * sin(atan(0.4))));
    engines_2.push_back((&e2));

    Engine g1(std::complex<double>(12000000.0 + 10000 * index,(12000000.0 + 10000 * index) * tan(acos(0.95))));
    generator.push_back(&g1);

    Node * n1 = new Node(0,10000,nullptr);
    n1->addEngines(engines_1,eee);
    nodes.push_back(n1);
    Quadripole * q1 = new Quadripole(t2,n1);
    quadripoles.push_back(q1);
    Node * n2 = q1->getNextNode();
    nodes.push_back(n2);
    Quadripole * q2 = new Quadripole(l2,n2);
    quadripoles.push_back(q2);
    Node * n3 = q2->getNextNode();
    nodes.push_back(n3);
    Quadripole * q3 = new Quadripole(l1,n3);
    quadripoles.push_back(q3);
    Node * n4 = q3->getNextNode();
    n4->addEngines(engines_2,generator);
    nodes.push_back(n4);
    Quadripole * q4 = new Quadripole(t1,n4);
    quadripoles.push_back(q4);
    Node * n5 = q4->getNextNode();
    nodes.push_back(n5);


    engines_1.at(0)->changeState();
    qDebug()<<"dd";
    Node * n1_r = new Node(0,10000,nullptr);
    n1_r->addEngines(engines_1,eee);
    nodes_r.push_back(n1_r);
    Quadripole * q1_r = new Quadripole(t2,n1_r);
    quadripoles_r.push_back(q1_r);
    Node * n2_r = q1_r->getNextNode();
    nodes_r.push_back(n2);
    Quadripole * q2_r = new Quadripole(l2,n2_r);
    quadripoles_r.push_back(q2_r);
    Node * n3_r = q2_r->getNextNode();
    nodes_r.push_back(n3_r);
    Quadripole * q3_r = new Quadripole(l1,n3_r);
    quadripoles_r.push_back(q3_r);
    Node * n4_r = q3_r->getNextNode();
    n4_r->addEngines(engines_2,generator);
    nodes_r.push_back(n4);
    Quadripole * q4_r = new Quadripole(t1,n4_r);
    quadripoles_r.push_back(q4_r);
    Node * n5_r = q4_r->getNextNode();
    nodes_r.push_back(n5_r);

    createSpreadsheet();
}

void Dialog::createSpreadsheet()
{
    //Tables titles
    QStringList titles;
    titles << "Tabela 1. Dane gałęziowe"
           << "Tabela 2.1n. Wariant pracy normalnej - wyniki rozpływu mocy w poszczególnych czwórnikach p-k"
           << "Tabela 2.1r. Wariant pracy z rozruchem - wyniki rozpływu mocy w poszczególnych czwórnikach p-k"
           << "Tabela 3.1n. Wariant pracy normalnej - napięcia i procentowe odchylenia, moce węzłowe"
           << "Tabela 3.1r. Wariant pracy z rozruchem - napięcia i procentowe odchylenia, moce węzłowe";

    QStringList label1,label2,label3;

    //Horizontal tables headers, \u2126 is ohm, \u00B5 is micro
    label1 << "Czwórnik" << "R [\u2126]"<<"X [\u2126]"<<"G [\u00B5S]"<<"B [\u00B5S]";
    label2 << "Czwórnik p-k" << "U [kV]" << "Pp [MW]" <<"dPpp [MW]" <<"Qp [MVar]" <<"dPpp [MVar]"<<"dP [MW]" <<"dQ [MVar]"
           << "Uk [kV]" << "Pk [MW]" <<"dPkk [MW]" << "Qk [MVar]" <<"dQkk [MVar]";
    label3 << "Nap. znam. [kV]" << "Nap. obl. [kV]" <<"Procentowe odch. nap." <<"Spelnienie ogr. nap."
           << "Węzłowa moc czynna odbierana [MW]" << "Węzłowa moc bierna odbierana [MVar]"
           << "Węzłowa moc czynna generowana [MW]" << "Węzłowa moc bierna generowana [MVar]";

    //Create a new .xlsx file.

        QXlsx::Document xlsx;
        xlsx.write("A1", titles.at(0));

        QXlsx::Format titleFormat;
        titleFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
        titleFormat.setBorderStyle(QXlsx::Format::BorderThin);
        xlsx.mergeCells("A1:E1", titleFormat);

        int rowCount = 2;
        QChar columnCount = 'A';

        for(auto itm: label1)
        {
             xlsx.write((QString("%1%2").arg(columnCount).arg(rowCount)),itm);
             columnCount=static_cast<QLatin1Char>(columnCount.toLatin1() + 1);
        }

        rowCount++;

        for(auto itm: elements){

           xlsx.write((QString("B%1").arg(rowCount)),QString::number(itm->getHorizontal().real()),titleFormat);
           xlsx.write((QString("C%1").arg(rowCount)),QString::number(itm->getHorizontal().imag()),titleFormat);
           xlsx.write((QString("D%1").arg(rowCount)),QString::number(1000000.0 * itm->getVertical().real()),titleFormat);
           xlsx.write((QString("E%1").arg(rowCount)),QString::number(1000000.0 * itm->getVertical().imag()),titleFormat);

           rowCount++;
    }

        rowCount++;

        //Table 2a
        xlsx.write(QString("A%1").arg(rowCount),titles.at(1));
        xlsx.mergeCells(QString("A%1:M%1").arg(rowCount), titleFormat);

        rowCount++;
        columnCount = 'A';

        for(auto itm: label2)
        {
             xlsx.write((QString("%1%2").arg(columnCount).arg(rowCount)),itm);
             columnCount=static_cast<QLatin1Char>(columnCount.toLatin1() + 1);
        }
         rowCount++;
         int rowCountCopy = rowCount;
//TODO
        for(auto itm: nodes)
        {
            xlsx.write((QString("B%1").arg(rowCount)),QString::number(),titleFormat);
            xlsx.write((QString("C%1").arg(rowCount)),QString::number(),titleFormat);
            xlsx.write((QString("D%1").arg(rowCount)),QString::number(),titleFormat);
            xlsx.write((QString("E%1").arg(rowCount)),QString::number(),titleFormat);
            rowCount++;
        }

        int rowCount = rowCountCopy;

        for(auto itm : quadripoles)
        {
            xlsx.write((QString("B%1").arg(rowCount)),QString::number(),titleFormat);
            xlsx.write((QString("C%1").arg(rowCount)),QString::number(),titleFormat);
            xlsx.write((QString("D%1").arg(rowCount)),QString::number(),titleFormat);
            xlsx.write((QString("E%1").arg(rowCount)),QString::number(),titleFormat);
        }




        xlsx.saveAs(QString("%1.xlsx").arg(ui->lineEdit->text()));
}

void Dialog::eraseContainers()
{
    elements.erase(elements.begin());
    nodes.erase(nodes.begin());
    nodes_r.erase(nodes_r.begin());
    quadripoles.erase(quadripoles.begin());
    quadripoles_r.erase(quadripoles_r.begin());

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //Caluclates 'a' parameter
    index = 20;
    QString list = ui->lineEdit->text();
    QString::const_iterator constIterator;
    for (constIterator = list.constBegin(); constIterator != list.constEnd();++constIterator)
    {
        if((*constIterator).isDigit())
        index+=(*constIterator).digitValue();
    }

    calculate();

}
