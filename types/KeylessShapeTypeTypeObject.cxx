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
 * @file KeylessShapeTypeTypeObject.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "KeylessShapeType.h"
#include "KeylessShapeTypeTypeObject.h"
#include <mutex>
#include <utility>
#include <sstream>
#include <fastdds/rtps/common/CdrSerialization.hpp>
#include <fastrtps/rtps/common/SerializedPayload.h>
#include <fastrtps/utils/md5.h>
#include <fastrtps/types/TypeObjectFactory.h>
#include <fastrtps/types/TypeNamesGenerator.h>
#include <fastrtps/types/AnnotationParameterValue.h>

using namespace eprosima::fastrtps::rtps;

void registerKeylessShapeTypeTypes()
{
    static std::once_flag once_flag;
    std::call_once(once_flag, []()
            {
                TypeObjectFactory *factory = TypeObjectFactory::get_instance();
                factory->add_type_object("shapes_demo_typesupport::idl::dds_::KeylessShapeType_", shapes_demo_typesupport::idl::GetKeylessShapeTypeIdentifier(true),
                        shapes_demo_typesupport::idl::GetKeylessShapeTypeObject(true));
                factory->add_type_object("shapes_demo_typesupport::idl::dds_::KeylessShapeType_", shapes_demo_typesupport::idl::GetKeylessShapeTypeIdentifier(false),
                        shapes_demo_typesupport::idl::GetKeylessShapeTypeObject(false));



            });
}

namespace shapes_demo_typesupport {
    namespace idl {


        const TypeIdentifier* GetKeylessShapeTypeIdentifier(bool complete)
        {
            const TypeIdentifier * c_identifier = TypeObjectFactory::get_instance()->get_type_identifier("KeylessShapeType", complete);
            if (c_identifier != nullptr && (!complete || c_identifier->_d() == EK_COMPLETE))
            {
                return c_identifier;
            }

            GetKeylessShapeTypeObject(complete); // Generated inside
            return TypeObjectFactory::get_instance()->get_type_identifier("KeylessShapeType", complete);
        }

        const TypeObject* GetKeylessShapeTypeObject(bool complete)
        {
            const TypeObject* c_type_object = TypeObjectFactory::get_instance()->get_type_object("KeylessShapeType", complete);
            if (c_type_object != nullptr)
            {
                return c_type_object;
            }
            else if (complete)
            {
                return GetCompleteKeylessShapeTypeObject();
            }
            //else
            return GetMinimalKeylessShapeTypeObject();
        }

