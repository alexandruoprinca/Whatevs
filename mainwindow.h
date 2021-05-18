#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QTableView>
#include "Model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QHBoxLayout* layout;
    QGroupBox* group;
    QPushButton *train_button;
    QLabel* label;
    QTableView* listView;
    Model* model;


};
#endif // MAINWINDOW_H
