// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// This file is part of eProsima Fast DDS Shapes-Demo.
//
// eProsima Fast DDS Shapes-Demo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// eProsima Fast DDS Shapes-Demo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with eProsima Fast DDS Shapes-Demo. If not, see <https://www.gnu.org/licenses/>.

#include <eprosimashapesdemo/qt/DrawArea.h>

#include <eprosimashapesdemo/qt/ContentFilterSelector.h>
#include <eprosimashapesdemo/shapesdemo/ShapesDemo.h>

#include <eprosimashapesdemo/shapesdemo/ShapePublisher.h>
#include <eprosimashapesdemo/shapesdemo/ShapeSubscriber.h>

#include <QPainter>
#include <QStyleOption>
#include <QVBoxLayout>
#include <QSizeGrip>

DrawArea::DrawArea(
        QWidget* parent)
    : QWidget(parent)
    , m_isInitialized(false)
    , firstA(10)
    , lastA(240)
{
    this->setStyleSheet(
        "QWidget#areaDraw{background-color: rgb(255, 255, 255);background-repeat:none;background-image: url(:/eProsimaLogo.png);background-position:center;}");
    setVisible(true);
    m_brush.setStyle(Qt::SolidPattern);

    m_timerId = startTimer(50);
}

DrawArea::~DrawArea()
{

}

QSize DrawArea::sizeHint() const
{
    return QSize(MAX_DRAW_AREA_X, MAX_DRAW_AREA_Y);
}

QSize DrawArea::minimumSizeHint() const
{
    return QSize(MAX_DRAW_AREA_X, MAX_DRAW_AREA_Y);
}

void DrawArea::paintEvent(
        QPaintEvent* e /* event */)
{
    Q_UNUSED(e);
    QStyleOption opt;
    opt.init(this);

    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    drawShapes(&painter);
}

void DrawArea::addContentFilter(
        ShapeSubscriber* ssub)
{
    ContentFilterSelector* a = new ContentFilterSelector(this);
    a->assignShapeSubscriber(ssub);
    ssub->assignContentFilterPointer(a);
}

void DrawArea::timerEvent(
        QTimerEvent* e)
{
    Q_UNUSED(e);
    this->setStyleSheet(
        "QWidget#areaDraw{background-color: rgb(255, 255, 255);background-repeat:none;background-image: url(:/eProsimaLogo.png);background-position:center;}");
    repaint();
}

uint8_t DrawArea::getAlpha(
        int pos,
        size_t total)
{
    float inc = (lastA - firstA) / total;
    return (uint8_t)(firstA + inc * (pos + 1));
}

void DrawArea::drawShapes(
        QPainter* painter)
{
    if (m_isInitialized)
    {
        QMutexLocker lock(&mp_SD->m_mutex);
        for (std::vector<ShapeSubscriber*>::iterator it = mp_SD->m_subscribers.begin();
                it != mp_SD->m_subscribers.end(); ++it)
        {
            QMutexLocker lock2(&(*it)->m_mutex);
            if ((*it)->hasReceived)
            {
                // cout << "OK"<<std::flush;
                for (std::vector<std::list<Shape>>::iterator vit = (*it)->m_shapeHistory.m_history.begin();
                        vit != (*it)->m_shapeHistory.m_history.end(); ++vit)
                {
                    size_t total = vit->size();
                    int index = 0;
                    if (vit->begin()->m_writerGuid != rtps::c_Guid_Unknown)
                    {
                        for (std::list<Shape>::reverse_iterator sit = vit->rbegin();
                                sit != vit->rend(); ++sit)
                        {
                            paintShape(painter, *sit, getAlpha(index, total), true);
                            ++index;
                        }
                    }
                }
            }
        }
        for (std::vector<ShapePublisher*>::iterator it = mp_SD->m_publishers.begin();
                it != mp_SD->m_publishers.end(); ++it)
        {
            QMutexLocker lock2(&(*it)->m_mutex);
            if ((*it)->hasWritten)
            {
                paintShape(painter, (*it)->m_shape, 255);
            }
        }
    }
}

void DrawArea::paintShape(
        QPainter* painter,
        Shape& shape,
        uint8_t alpha,
        bool isHistory)
{
    painter->save();
    m_pen.setColor(SD_QT_BLACK);
    m_pen.setStyle(isHistory ? Qt::DotLine : Qt::SolidLine);
    painter->setPen(m_pen);
    QColor auxc = SD_QT_BLACK;
    if (shape.m_shape.color().size() >= 3)
    {
        auxc = SD_COLOR2QColor(getColor(shape.m_shape.color().at(0), shape.m_shape.color().at(2)));
    }
    auxc.setAlpha(alpha);
    m_brush.setColor(auxc);
    m_brush.setStyle(Qt::SolidPattern);
    painter->setBrush(m_brush);
    switch (shape.m_type)
    {
        case SQUARE:
        {
            QRect rect(shape.m_shape.x() - shape.m_shape.shapesize() / 2,
                    shape.m_shape.y() - shape.m_shape.shapesize() / 2,
                    shape.m_shape.shapesize(),
                    shape.m_shape.shapesize());
            painter->drawRect(rect);
            break;
        }
        case TRIANGLE:
        {
            uint32_t x, y, s;
            x = shape.m_shape.x();
            y = shape.m_shape.y();
            s = shape.m_shape.shapesize();
            //double h = 0.5*sqrt(3*pow((double)s,2));
            QPoint points[3] = {
                QPoint(x - s / 2, y + s / 2),
                QPoint(x + s / 2, y + s / 2),
                QPoint(x, y - s / 2)
            };
            painter->drawPolygon(points, 3);
            break;
        }
        case CIRCLE:
        {
            QRect rect(shape.m_shape.x() - shape.m_shape.shapesize() / 2,
                    shape.m_shape.y() - shape.m_shape.shapesize() / 2,
                    shape.m_shape.shapesize(),
                    shape.m_shape.shapesize());
            painter->drawEllipse(rect);
            break;
        }
    }
    painter->restore();

}

void DrawArea::setShapesDemo(
        ShapesDemo* SD)
{
    if (SD != NULL)
    {
        mp_SD = SD;
        m_isInitialized = true;
    }
}
