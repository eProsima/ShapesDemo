// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
class ContentFilterSelector: public QWidget
{
    // Q_OBJECT
public:
    ContentFilterSelector(QWidget* parent=0);
    virtual ~ContentFilterSelector();

    //    QSize minimumSizeHint() const;
    //    QSize sizeHint() const;

    void assignShapeSubscriber(ShapeSubscriber* ssub);
protected:


private:


public slots:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent *event);
private:
    QPen m_pen;
    QBrush m_brush;
    QPoint offset;
    int m_size_x;
    int m_size_y;
    bool m_moveFilter;
    bool m_resizeFilter;
    SD_CONTENTCORNER getCorner(QMouseEvent* event);
    QFrame* m_frame;
    SD_CONTENTCORNER m_corner;
    ShapeSubscriber* mp_ssub;

    void contentFilterChanged();



};


#endif // CONTENTFILTERSELECTOR_H
