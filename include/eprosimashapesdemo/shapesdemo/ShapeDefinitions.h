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
enum TYPESHAPE{
    SQUARE,
    CIRCLE,
    TRIANGLE
};


/**
 * @brief getShapeQStr, get the type fo shape as a string.
 * @return QString.
 */
inline QString getShapeQStr(const TYPESHAPE shape)
{
    switch(shape)
    {
    case SQUARE: return "Square";
    case CIRCLE: return "Circle";
    case TRIANGLE: return "Triangle";
    }
    return "Square"; //Default to square if something unexpected happens
}

inline std::string getColorStr(const SD_COLOR color)
{
    switch(color)
    {
    case SD_PURPLE: return "PURPLE"; break;
    case SD_BLUE: return "BLUE";break;
    case SD_RED: return "RED";break;
    case SD_GREEN: return "GREEN";break;
    case SD_YELLOW: return "YELLOW";break;
    case SD_CYAN: return "CYAN";break;
    case SD_MAGENTA: return "MAGENTA";break;
    case SD_ORANGE: return "ORANGE";break;
    case SD_GRAY: return "GRAY"; break;
    case SD_BLACK: return "BLACK"; break;
    }
    return "BLACK";
}

inline SD_COLOR getColor(const unsigned char ch1, const unsigned char ch3)
{
    switch(ch1)
    {
    case 'P': return SD_PURPLE; break;
    case 'B':
    {
        if(ch3 == 'U'){  return SD_BLUE; break;}
        if(ch3 == 'A'){  return SD_BLACK; break;}
        return SD_BLACK;
    }
    case 'R': return SD_RED; break;
    case 'G':
    {
        if(ch3 == 'E') {return SD_GREEN; break;}
        if(ch3 == 'A') {return SD_GRAY; break;}
        return SD_BLACK;
    }
    case 'Y': return SD_YELLOW; break;
    case 'C': return SD_CYAN; break;
    case 'M': return SD_MAGENTA; break;
    case 'O': return SD_ORANGE; break;
    }
    return SD_BLACK;
}



#endif // SHAPEDEFINITIONS_H
