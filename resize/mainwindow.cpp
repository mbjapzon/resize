#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);
    m_sequence = new SequenceWidget();
    ui->graphicsView->setScene(m_scene);
    m_scene->addItem(m_sequence);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //TODO resize the test widgets
}
