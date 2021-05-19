#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include "Model.h"
#include <QDebug>
#include "ClientWindow.h"
#include "AdminWindow.h"
#include "Repository.h"
#include "Controller.h"
#include "FileManager.h"
#include "CSVFileManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    qDebug() << "got here";
    ui->setupUi(this);

    group = new QGroupBox(this);
    layout = new QHBoxLayout{};

    client_button = new QPushButton(this);
    client_button->setText(tr("client"));
    connect(client_button, SIGNAL(clicked()), this, SLOT(connected_client()));
    admin_button = new QPushButton(this);
    admin_button->setText(tr("admin"));
    connect(admin_button, SIGNAL(clicked()), this, SLOT(connected_admin()));


    layout->addWidget(client_button);
    layout->addWidget(admin_button);
    layout->setSpacing(100);
    group ->setLayout(layout);
    group->resize(500,500);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connected_client()
{
    if(window == nullptr)
        window = new ClientWindow{};
    window->show();
    this->hide();
}

void MainWindow::connected_admin()
{
    if(window == nullptr){
        FileManager* fileManger = new CSVFileManager{"Filename.csv"};
        Repository* repository = new Repository{*fileManger};
        Controller* controller = new Controller{*repository};
        window = new AdminWindow{*controller};
    }
    window->show();
    this->hide();
}

