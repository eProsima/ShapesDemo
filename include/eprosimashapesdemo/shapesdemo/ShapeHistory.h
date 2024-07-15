// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef SHAPEHISTORY_H
#define SHAPEHISTORY_H

#include <cstdint>
#include <vector>
#include <list>

#include "eprosimashapesdemo/shapesdemo/ShapeInfo.h"

/**
 * @brief The ShapeFilter class, represents a filter.
 */
class ShapeFilter
{
public:

    ShapeFilter()
        : m_maxX(MAX_DRAW_AREA_X)
        , m_minX(0)
        , m_maxY(MAX_DRAW_AREA_Y)
        , m_minY(0)
        , m_useContentFilter(false)
        , m_useTimeFilter(false)
    {

    }

    ~ShapeFilter()
    {
    }

    int32_t m_maxX;
    int32_t m_minX;
    int32_t m_maxY;
    int32_t m_minY;
    eprosima::fastdds::dds::Duration_t m_minimumSeparation;
    bool m_useContentFilter;
    bool m_useTimeFilter;

};



class ShapeHistory
{
public:

    ShapeHistory()
        : m_history_depth(0)
    {
    }

    virtual ~ShapeHistory()
    {
    }

    std::vector<std::list<Shape>> m_history;
    bool addToHistory(
            Shape& sh);

private:

    bool findInstance(
            Shape& sh,
            std::vector<std::list<Shape>>::iterator* it);
    void addNewInstance(
            Shape& sh);
    bool passContentFilter(
            Shape& sh);
    bool passTimeFilter(
            Shape& sh_in,
            Shape& sh_last);
    void addShapeToList(
            Shape& sh,
            std::list<Shape>& list);
    void addShape(
            Shape& sh,
            std::list<Shape>& list);
    void addShapeExclusive(
            Shape& sh,
            std::list<Shape>& list);

public:

    void dispose(
            const SD_COLOR color);
    void unregister(
            const SD_COLOR color);
    void adjustContentFilter(
            ShapeFilter& filter);

    uint32_t m_history_depth;
    ShapeFilter m_filter;
};

#endif // SHAPEHISTORY_H
