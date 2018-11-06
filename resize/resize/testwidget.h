#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QGraphicsLayoutItem>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>


class TestWidget : public QGraphicsWidget
{
public:
    //Constructor
    TestWidget(QGraphicsWidget* parent = nullptr);
    ~TestWidget() override;

    // Inherited from QGraphicsWidget
    void setGeometry(const QRectF &geom) override;
    // Inherited from QGraphicsWidget
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // Inherited from QGraphicsWidget
    QRectF boundingRect() const override;

    //Inherited Function that is responsible for painting items such
    //as text, arrows, and borders.  Proxy Widgets such as buttons,
    //tool bar, and web views are added in populateTestSubWidgets
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;


private:
    QGraphicsLinearLayout * m_layout;

};

#endif // TESTWIDGET_H
