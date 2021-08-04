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

#ifndef CONTENTFILTERSELECTOR_H
#define CONTENTFILTERSELECTOR_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include <QTimer>

enum SD_CONTENTCORNER
{
    SD_OUTSIDE,
    SD_CENTER,
    SD_TOPLEFT,
    SD_TOPRIGHT,
    SD_BOTTOMLEFT,
    SD_BOTTOMRIGHT
};

class QFrame;
class ShapeSubscriber;

/**
 * @brief Class ContentFilterSelector, implements content filter selector.
 */
class ContentFilterSelector : public QWidget
{
    // Q_OBJECT

public:

    ContentFilterSelector(
            QWidget* parent = 0);
    virtual ~ContentFilterSelector();

    //    QSize minimumSizeHint() const;
    //    QSize sizeHint() const;

    void assignShapeSubscriber(
            ShapeSubscriber* ssub);

protected:

private:

public slots:

    void mousePressEvent(
            QMouseEvent* event);
    void mouseMoveEvent(
            QMouseEvent* event);
    void mouseReleaseEvent(
            QMouseEvent* event);
    void paintEvent(
            QPaintEvent* event);

private:

    QPen m_pen;
    QBrush m_brush;
    QPoint offset;
    int m_size_x;
    int m_size_y;
    bool m_moveFilter;
    bool m_resizeFilter;
    SD_CONTENTCORNER getCorner(
            QMouseEvent* event);
    QFrame* m_frame;
    SD_CONTENTCORNER m_corner;
    ShapeSubscriber* mp_ssub;

    void contentFilterChanged();



};


#endif // CONTENTFILTERSELECTOR_H
