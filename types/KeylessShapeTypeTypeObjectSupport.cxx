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
 * @file KeylessShapeTypeTypeObjectSupport.cxx
 * Source file containing the implementation to register the TypeObject representation of the described types in the IDL file
 *
 * This file was generated by the tool fastddsgen (version: 4.1.0).
 */

#include "KeylessShapeTypeTypeObjectSupport.hpp"

#include <mutex>
#include <string>

#include <fastcdr/xcdr/external.hpp>
#include <fastcdr/xcdr/optional.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/log/Log.hpp>
#include <fastdds/dds/xtypes/common.hpp>
#include <fastdds/dds/xtypes/type_representation/ITypeObjectRegistry.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObject.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObjectUtils.hpp>
#include "KeylessShapeType.hpp"


using namespace eprosima::fastdds::dds::xtypes;

namespace shapes_demo_typesupport {
namespace idl {
// TypeIdentifier is returned by reference: dependent structures/unions are registered in this same method
void register_KeylessShapeType_type_identifier(
        TypeIdentifierPair& type_ids_KeylessShapeType)
{

    ReturnCode_t return_code_KeylessShapeType {eprosima::fastdds::dds::RETCODE_OK};
    return_code_KeylessShapeType =
        eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
        "shapes_demo_typesupport::idl::dds_::KeylessShapeType_", type_ids_KeylessShapeType);
    if (eprosima::fastdds::dds::RETCODE_OK != return_code_KeylessShapeType)
    {
        StructTypeFlag struct_flags_KeylessShapeType = TypeObjectUtils::build_struct_type_flag(eprosima::fastdds::dds::xtypes::ExtensibilityKind::FINAL,
                false, false);
        QualifiedTypeName type_name_KeylessShapeType = "shapes_demo_typesupport::idl::dds_::KeylessShapeType_";
        eprosima::fastcdr::optional<AppliedBuiltinTypeAnnotations> type_ann_builtin_KeylessShapeType;
        eprosima::fastcdr::optional<AppliedAnnotationSeq> ann_custom_KeylessShapeType;
        CompleteTypeDetail detail_KeylessShapeType = TypeObjectUtils::build_complete_type_detail(type_ann_builtin_KeylessShapeType, ann_custom_KeylessShapeType, type_name_KeylessShapeType.to_string());
        CompleteStructHeader header_KeylessShapeType;
        header_KeylessShapeType = TypeObjectUtils::build_complete_struct_header(TypeIdentifier(), detail_KeylessShapeType);
        CompleteStructMemberSeq member_seq_KeylessShapeType;
        {
            TypeIdentifierPair type_ids_color;
            ReturnCode_t return_code_color {eprosima::fastdds::dds::RETCODE_OK};
            return_code_color =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "anonymous_string_unbounded", type_ids_color);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_color)
            {
                {
                    SBound bound = 0;
                    StringSTypeDefn string_sdefn = TypeObjectUtils::build_string_s_type_defn(bound);
                    if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                            TypeObjectUtils::build_and_register_s_string_type_identifier(string_sdefn,
                            "anonymous_string_unbounded", type_ids_color))
                    {
                        EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                            "anonymous_string_unbounded already registered in TypeObjectRegistry for a different type.");
                    }
                }
            }
            StructMemberFlag member_flags_color = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_color = 0x00000000;
            bool common_color_ec {false};
            CommonStructMember common_color {TypeObjectUtils::build_common_struct_member(member_id_color, member_flags_color, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_color, common_color_ec))};
            if (!common_color_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure color member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_color = "color";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_color;
            ann_custom_KeylessShapeType.reset();
            CompleteMemberDetail detail_color = TypeObjectUtils::build_complete_member_detail(name_color, member_ann_builtin_color, ann_custom_KeylessShapeType);
            CompleteStructMember member_color = TypeObjectUtils::build_complete_struct_member(common_color, detail_color);
            TypeObjectUtils::add_complete_struct_member(member_seq_KeylessShapeType, member_color);
        }
        {
            TypeIdentifierPair type_ids_x;
            ReturnCode_t return_code_x {eprosima::fastdds::dds::RETCODE_OK};
            return_code_x =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_int32_t", type_ids_x);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_x)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "x Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_x = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_x = 0x00000001;
            bool common_x_ec {false};
            CommonStructMember common_x {TypeObjectUtils::build_common_struct_member(member_id_x, member_flags_x, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_x, common_x_ec))};
            if (!common_x_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure x member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_x = "x";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_x;
            ann_custom_KeylessShapeType.reset();
            CompleteMemberDetail detail_x = TypeObjectUtils::build_complete_member_detail(name_x, member_ann_builtin_x, ann_custom_KeylessShapeType);
            CompleteStructMember member_x = TypeObjectUtils::build_complete_struct_member(common_x, detail_x);
            TypeObjectUtils::add_complete_struct_member(member_seq_KeylessShapeType, member_x);
        }
        {
            TypeIdentifierPair type_ids_y;
            ReturnCode_t return_code_y {eprosima::fastdds::dds::RETCODE_OK};
            return_code_y =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_int32_t", type_ids_y);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_y)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "y Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_y = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_y = 0x00000002;
            bool common_y_ec {false};
            CommonStructMember common_y {TypeObjectUtils::build_common_struct_member(member_id_y, member_flags_y, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_y, common_y_ec))};
            if (!common_y_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure y member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_y = "y";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_y;
            ann_custom_KeylessShapeType.reset();
            CompleteMemberDetail detail_y = TypeObjectUtils::build_complete_member_detail(name_y, member_ann_builtin_y, ann_custom_KeylessShapeType);
            CompleteStructMember member_y = TypeObjectUtils::build_complete_struct_member(common_y, detail_y);
            TypeObjectUtils::add_complete_struct_member(member_seq_KeylessShapeType, member_y);
        }
        {
            TypeIdentifierPair type_ids_shapesize;
            ReturnCode_t return_code_shapesize {eprosima::fastdds::dds::RETCODE_OK};
            return_code_shapesize =
                eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->type_object_registry().get_type_identifiers(
                "_int32_t", type_ids_shapesize);

            if (eprosima::fastdds::dds::RETCODE_OK != return_code_shapesize)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                        "shapesize Structure member TypeIdentifier unknown to TypeObjectRegistry.");
                return;
            }
            StructMemberFlag member_flags_shapesize = TypeObjectUtils::build_struct_member_flag(eprosima::fastdds::dds::xtypes::TryConstructFailAction::DISCARD,
                    false, false, false, false);
            MemberId member_id_shapesize = 0x00000003;
            bool common_shapesize_ec {false};
            CommonStructMember common_shapesize {TypeObjectUtils::build_common_struct_member(member_id_shapesize, member_flags_shapesize, TypeObjectUtils::retrieve_complete_type_identifier(type_ids_shapesize, common_shapesize_ec))};
            if (!common_shapesize_ec)
            {
                EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION, "Structure shapesize member TypeIdentifier inconsistent.");
                return;
            }
            MemberName name_shapesize = "shapesize";
            eprosima::fastcdr::optional<AppliedBuiltinMemberAnnotations> member_ann_builtin_shapesize;
            ann_custom_KeylessShapeType.reset();
            CompleteMemberDetail detail_shapesize = TypeObjectUtils::build_complete_member_detail(name_shapesize, member_ann_builtin_shapesize, ann_custom_KeylessShapeType);
            CompleteStructMember member_shapesize = TypeObjectUtils::build_complete_struct_member(common_shapesize, detail_shapesize);
            TypeObjectUtils::add_complete_struct_member(member_seq_KeylessShapeType, member_shapesize);
        }
        CompleteStructType struct_type_KeylessShapeType = TypeObjectUtils::build_complete_struct_type(struct_flags_KeylessShapeType, header_KeylessShapeType, member_seq_KeylessShapeType);
        if (eprosima::fastdds::dds::RETCODE_BAD_PARAMETER ==
                TypeObjectUtils::build_and_register_struct_type_object(struct_type_KeylessShapeType, type_name_KeylessShapeType.to_string(), type_ids_KeylessShapeType))
        {
            EPROSIMA_LOG_ERROR(XTYPES_TYPE_REPRESENTATION,
                    "shapes_demo_typesupport::idl::KeylessShapeType already registered in TypeObjectRegistry for a different type.");
        }
    }
}
} // namespace idl

} // namespace shapes_demo_typesupport

