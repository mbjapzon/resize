#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>

static int count = 0;

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

    int i = 0;

    foreach(TestWidget * test, m_sequence->getChildrenTests())
    {
        //Increase the first TestWidget by a height of 100
        if(i ==0)
        {
            QRectF testGeometry = test->geometry();
            testGeometry.setHeight(testGeometry.height() + 100);
            test->setGeometry(testGeometry);
        }
        else
        {
            //Adjust the y coordinate of the subsequence tests by 100
            QRectF testGeometry = test->geometry();
            testGeometry.adjust(0, 100, 0, 0);
            test->setGeometry(testGeometry);
        }
        i++;

    }

    //Increase the height of the sequence by 100
    QRectF sequenceGeometry = m_sequence->geometry();
    sequenceGeometry.setHeight(sequenceGeometry.height() + 100);
    m_sequence->setGeometry(sequenceGeometry);

}
