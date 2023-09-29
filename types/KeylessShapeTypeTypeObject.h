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
 * @file KeylessShapeTypeTypeObject.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_SHAPES_DEMO_TYPESUPPORT_IDL_KEYLESSSHAPETYPE_TYPE_OBJECT_H_
#define _FAST_DDS_GENERATED_SHAPES_DEMO_TYPESUPPORT_IDL_KEYLESSSHAPETYPE_TYPE_OBJECT_H_


#include <fastrtps/types/TypeObject.h>
#include <map>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(KeylessShapeType_SOURCE)
#define KeylessShapeType_DllAPI __declspec( dllexport )
#else
#define KeylessShapeType_DllAPI __declspec( dllimport )
#endif // KeylessShapeType_SOURCE
#else
#define KeylessShapeType_DllAPI
#endif
#else
#define KeylessShapeType_DllAPI
#endif // _WIN32

using namespace eprosima::fastrtps::types;

eProsima_user_DllExport void registerKeylessShapeTypeTypes();

namespace shapes_demo_typesupport {
    namespace idl {
        eProsima_user_DllExport const TypeIdentifier* GetKeylessShapeTypeIdentifier(bool complete = false);
        eProsima_user_DllExport const TypeObject* GetKeylessShapeTypeObject(bool complete = false);
        eProsima_user_DllExport const TypeObject* GetMinimalKeylessShapeTypeObject();
        eProsima_user_DllExport const TypeObject* GetCompleteKeylessShapeTypeObject();

    } // namespace idl
} // namespace shapes_demo_typesupport

#endif // _FAST_DDS_GENERATED_SHAPES_DEMO_TYPESUPPORT_IDL_KEYLESSSHAPETYPE_TYPE_OBJECT_H_