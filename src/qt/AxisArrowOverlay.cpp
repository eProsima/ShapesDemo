// Copyright 2026 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// This file is part of eProsima Fast DDS Shapes Demo.
//
// eProsima Fast DDS Shapes Demo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// eProsima Fast DDS Shapes Demo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with eProsima Fast DDS Shapes Demo. If not, see <https://www.gnu.org/licenses/>.

#include <eprosimashapesdemo/qt/AxisArrowOverlay.h>
#include <eprosimashapesdemo/shapesdemo/ShapesDemo.h>

#include <QEvent>
#include <QFont>
#include <QFontMetrics>
#include <QPainter>
#include <QPen>
#include <QPolygon>
#include <QResizeEvent>

// Filled-triangle arrowhead dimensions
static const int TRI_LEN  = 5;   // tip to base (along the axis)
static const int TRI_HALF = 4;   // base half-width (perpendicular to axis)
// Origin dot radius
static const int DOT_R    = 2;

AxisArrowOverlay::AxisArrowOverlay(
        QWidget* parent,
        QFrame* innerFrame,
        ShapesDemo* sd)
    : QWidget(parent)
    , mp_fd2(innerFrame)
    , mp_sd(sd)
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    // Do not fill the background — the parent's composited content shows through
    // everywhere we do not explicitly paint, making this overlay truly transparent.
    setAttribute(Qt::WA_NoSystemBackground);
    setAutoFillBackground(false);

    setGeometry(parent->rect());
    parent->installEventFilter(this);

    m_timerId = startTimer(100);
}

bool AxisArrowOverlay::eventFilter(
        QObject* obj,
        QEvent* e)
{
    if (obj == parent() && e->type() == QEvent::Resize)
    {
        resize(static_cast<QResizeEvent*>(e)->size());
        update();
    }
    return QWidget::eventFilter(obj, e);
}

void AxisArrowOverlay::timerEvent(
        QTimerEvent*)
{
    update();
}

void AxisArrowOverlay::paintEvent(
        QPaintEvent*)
{
    if (!mp_fd2)
    {
        return;
    }

    bool invertY = mp_sd ? mp_sd->getOptions().m_invertYAxis : false;
    const QRect fd2 = mp_fd2->geometry();

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    QFont f = font();
    f.setPointSize(7);
    p.setFont(f);
    const QFontMetrics fm(f);
    const int lh = fm.height();

    const int xw = fm.horizontalAdvance("X") + 2;
    const int yw = fm.horizontalAdvance("Y") + 2;

    // Label corner positions in the outer margin, anchored to fd2's corners.
    const int rightX  = fd2.right() + 4;
    const int topY    = qMax(0, fd2.top() - lh);
    const int bottomY = fd2.bottom() - 1;
    const int leftX   = qMax(0, fd2.left() - yw - 3);

    // Draw filled shapes (no outline)
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);

    // Origin dot at the corner where both axes meet.
    // Not inverted: top-left corner.  Inverted: bottom-left corner.
    const QPoint origin(fd2.left() + 1, invertY ? fd2.bottom() : fd2.top() + 1);
    p.drawEllipse(origin, DOT_R, DOT_R);

    // X arrowhead: right-pointing filled triangle, tip 1px past fd2's right border.
    // Not inverted: aligned with the top border.  Inverted: with the bottom border.
    {
        const int xTip  = fd2.right() + 1;
        const int yAxis = invertY ? fd2.bottom() : fd2.top();
        QPolygon tri;
        tri << QPoint(xTip,           yAxis)
            << QPoint(xTip - TRI_LEN, yAxis - TRI_HALF)
            << QPoint(xTip - TRI_LEN, yAxis + TRI_HALF);
        p.drawPolygon(tri);
    }

    // Y arrowhead: down/up-pointing filled triangle, tip 1px inside fd2's left border.
    // Not inverted: aligned with the bottom border.  Inverted: with the top border.
    {
        const int xTip = fd2.left() + 1;
        if (!invertY)
        {
            QPolygon tri;
            tri << QPoint(xTip,            fd2.bottom())
                << QPoint(xTip - TRI_HALF, fd2.bottom() - TRI_LEN)
                << QPoint(xTip + TRI_HALF, fd2.bottom() - TRI_LEN);
            p.drawPolygon(tri);
        }
        else
        {
            QPolygon tri;
            tri << QPoint(xTip,            fd2.top())
                << QPoint(xTip - TRI_HALF, fd2.top() + TRI_LEN)
                << QPoint(xTip + TRI_HALF, fd2.top() + TRI_LEN);
            p.drawPolygon(tri);
        }
    }

    // Axis labels
    p.setPen(Qt::black);
    p.drawText(QRect(rightX, invertY ? bottomY : topY, xw, lh),
               Qt::AlignLeft | Qt::AlignTop, "X");
    p.drawText(QRect(leftX, invertY ? topY : bottomY, yw, lh),
               Qt::AlignLeft | Qt::AlignTop, "Y");
}
