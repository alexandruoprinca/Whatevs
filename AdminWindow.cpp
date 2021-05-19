#include "AdminWindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include "Model.h"
#include <QDebug>

AdminWindow::AdminWindow(Controller& controller, QWidget *parent)
    : QWidget(parent)
    , controller{controller}
{

    qDebug() << "got here admin";

    group = new QGroupBox(this);
    layout = new QHBoxLayout{};

    listView = new QTableView(this);
    model = new Model{controller};
    listView->setModel(model);

    layout->addWidget(listView);
    layout->setSpacing(100);
    group ->setLayout(layout);
    group->resize(900,500);


}

