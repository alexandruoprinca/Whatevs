#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QTableView>
#include "Model.h"

class ClientWindow : public QWidget
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);

private:
    QHBoxLayout* layout;
    QGroupBox* group;
    QPushButton *train_button;
    QLabel* label;
    QTableView* listView;
    Model* model;


};
#endif // MAINWINDOW_H
