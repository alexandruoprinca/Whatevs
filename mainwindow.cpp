#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include "Model.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    group = new QGroupBox(this);
    layout = new QHBoxLayout{};

    train_button = new QPushButton(this);
    train_button->setText(tr("something"));

    listView = new QTableView(this);
    model = new Model{};
    listView->setModel(model);

    label = new QLabel(this);
    label->setText("Penis");
    layout->addWidget(train_button);
    layout->addWidget(label);
    layout->addWidget(listView);
    layout->setSpacing(100);
    group ->setLayout(layout);
    group->resize(500,500);


}

MainWindow::~MainWindow()
{
    delete ui;
}

