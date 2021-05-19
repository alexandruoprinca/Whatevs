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
public slots:
    void connected_client();
    void connected_admin();

private:
    QHBoxLayout* layout;
    QGroupBox* group;
    QPushButton *client_button;
    QPushButton *admin_button;
    QWidget* window = nullptr;



};
#endif // MAINWINDOW_H
