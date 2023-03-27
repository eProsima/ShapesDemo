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

#ifndef SHAPEDEFINITIONS_H
#define SHAPEDEFINITIONS_H

#define MAX_DRAW_AREA_X 235
#define MAX_DRAW_AREA_Y 265
#define INITIAL_INTERVAL_MS 75

#include <qstring.h>

/**
 * @brief The SD_COLOR enum, the different colors.
 */
enum SD_COLOR
{
    SD_PURPLE,
    SD_BLUE,
    SD_RED,
    SD_GREEN,
    SD_YELLOW,
    SD_CYAN,
    SD_MAGENTA,
    SD_ORANGE,
    SD_GRAY,
    SD_BLACK
};
/**
 * @brief The TYPESHAPE enum, the different shapes.
 */
enum TYPESHAPE
{
    SQUARE,
    CIRCLE,
    TRIANGLE
};


/**
 * @brief getShapeQStr, get the type fo shape as a string.
 * @return QString.
 */
inline QString getShapeQStr(
        const TYPESHAPE shape)
{
    switch (shape)
    {
        case SQUARE: return "Square";
        case CIRCLE: return "Circle";
        case TRIANGLE: return "Triangle";
    }
    return "Square"; //Default to square if something unexpected happens
}

inline std::string getColorStr(
        const SD_COLOR color)
{
    switch (color)
    {
        case SD_PURPLE: return "PURPLE"; break;
        case SD_BLUE: return "BLUE"; break;
        case SD_RED: return "RED"; break;
        case SD_GREEN: return "GREEN"; break;
        case SD_YELLOW: return "YELLOW"; break;
        case SD_CYAN: return "CYAN"; break;
        case SD_MAGENTA: return "MAGENTA"; break;
        case SD_ORANGE: return "ORANGE"; break;
        case SD_GRAY: return "GRAY"; break;
        case SD_BLACK: return "BLACK"; break;
    }
    return "BLACK";
}

inline SD_COLOR getColor(
        const unsigned char ch1,
        const unsigned char ch3)
{
    switch (ch1)
    {
        case 'P': return SD_PURPLE; break;
        case 'B':
        {
            if (ch3 == 'U')
            {
                return SD_BLUE; break;
            }
            if (ch3 == 'A')
            {
                return SD_BLACK; break;
            }
            return SD_BLACK;
        }
        case 'R': return SD_RED; break;
        case 'G':
        {
            if (ch3 == 'E')
            {
                return SD_GREEN; break;
            }
            if (ch3 == 'A')
            {
                return SD_GRAY; break;
            }
            return SD_BLACK;
        }
        case 'Y': return SD_YELLOW; break;
        case 'C': return SD_CYAN; break;
        case 'M': return SD_MAGENTA; break;
        case 'O': return SD_ORANGE; break;
    }
    return SD_BLACK;
}

#ifdef ENABLE_ROS_COMPONENTS
    constexpr const char* const ROS_2_ENVIRONMENT_VAR = "ROS_DISTRO";
#endif // ifdef ENABLE_ROS_COMPONENTS

#endif // SHAPEDEFINITIONS_H