        const TypeObject* GetMinimalKeylessShapeTypeObject()
        {
            const TypeObject* c_type_object = TypeObjectFactory::get_instance()->get_type_object("KeylessShapeType", false);
            if (c_type_object != nullptr)
            {
                return c_type_object;
            }

            TypeObject *type_object = new TypeObject();
            type_object->_d(EK_MINIMAL);
            type_object->minimal()._d(TK_STRUCTURE);

            type_object->minimal().struct_type().struct_flags().IS_FINAL(false);
            type_object->minimal().struct_type().struct_flags().IS_APPENDABLE(false);
            type_object->minimal().struct_type().struct_flags().IS_MUTABLE(false);
            type_object->minimal().struct_type().struct_flags().IS_NESTED(false);
            type_object->minimal().struct_type().struct_flags().IS_AUTOID_HASH(false); // Unsupported

            MemberId memberId = 0;
            MinimalStructMember mst_color;
            mst_color.common().member_id(memberId++);
            mst_color.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            mst_color.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            mst_color.common().member_flags().IS_EXTERNAL(false); // Unsupported
            mst_color.common().member_flags().IS_OPTIONAL(false);
            mst_color.common().member_flags().IS_MUST_UNDERSTAND(false);
            mst_color.common().member_flags().IS_KEY(false);
            mst_color.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            mst_color.common().member_type_id(*TypeObjectFactory::get_instance()->get_string_identifier(255, false));

            MD5 color_hash("color");
            for(int i = 0; i < 4; ++i)
            {
                mst_color.detail().name_hash()[i] = color_hash.digest[i];
            }
            type_object->minimal().struct_type().member_seq().emplace_back(mst_color);

            MinimalStructMember mst_x;
            mst_x.common().member_id(memberId++);
            mst_x.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            mst_x.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            mst_x.common().member_flags().IS_EXTERNAL(false); // Unsupported
            mst_x.common().member_flags().IS_OPTIONAL(false);
            mst_x.common().member_flags().IS_MUST_UNDERSTAND(false);
            mst_x.common().member_flags().IS_KEY(false);
            mst_x.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            mst_x.common().member_type_id(*TypeObjectFactory::get_instance()->get_type_identifier("int32_t", false));


            MD5 x_hash("x");
            for(int i = 0; i < 4; ++i)
            {
                mst_x.detail().name_hash()[i] = x_hash.digest[i];
            }
            type_object->minimal().struct_type().member_seq().emplace_back(mst_x);

            MinimalStructMember mst_y;
            mst_y.common().member_id(memberId++);
            mst_y.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            mst_y.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            mst_y.common().member_flags().IS_EXTERNAL(false); // Unsupported
            mst_y.common().member_flags().IS_OPTIONAL(false);
            mst_y.common().member_flags().IS_MUST_UNDERSTAND(false);
            mst_y.common().member_flags().IS_KEY(false);
            mst_y.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            mst_y.common().member_type_id(*TypeObjectFactory::get_instance()->get_type_identifier("int32_t", false));


            MD5 y_hash("y");
            for(int i = 0; i < 4; ++i)
            {
                mst_y.detail().name_hash()[i] = y_hash.digest[i];
            }
            type_object->minimal().struct_type().member_seq().emplace_back(mst_y);

            MinimalStructMember mst_shapesize;
            mst_shapesize.common().member_id(memberId++);
            mst_shapesize.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            mst_shapesize.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            mst_shapesize.common().member_flags().IS_EXTERNAL(false); // Unsupported
            mst_shapesize.common().member_flags().IS_OPTIONAL(false);
            mst_shapesize.common().member_flags().IS_MUST_UNDERSTAND(false);
            mst_shapesize.common().member_flags().IS_KEY(false);
            mst_shapesize.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            mst_shapesize.common().member_type_id(*TypeObjectFactory::get_instance()->get_type_identifier("int32_t", false));


            MD5 shapesize_hash("shapesize");
            for(int i = 0; i < 4; ++i)
            {
                mst_shapesize.detail().name_hash()[i] = shapesize_hash.digest[i];
            }
            type_object->minimal().struct_type().member_seq().emplace_back(mst_shapesize);


            // Header
            // TODO Inheritance
            //type_object->minimal().struct_type().header().base_type()._d(EK_MINIMAL);
            //type_object->minimal().struct_type().header().base_type().equivalence_hash()[0..13];
            TypeIdentifier identifier;
            identifier._d(EK_MINIMAL);

            eprosima::fastcdr::CdrSizeCalculator calculator(eprosima::fastcdr::CdrVersion::XCDRv1);
            size_t current_alignment {0};
            SerializedPayload_t payload(static_cast<uint32_t>(
                calculator.calculate_serialized_size(type_object->minimal().struct_type(), current_alignment) + 4));
            eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
            // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
            eprosima::fastcdr::Cdr ser(
                fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::CdrVersion::XCDRv1); // Object that serializes the data.
            payload.encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

            ser << *type_object;
        #if FASTCDR_VERSION_MAJOR == 1
            payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        #else
            payload.length = (uint32_t)ser.get_serialized_data_length(); //Get the serialized length
        #endif // FASTCDR_VERSION_MAJOR == 1
            MD5 objectHash;
            objectHash.update((char*)payload.data, payload.length);
            objectHash.finalize();
            for(int i = 0; i < 14; ++i)
            {
                identifier.equivalence_hash()[i] = objectHash.digest[i];
            }

            TypeObjectFactory::get_instance()->add_type_object("KeylessShapeType", &identifier, type_object);
            delete type_object;
            return TypeObjectFactory::get_instance()->get_type_object("KeylessShapeType", false);
        }

