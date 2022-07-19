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

/*!
 * @file Shape.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _SHAPEINFO_H_
#define _SHAPEINFO_H_

#include <fastrtps/rtps/common/Time_t.h>
#include <fastrtps/rtps/common/Guid.h>
#include <fastrtps/rtps/common/InstanceHandle.h>

#include <cstdint>
#include <sstream>
#include <QString>

#include "eprosimashapesdemo/shapesdemo/ShapeDefinitions.h"
#include "eprosimashapesdemo/shapesdemo/ShapePubSubTypes.h"

using namespace eprosima::fastrtps;

class Shape
{
public:

    Shape()
        : m_dirX(0)
        , m_dirY(0)
        , m_changeDir(true)
        , m_max_speed_variance(0.1f)
    {
    }

    virtual ~Shape()
    {
    }

    void define(
            SD_COLOR color = SD_BLUE,
            uint32_t x = 30,
            uint32_t y = 30,
            uint32_t size = 30)
    {
        m_shape.color(getColorStr(color));
        m_shape.x(x);
        m_shape.y(y);
        m_shape.shapesize(size);
    }

    ShapeType m_shape;
    TYPESHAPE m_type;
    Time_t m_time;
    float m_dirX;
    float m_dirY;
    bool m_changeDir;
    float m_max_speed_variance;
};

typedef std::pair<SD_COLOR, rtps::InstanceHandle_t> colorPair;

class ColorInstanceHandle
{
public:

    colorPair PurpleIH;
    colorPair BlueIH;
    colorPair RedIH;
    colorPair GreenIH;
    colorPair YellowIH;
    colorPair CyanIH;
    colorPair MagentaIH;
    colorPair OrangeIH;
    colorPair GrayIH;
    colorPair BlackIH;
    ShapeTypePubSubType m_topic;
    ColorInstanceHandle()
    {
        Shape shape;
        shape.define(SD_PURPLE);
        m_topic.getKey((void*)&shape.m_shape, &PurpleIH.second);
        shape.define(SD_BLUE);
        m_topic.getKey((void*)&shape.m_shape, &BlueIH.second);
        shape.define(SD_RED);
        m_topic.getKey((void*)&shape.m_shape, &RedIH.second);
        shape.define(SD_GREEN);
        m_topic.getKey((void*)&shape.m_shape, &GreenIH.second);
        shape.define(SD_YELLOW);
        m_topic.getKey((void*)&shape.m_shape, &YellowIH.second);
        shape.define(SD_CYAN);
        m_topic.getKey((void*)&shape.m_shape, &CyanIH.second);
        shape.define(SD_MAGENTA);
        m_topic.getKey((void*)&shape.m_shape, &MagentaIH.second);
        shape.define(SD_ORANGE);
        m_topic.getKey((void*)&shape.m_shape, &OrangeIH.second);
        shape.define(SD_GRAY);
        m_topic.getKey((void*)&shape.m_shape, &GrayIH.second);
        shape.define(SD_BLACK);
        m_topic.getKey((void*)&shape.m_shape, &BlackIH.second);
        //        cout << PurpleIH.second << endl;
        //        cout << BlueIH.second << endl;
        //        cout << RedIH.second<<endl;
    }

    ~ColorInstanceHandle()
    {

    }

};


const ColorInstanceHandle c_ShapesHandles;


inline SD_COLOR getColorFromInstanceHandle(
        rtps::InstanceHandle_t& iHandle)
{
    if (iHandle == c_ShapesHandles.BlueIH.second)
    {
        return SD_BLUE;
    }
    if (iHandle == c_ShapesHandles.PurpleIH.second)
    {
        return SD_PURPLE;
    }
    if (iHandle == c_ShapesHandles.RedIH.second)
    {
        return SD_RED;
    }
    if (iHandle == c_ShapesHandles.MagentaIH.second)
    {
        return SD_MAGENTA;
    }
    if (iHandle == c_ShapesHandles.OrangeIH.second)
    {
        return SD_ORANGE;
    }
    if (iHandle == c_ShapesHandles.YellowIH.second)
    {
        return SD_YELLOW;
    }
    if (iHandle == c_ShapesHandles.GreenIH.second)
    {
        return SD_GREEN;
    }
    if (iHandle == c_ShapesHandles.CyanIH.second)
    {
        return SD_CYAN;
    }
    if (iHandle == c_ShapesHandles.GrayIH.second)
    {
        return SD_GRAY;
    }
    return SD_BLACK;
}

#endif // _SHAPEINFO_H_
