#include "TestWidget.h"

#include <QGradient>
#include <QGraphicsLinearLayout>
#include <QPainter>

TestWidget::TestWidget(QGraphicsWidget *parent)
    : QGraphicsWidget(parent)
  {
    Q_UNUSED(parent);


    m_layout = new QGraphicsLinearLayout(Qt::Vertical);
    m_layout->setContentsMargins(30, 30, 30, 30);

    QGraphicsLayoutItem::setGraphicsItem(this);
    QGraphicsWidget::setLayout(m_layout);
}

TestWidget::~TestWidget()
{

}

void TestWidget::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0*/)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    //Draw border
    painter->drawRoundedRect(boundingRect(), 5.0, 5.0);


}

QRectF TestWidget::boundingRect() const
{
    return QRectF(QPointF(0,0), QGraphicsLayoutItem::geometry().size());
}

void TestWidget::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF TestWidget::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        // Do not allow a size smaller than the pixmap with two frames around it.
        return QSizeF(100, 100);
    default:
        break;
    }
    return constraint;
}
