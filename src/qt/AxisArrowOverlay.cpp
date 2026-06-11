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
#include <QResizeEvent>

// Half-width of the arrowhead chevron (pixels from tip to each arm end)
static const int ARROW = 6;

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
    p.setRenderHint(QPainter::Antialiasing, false);
    p.setPen(QPen(Qt::black, 1));

    QFont f = font();
    f.setPointSize(7);
    p.setFont(f);
    const QFontMetrics fm(f);
    const int lh = fm.height();

    const int xw = fm.horizontalAdvance("X") + 2;
    const int yw = fm.horizontalAdvance("Y") + 2;

    // Label positions in the outer margin, anchored to fd2's corners.
    // RIGHT margin: X labels — to the right of fd2.right()
    // LEFT  margin: Y labels — to the left  of fd2.left()
    const int rightX  = fd2.right() + 4;
    const int topY    = qMax(0, fd2.top() - lh);
    const int bottomY = fd2.bottom() - 1;
    const int leftX   = qMax(0, fd2.left() - yw - 3);

    // X arrowhead ">": tip at the right end of the axis border.
    // Not inverted: top border (origin top-left).  Inverted: bottom border.
    // Label "X" in the right-margin corner adjacent to the arrowhead.
    {
        const int yAxis = invertY ? fd2.bottom() : fd2.top();
        const QPoint tip(fd2.right(), yAxis);
        p.drawLine(tip, QPoint(tip.x() - ARROW, tip.y() - ARROW));
        p.drawLine(tip, QPoint(tip.x() - ARROW, tip.y() + ARROW));
        p.drawText(QRect(rightX, invertY ? bottomY : topY, xw, lh),
                   Qt::AlignLeft | Qt::AlignTop, "X");
    }

    // Y arrowhead "v"/"^": tip at the end of the left border.
    // Not inverted: bottom end, pointing down.  Inverted: top end, pointing up.
    // Label "Y" in the left-margin corner adjacent to the arrowhead.
    if (!invertY)
    {
        const QPoint tip(fd2.left(), fd2.bottom());
        p.drawLine(tip, QPoint(tip.x() - ARROW, tip.y() - ARROW));
        p.drawLine(tip, QPoint(tip.x() + ARROW, tip.y() - ARROW));
        p.drawText(QRect(leftX, bottomY, yw, lh),
                   Qt::AlignLeft | Qt::AlignTop, "Y");
    }
    else
    {
        const QPoint tip(fd2.left(), fd2.top());
        p.drawLine(tip, QPoint(tip.x() - ARROW, tip.y() + ARROW));
        p.drawLine(tip, QPoint(tip.x() + ARROW, tip.y() + ARROW));
        p.drawText(QRect(leftX, topY, yw, lh),
                   Qt::AlignLeft | Qt::AlignTop, "Y");
    }
}
