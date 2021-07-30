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

#ifndef SHAPEHISTORY_H
#define SHAPEHISTORY_H

#include "ShapeInfo.h"
#include <vector>
#include <list>
#include <cstdint>

/**
 * @brief The ShapeFilter class, represents a filter.
 */
class ShapeFilter
{
public:
    ShapeFilter(): m_maxX(MAX_DRAW_AREA_X),m_minX(0),m_maxY(MAX_DRAW_AREA_Y),m_minY(0),
        m_useContentFilter(false),m_useTimeFilter(false)
    {

    }
   ~ShapeFilter(){}
    int32_t m_maxX;
    int32_t m_minX;
    int32_t m_maxY;
    int32_t m_minY;
    Duration_t m_minimumSeparation;
    bool m_useContentFilter;
    bool m_useTimeFilter;

};



class ShapeHistory
{
public:
    ShapeHistory():m_history_depth(0),m_isExclusiveOwnership(false){}
    virtual ~ShapeHistory(){}
    std::vector<std::list<Shape>> m_history;
    bool addToHistory(Shape& sh);
private:

    bool findInstance(Shape& sh,std::vector<std::list<Shape>>::iterator* it);
    void addNewInstance(Shape& sh);
    bool passContentFilter(Shape& sh);
    bool passTimeFilter(Shape& sh_in, Shape& sh_last);
    void addShapeToList(Shape&sh,std::list<Shape>& list);
    void addShape(Shape& sh,std::list<Shape>& list);
    void addShapeExclusive(Shape& sh,std::list<Shape>& list);
public:
    void dispose(const SD_COLOR color);
    void unregister(const SD_COLOR color);
    void adjustContentFilter(ShapeFilter& filter);
    void removedOwner(rtps::GUID_t& guid);

    uint32_t m_history_depth;
    ShapeFilter m_filter;
    bool m_isExclusiveOwnership;
};

#endif // SHAPEHISTORY_H
