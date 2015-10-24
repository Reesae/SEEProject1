#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "quadripole.h"
#include <QtXlsx>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    void calculate();
    void createSpreadsheet();
    void eraseContainers();
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int index;
    std::vector<Quadripole *> quadripoles;
    std::vector<Quadripole *> quadripoles_r;
    std::vector<Node *> nodes;
    std::vector<Node *> nodes_r;
    std::vector<Element *> elements;

};

#endif // DIALOG_H
