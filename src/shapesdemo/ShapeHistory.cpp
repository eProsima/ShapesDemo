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

#include <cmath>

#include <fastdds/rtps/common/Guid.h>
#include <fastdds/rtps/common/Time_t.h>

#include <eprosimashapesdemo/shapesdemo/ShapeHistory.h>

using namespace eprosima::fastdds::rtps;

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

inline double Time_tAbsDiff2DoubleMillisec(
        const eprosima::fastdds::Time_t& t1,
        const eprosima::fastdds::Time_t& t2)
{
    double result = 0;
    result += (double)abs((t2.seconds - t1.seconds) * 1000);
    result += (double)std::abs((t2.fraction() - t1.fraction()) / pow(2.0, 32) * 1000);
    return result;
}

inline double Time_t2MilliSecondsDouble(
        const eprosima::fastdds::Time_t& t)
{
    return ((double)t.fraction() / pow(2.0, 32) * pow(10.0, 3)) + (double)t.seconds * pow(10.0, 3);
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
        if (Time_tAbsDiff2DoubleMillisec(sh_in.m_time, sh_last.m_time)
                >= Time_t2MilliSecondsDouble(m_filter.m_minimumSeparation))
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
            it->front().dispose = true;
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
