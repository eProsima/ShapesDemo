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

#include <eprosimashapesdemo/shapesdemo/ShapeHistory.h>
#include <fastrtps/utils/TimeConversion.h>

using namespace eprosima::fastrtps::rtps;

inline bool compareGUID(
        GUID_t& g1,
        GUID_t& g2)
{
    for (uint8_t i = 0; i < 16; ++i)
    {
        if (i < 12)
        {
            if (g1.guidPrefix.value[i] < g2.guidPrefix.value[i])
            {
                return true;
            }
            else if (g1.guidPrefix.value[i] > g2.guidPrefix.value[i])
            {
                return false;
            }
        }
        else
        {
            if (g1.entityId.value[i - 12] < g2.entityId.value[i - 12])
            {
                return true;
            }
            else if (g1.entityId.value[i - 12] > g2.entityId.value[i - 12])
            {
                return false;
            }
        }
    }
    return false;
}

bool ShapeHistory::addToHistory(
        Shape& sh)
{
    if (passContentFilter(sh))
    {
        std::vector<std::list<Shape>>::iterator it;
        if (findInstance(sh, &it))
        {
            addShapeToList(sh, *it);
        }
        else
        {
            addNewInstance(sh);
        }
        return true;
    }
    return false;
}

void ShapeHistory::addShapeToList(
        Shape& sh,
        std::list<Shape>& list)
{
    if (passTimeFilter(sh, list.front()))
    {
        if (this->m_isExclusiveOwnership)
        {
            addShapeExclusive(sh, list);
        }
        else
        {
            addShape(sh, list);
        }
    }
}

void ShapeHistory::addShapeExclusive(
        Shape& sh,
        std::list<Shape>& list)
{
    if (sh.m_strength > list.front().m_strength || list.front().m_hasOwner == false)
    {
        list.pop_front();
        addShape(sh, list);
    }
    else if (sh.m_strength == list.front().m_strength && sh.m_writerGuid == list.front().m_writerGuid )
    {
        addShape(sh, list);
    }
    else if (sh.m_strength == list.front().m_strength &&
            compareGUID(sh.m_writerGuid, list.front().m_writerGuid))
    {
        addShape(sh, list);
    }
}

void ShapeHistory::addShape(
        Shape& sh,
        std::list<Shape>& list)
{
    if (list.size() + 1 > this->m_history_depth)
    {
        list.pop_back();
    }
    list.push_front(sh);
}

bool ShapeHistory::passTimeFilter(
        Shape& sh_in,
        Shape& sh_last)
{
    if (!m_filter.m_useTimeFilter)
    {
        return true;
    }
    else
    {
        if (TimeConv::Time_tAbsDiff2DoubleMillisec(sh_in.m_time, sh_last.m_time)
                >= TimeConv::Time_t2MilliSecondsDouble(m_filter.m_minimumSeparation))
        {
            return true;
        }
    }
    return false;
}

bool ShapeHistory::findInstance(
        Shape& sh,
        std::vector<std::list<Shape>>::iterator* out_it)
{
    for (std::vector<std::list<Shape>>::iterator it = m_history.begin();
            it != m_history.end(); ++it)
    {
        if (it->front().m_shape.color() == sh.m_shape.color())
        {
            *out_it = it;
            return true;
        }
    }
    return false;
}

void ShapeHistory::addNewInstance(
        Shape& sh)
{
    std::list<Shape> shapelist;
    shapelist.push_back(sh);
    m_history.push_back(shapelist);
}

bool ShapeHistory::passContentFilter(
        Shape& sh)
{
    if (!m_filter.m_useContentFilter)
    {
        return true;
    }
    else
    {
        if (sh.m_shape.x() < m_filter.m_maxX &&
                sh.m_shape.x() > m_filter.m_minX &&
                sh.m_shape.y() < m_filter.m_maxY &&
                sh.m_shape.y() > m_filter.m_minY)
        {
            // cout << "FILTER PASSED"<<endl;
            return true;
        }
    }
    return false;
}

void ShapeHistory::dispose(
        const SD_COLOR color)
{
    for (std::vector<std::list<Shape>>::iterator it = m_history.begin();
            it != m_history.end(); ++it)
    {
        if (it->front().m_shape.color() == getColorStr(color))
        {
            it->front().m_hasOwner = false;
            return;
        }
    }
    return;
}

void ShapeHistory::unregister(
        const SD_COLOR color)
{
    for (std::vector<std::list<Shape>>::iterator it = m_history.begin();
            it != m_history.end(); ++it)
    {
        if (it->front().m_shape.color() == getColorStr(color))
        {
            m_history.erase(it);
            return;
        }
    }
    return;
}

void ShapeHistory::adjustContentFilter(
        ShapeFilter& filter)
{
    if (m_filter.m_useContentFilter)
    {
        m_filter.m_maxX = filter.m_maxX;
        m_filter.m_maxY = filter.m_maxY;
        m_filter.m_minX = filter.m_minX;
        m_filter.m_minY = filter.m_minY;
    }
}

void ShapeHistory::removedOwner(
        const GUID_t& guid)
{
    for (std::vector<std::list<Shape>>::iterator it = m_history.begin();
            it != m_history.end(); ++it)
    {
        if (it->front().m_writerGuid == guid)
        {
            it->front().m_hasOwner = false;
            return;
        }
    }
    return;
}
