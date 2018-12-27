# Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

macro(install_prerequisites target)
    if(THIRDPARTY)
        file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/install_prerequisites_for_${target}.cmake
            "message(STATUS \"Getting prerequisites for target \${TARGET_FILE}\")\n"
            "set(CMAKE_PREFIX_PATH \"${CMAKE_PREFIX_PATH}\")\n"
            "include(GetPrerequisites)\n"
            "if(NOT \"\${TARGET_FILE}\" STREQUAL \"\")\n"
            "file(READ \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake FILE_READED)\n"
            "string(FIND \"\${FILE_READED}\" \"\#\${TARGET_FILE}\" STRING_FOUND)\n"
            "if(\${STRING_FOUND} LESS 0)\n"
            "get_prerequisites(\${TARGET_FILE} DEPENDENT_LIBRARIES 1 1 \"\" \"\")\n"
            "list(LENGTH DEPENDENT_LIBRARIES DEPENDENT_LIBRARIES_LENGTH)\n"
            "if(\${DEPENDENT_LIBRARIES_LENGTH} GREATER 0)\n"
            "file(APPEND \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake \"\#\${TARGET_FILE}\\n\")\n"
            "file(APPEND \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake \"if(NOT CMAKE_INSTALL_COMPONENT OR \\\"\\\${CMAKE_INSTALL_COMPONENT}\\\" STREQUAL \\\"Unspecified\\\")\\n\")\n"
            "if(\"\${TARGET_FILE}\" MATCHES \".*([Dd][Ee][Bb][Uu][Gg]).*\")\n"
            "file(APPEND \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake \"if(\\\"\\\${CMAKE_INSTALL_CONFIG_NAME}\\\" MATCHES \\\"^([Dd][Ee][Bb][Uu][Gg])\\$\\\")\\n\")\n"
            "elseif(\"\${TARGET_FILE}\" MATCHES \".*([Rr][Ee][Ll][Ee][Aa][Ss][Ee]).*\")\n"
            "file(APPEND \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake \"if(\\\"\\\${CMAKE_INSTALL_CONFIG_NAME}\\\" MATCHES \\\"^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])\\$\\\")\\n\")\n"
            "endif()\n"
            "foreach(DEPENDENCY_FILE \${DEPENDENT_LIBRARIES})\n"
            "gp_resolve_item(\"\${TARGET_FILE}\" \"\${DEPENDENCY_FILE}\" \"\" \"\" resolved_file_)\n"
            "if(NOT \"\${DEPENDENCY_FILE}\" STREQUAL \"\${resolved_file_}\")\n"
            "file(APPEND \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake \"file(INSTALL DESTINATION \\\"\\\${CMAKE_INSTALL_PREFIX}/bin\\\" TYPE EXECUTABLE FILES \\\"\${resolved_file_}\\\")\\n\")\n"
            "endif()\n"
            "endforeach()\n"
            "file(APPEND \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake \"endif()\\n\")\n"
            "file(APPEND \${CMAKE_CURRENT_SOURCE_DIR}/cmake_install.cmake \"endif()\\n\")\n"
            "endif()\n"
            "endif()\n"
            "else()\n"
            "message(FATAL_ERROR \"Not found target file \${TARGET_FILE}\")\n"
            "endif()"
            )

        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND}
            -DTARGET_FILE=$<TARGET_FILE:${target}>
            -P ${CMAKE_CURRENT_BINARY_DIR}/install_prerequisites_for_${target}.cmake
            )
    endif()
endmacro()
