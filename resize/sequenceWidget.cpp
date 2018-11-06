#include "sequenceWidget.h"
#include "testwidget.h"

#include <QGradient>
#include <QGraphicsLinearLayout>
#include <QPainter>

SequenceWidget::SequenceWidget(QGraphicsWidget* parent)
{
    Q_UNUSED(parent);

    m_layout = new QGraphicsLinearLayout(Qt::Vertical, this);
    m_layout->setContentsMargins(30, 30, 30, 30);

    TestWidget * one = new TestWidget(this);
    TestWidget * two = new TestWidget(this);

    QGraphicsLayoutItem::setGraphicsItem(this);
    QGraphicsWidget::setLayout(m_layout);

    m_layout->addItem(one);
    m_childrenTests.append(one);
    m_layout->addItem(two);
    m_childrenTests.append(two);
}


SequenceWidget::~SequenceWidget()
{

}

void SequenceWidget::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0*/)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    //Draw border
    painter->drawRoundedRect(boundingRect(), 5.0, 5.0);
}

QRectF SequenceWidget::boundingRect() const
{
    return QRectF(QPointF(0,0), QGraphicsLayoutItem::geometry().size());
}

void SequenceWidget::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF SequenceWidget::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        // Do not allow a size smaller than the pixmap with two frames around it.
        return QSizeF(300, 300);
    default:
        break;
    }
    return constraint;
}
