# Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# This file is part of eProsima Fast DDS Shapes-Demo.
#
# eProsima Fast DDS Shapes-Demo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# eProsima Fast DDS Shapes-Demo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with eProsima Fast DDS Shapes-Demo. If not, see <https://www.gnu.org/licenses/>.

macro(eprosima_find_package package)

    if(NOT ${package}_FOUND)

        # Parse arguments.
        set(options REQUIRED)
        set(multiValueArgs OPTIONS)
        cmake_parse_arguments(FIND "${options}" "" "${multiValueArgs}" ${ARGN})

        option(THIRDPARTY "Activate the use of internal thirdparties" OFF)
        option(THIRDPARTY_UPDATE "Activate the auto update of internal thirdparties" ON)

        if(EPROSIMA_BUILD)
            set(THIRDPARTY ON)
        endif()

        option(THIRDPARTY_${package} "Activate the use of internal thirdparty ${package}" OFF)

        if(NOT EPROSIMA_INSTALLER)
            find_package(${package} QUIET)
        endif()

        if(NOT ${package}_FOUND AND (THIRDPARTY OR THIRDPARTY_${package}))
            set(SUBDIRECTORY_EXIST TRUE)
            if(THIRDPARTY_UPDATE OR NOT EXISTS "${PROJECT_SOURCE_DIR}/thirdparty/${package}/CMakeLists.txt")
                message(STATUS "${package} thirdparty is being updated...")
                execute_process(
                    COMMAND git submodule update --recursive --init "thirdparty/${package}"
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                    RESULT_VARIABLE EXECUTE_RESULT
                    )
                if(NOT EXECUTE_RESULT EQUAL 0)
                    message(WARNING "Cannot configure Git submodule ${package}")
                    if(NOT EXISTS "${PROJECT_SOURCE_DIR}/thirdparty/${package}/CMakeLists.txt")
                        set(SUBDIRECTORY_EXIST FALSE)
                    endif()
                endif()
            endif()

            if(SUBDIRECTORY_EXIST)
                foreach(opt_ ${FIND_OPTIONS})
                    set(${opt_} ON)
                endforeach()
                add_subdirectory(${PROJECT_SOURCE_DIR}/thirdparty/${package})
                set(${package}_FOUND TRUE)
                if(NOT IS_TOP_LEVEL)
                    set(${package}_FOUND TRUE PARENT_SCOPE)
                endif()
            endif()
        endif()

        if(${package}_FOUND)
            message(STATUS "${package} library found...")
        elseif(${FIND_REQUIRED})
            message(FATAL_ERROR "${package} library not found...")
        else()
            message(STATUS "${package} library not found...")
        endif()
    endif()
endmacro()

macro(eprosima_find_thirdparty package thirdparty_name)
    if(NOT (EPROSIMA_INSTALLER AND (MSVC OR MSVC_IDE)))

        option(THIRDPARTY_${package} "Activate the use of internal thirdparty ${package}" OFF)

        find_package(${package} QUIET)

        if(NOT ${package}_FOUND AND (THIRDPARTY OR THIRDPARTY_${package}))
            execute_process(
                COMMAND git submodule update --recursive --init "thirdparty/${thirdparty_name}"
                WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                RESULT_VARIABLE EXECUTE_RESULT
                )

            if(EXECUTE_RESULT EQUAL 0)
                set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${PROJECT_SOURCE_DIR}/thirdparty/${thirdparty_name})
                set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${PROJECT_SOURCE_DIR}/thirdparty/${thirdparty_name}/${thirdparty_name})
                find_package(${package} REQUIRED)
            else()
                message(FATAL_ERROR "Cannot configure Git submodule ${package}")
            endif()
        endif()

    endif()
endmacro()
