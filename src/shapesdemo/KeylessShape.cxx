// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*!
 * @file KeylessShape.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "eprosimashapesdemo/shapesdemo/KeylessShape.h"
#include "eprosimashapesdemo/shapesdemo/KeylessShapeTypeObject.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

shapes_demo_typesupport::idl::KeylessShapeType::KeylessShapeType()
{
    // m_color com.eprosima.idl.parser.typecode.StringTypeCode@3a883ce7
    m_color ="";
    // m_x com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4973813a
    m_x = 0;
    // m_y com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6321e813
    m_y = 0;
    // m_shapesize com.eprosima.idl.parser.typecode.PrimitiveTypeCode@79be0360
    m_shapesize = 0;

    // Just to register all known types
    registerKeylessShapeTypes();
}

shapes_demo_typesupport::idl::KeylessShapeType::~KeylessShapeType()
{




}

shapes_demo_typesupport::idl::KeylessShapeType::KeylessShapeType(
        const KeylessShapeType& x)
{
    m_color = x.m_color;
    m_x = x.m_x;
    m_y = x.m_y;
    m_shapesize = x.m_shapesize;
}

shapes_demo_typesupport::idl::KeylessShapeType::KeylessShapeType(
        KeylessShapeType&& x)
{
    m_color = std::move(x.m_color);
    m_x = x.m_x;
    m_y = x.m_y;
    m_shapesize = x.m_shapesize;
}

shapes_demo_typesupport::idl::KeylessShapeType& shapes_demo_typesupport::idl::KeylessShapeType::operator =(
        const KeylessShapeType& x)
{

    m_color = x.m_color;
    m_x = x.m_x;
    m_y = x.m_y;
    m_shapesize = x.m_shapesize;

    return *this;
}

shapes_demo_typesupport::idl::KeylessShapeType& shapes_demo_typesupport::idl::KeylessShapeType::operator =(
        KeylessShapeType&& x)
{

    m_color = std::move(x.m_color);
    m_x = x.m_x;
    m_y = x.m_y;
    m_shapesize = x.m_shapesize;

    return *this;
}

bool shapes_demo_typesupport::idl::KeylessShapeType::operator ==(
        const KeylessShapeType& x) const
{

    return (m_color == x.m_color && m_x == x.m_x && m_y == x.m_y && m_shapesize == x.m_shapesize);
}

bool shapes_demo_typesupport::idl::KeylessShapeType::operator !=(
        const KeylessShapeType& x) const
{
    return !(*this == x);
}

size_t shapes_demo_typesupport::idl::KeylessShapeType::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t shapes_demo_typesupport::idl::KeylessShapeType::getCdrSerializedSize(
        const shapes_demo_typesupport::idl::KeylessShapeType& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.color().size() + 1;

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

void shapes_demo_typesupport::idl::KeylessShapeType::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_color;
    scdr << m_x;
    scdr << m_y;
    scdr << m_shapesize;

}

void shapes_demo_typesupport::idl::KeylessShapeType::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_color;
    dcdr >> m_x;
    dcdr >> m_y;
    dcdr >> m_shapesize;
}

/*!
 * @brief This function copies the value in member color
 * @param _color New value to be copied in member color
 */
void shapes_demo_typesupport::idl::KeylessShapeType::color(
        const std::string& _color)
{
    m_color = _color;
}

/*!
 * @brief This function moves the value in member color
 * @param _color New value to be moved in member color
 */
void shapes_demo_typesupport::idl::KeylessShapeType::color(
        std::string&& _color)
{
    m_color = std::move(_color);
}

/*!
 * @brief This function returns a constant reference to member color
 * @return Constant reference to member color
 */
const std::string& shapes_demo_typesupport::idl::KeylessShapeType::color() const
{
    return m_color;
}

/*!
 * @brief This function returns a reference to member color
 * @return Reference to member color
 */
std::string& shapes_demo_typesupport::idl::KeylessShapeType::color()
{
    return m_color;
}
/*!
 * @brief This function sets a value in member x
 * @param _x New value for member x
 */
void shapes_demo_typesupport::idl::KeylessShapeType::x(
        int32_t _x)
{
    m_x = _x;
}

/*!
 * @brief This function returns the value of member x
 * @return Value of member x
 */
int32_t shapes_demo_typesupport::idl::KeylessShapeType::x() const
{
    return m_x;
}

/*!
 * @brief This function returns a reference to member x
 * @return Reference to member x
 */
int32_t& shapes_demo_typesupport::idl::KeylessShapeType::x()
{
    return m_x;
}

/*!
 * @brief This function sets a value in member y
 * @param _y New value for member y
 */
void shapes_demo_typesupport::idl::KeylessShapeType::y(
        int32_t _y)
{
    m_y = _y;
}

/*!
 * @brief This function returns the value of member y
 * @return Value of member y
 */
int32_t shapes_demo_typesupport::idl::KeylessShapeType::y() const
{
    return m_y;
}

/*!
 * @brief This function returns a reference to member y
 * @return Reference to member y
 */
int32_t& shapes_demo_typesupport::idl::KeylessShapeType::y()
{
    return m_y;
}

/*!
 * @brief This function sets a value in member shapesize
 * @param _shapesize New value for member shapesize
 */
void shapes_demo_typesupport::idl::KeylessShapeType::shapesize(
        int32_t _shapesize)
{
    m_shapesize = _shapesize;
}

/*!
 * @brief This function returns the value of member shapesize
 * @return Value of member shapesize
 */
int32_t shapes_demo_typesupport::idl::KeylessShapeType::shapesize() const
{
    return m_shapesize;
}

/*!
 * @brief This function returns a reference to member shapesize
 * @return Reference to member shapesize
 */
int32_t& shapes_demo_typesupport::idl::KeylessShapeType::shapesize()
{
    return m_shapesize;
}


size_t shapes_demo_typesupport::idl::KeylessShapeType::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;







    return current_align;
}

bool shapes_demo_typesupport::idl::KeylessShapeType::isKeyDefined()
{
    return false;
}

void shapes_demo_typesupport::idl::KeylessShapeType::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
        
}

