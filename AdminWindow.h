#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QTableView>
#include "Model.h"
#include "Controller.h"

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    AdminWindow(Controller& controller, QWidget *parent = nullptr);

private:
    QHBoxLayout* layout;
    QGroupBox* group;
    QPushButton *train_button;
    QLabel* label;
    QTableView* listView;
    Model* model;
    Controller& controller;

};

#endif // ADMINWINDOW_H