        const TypeObject* GetCompleteKeylessShapeTypeObject()
        {
            const TypeObject* c_type_object = TypeObjectFactory::get_instance()->get_type_object("KeylessShapeType", true);
            if (c_type_object != nullptr && c_type_object->_d() == EK_COMPLETE)
            {
                return c_type_object;
            }

            TypeObject *type_object = new TypeObject();
            type_object->_d(EK_COMPLETE);
            type_object->complete()._d(TK_STRUCTURE);

            type_object->complete().struct_type().struct_flags().IS_FINAL(false);
            type_object->complete().struct_type().struct_flags().IS_APPENDABLE(false);
            type_object->complete().struct_type().struct_flags().IS_MUTABLE(false);
            type_object->complete().struct_type().struct_flags().IS_NESTED(false);
            type_object->complete().struct_type().struct_flags().IS_AUTOID_HASH(false); // Unsupported

            MemberId memberId = 0;
            CompleteStructMember cst_color;
            cst_color.common().member_id(memberId++);
            cst_color.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            cst_color.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            cst_color.common().member_flags().IS_EXTERNAL(false); // Unsupported
            cst_color.common().member_flags().IS_OPTIONAL(false);
            cst_color.common().member_flags().IS_MUST_UNDERSTAND(false);
            cst_color.common().member_flags().IS_KEY(false);
            cst_color.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            cst_color.common().member_type_id(*TypeObjectFactory::get_instance()->get_string_identifier(255, false));

            cst_color.detail().name("color");

            type_object->complete().struct_type().member_seq().emplace_back(cst_color);

            CompleteStructMember cst_x;
            cst_x.common().member_id(memberId++);
            cst_x.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            cst_x.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            cst_x.common().member_flags().IS_EXTERNAL(false); // Unsupported
            cst_x.common().member_flags().IS_OPTIONAL(false);
            cst_x.common().member_flags().IS_MUST_UNDERSTAND(false);
            cst_x.common().member_flags().IS_KEY(false);
            cst_x.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            cst_x.common().member_type_id(*TypeObjectFactory::get_instance()->get_type_identifier("int32_t", false));


            cst_x.detail().name("x");

            type_object->complete().struct_type().member_seq().emplace_back(cst_x);

            CompleteStructMember cst_y;
            cst_y.common().member_id(memberId++);
            cst_y.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            cst_y.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            cst_y.common().member_flags().IS_EXTERNAL(false); // Unsupported
            cst_y.common().member_flags().IS_OPTIONAL(false);
            cst_y.common().member_flags().IS_MUST_UNDERSTAND(false);
            cst_y.common().member_flags().IS_KEY(false);
            cst_y.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            cst_y.common().member_type_id(*TypeObjectFactory::get_instance()->get_type_identifier("int32_t", false));


            cst_y.detail().name("y");

            type_object->complete().struct_type().member_seq().emplace_back(cst_y);

            CompleteStructMember cst_shapesize;
            cst_shapesize.common().member_id(memberId++);
            cst_shapesize.common().member_flags().TRY_CONSTRUCT1(false); // Unsupported
            cst_shapesize.common().member_flags().TRY_CONSTRUCT2(false); // Unsupported
            cst_shapesize.common().member_flags().IS_EXTERNAL(false); // Unsupported
            cst_shapesize.common().member_flags().IS_OPTIONAL(false);
            cst_shapesize.common().member_flags().IS_MUST_UNDERSTAND(false);
            cst_shapesize.common().member_flags().IS_KEY(false);
            cst_shapesize.common().member_flags().IS_DEFAULT(false); // Doesn't apply
            cst_shapesize.common().member_type_id(*TypeObjectFactory::get_instance()->get_type_identifier("int32_t", false));


            cst_shapesize.detail().name("shapesize");

            type_object->complete().struct_type().member_seq().emplace_back(cst_shapesize);


            // Header
            type_object->complete().struct_type().header().detail().type_name("KeylessShapeType");
            // TODO inheritance
            TypeIdentifier identifier;
            identifier._d(EK_COMPLETE);

            eprosima::fastcdr::CdrSizeCalculator calculator(eprosima::fastcdr::CdrVersion::XCDRv1);
            size_t current_alignment {0};
            SerializedPayload_t payload(static_cast<uint32_t>(
                calculator.calculate_serialized_size(type_object->complete().struct_type(), current_alignment) + 4));
            eprosima::fastcdr::FastBuffer fastbuffer((char*) payload.data, payload.max_size);
            // Fixed endian (Page 221, EquivalenceHash definition of Extensible and Dynamic Topic Types for DDS document)
            eprosima::fastcdr::Cdr ser(
                fastbuffer, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS,
                eprosima::fastcdr::CdrVersion::XCDRv1); // Object that serializes the data.
            payload.encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

            ser << *type_object;
        #if FASTCDR_VERSION_MAJOR == 1
            payload.length = (uint32_t)ser.getSerializedDataLength(); //Get the serialized length
        #else
            payload.length = (uint32_t)ser.get_serialized_data_length(); //Get the serialized length
        #endif // FASTCDR_VERSION_MAJOR == 1
            MD5 objectHash;
            objectHash.update((char*)payload.data, payload.length);
            objectHash.finalize();
            for(int i = 0; i < 14; ++i)
            {
                identifier.equivalence_hash()[i] = objectHash.digest[i];
            }

            TypeObjectFactory::get_instance()->add_type_object("KeylessShapeType", &identifier, type_object);
            delete type_object;
            return TypeObjectFactory::get_instance()->get_type_object("KeylessShapeType", true);
        }

    } // namespace idl
} // namespace shapes_demo_typesupport