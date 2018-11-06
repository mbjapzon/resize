#ifndef SEQUENCEWIDGET_H
#define SEQUENCEWIDGET_H

#include <QGraphicsLayoutItem>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>

#include "testwidget.h"

class SequenceWidget : public QGraphicsWidget
{
public:
    //Constructor
    SequenceWidget(QGraphicsWidget* parent = nullptr);
    ~SequenceWidget() override;

    QList <TestWidget *> getChildrenTests()         { return m_childrenTests;}

protected:
    // Inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom) override;
    // Inherited from QGraphicsWidget
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // Inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;


private:
    QGraphicsLinearLayout * m_layout;
    QList <TestWidget *> m_childrenTests;

};

#endif // SEQUENCEWIDGET_H
