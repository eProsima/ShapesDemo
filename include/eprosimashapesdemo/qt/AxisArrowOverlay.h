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

#ifndef AXISARROWOVERLAY_H
#define AXISARROWOVERLAY_H

#include <QFrame>
#include <QWidget>

class ShapesDemo;

/**
 * @brief Full-size transparent overlay on the outer frame (frameDraw) that draws
 * arrowhead chevrons at the ends of the inner frame's (frameDraw2) axis border lines,
 * together with "X" / "Y" labels in the outer-margin corners.
 *
 * Not inverted (origin top-left):
 *   ">" tip at the top-right corner    (X axis →),  "X" label in the right margin
 *   "v" tip at the bottom-left corner  (Y axis ↓),  "Y" label in the left margin
 *
 * Inverted (origin bottom-left):
 *   ">" tip at the bottom-right corner (X axis →),  "X" label in the right margin
 *   "^" tip at the top-left corner     (Y axis ↑),  "Y" label in the left margin
 *
 * Polls ShapesDemoOptions::m_invertYAxis every 100 ms to react to option changes.
 */
class AxisArrowOverlay : public QWidget
{
    Q_OBJECT

public:

    AxisArrowOverlay(
            QWidget* parent,
            QFrame* innerFrame,
            ShapesDemo* sd);

protected:

    void paintEvent(
            QPaintEvent* e) override;

    void timerEvent(
            QTimerEvent* e) override;

    bool eventFilter(
            QObject* obj,
            QEvent* e) override;

private:

    QFrame* mp_fd2;
    ShapesDemo* mp_sd;
    int m_timerId;
};

#endif // AXISARROWOVERLAY_H
