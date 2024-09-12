# Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
#
# This file is part of eProsima Fast DDS Shapes Demo.
#
# eProsima Fast DDS Shapes Demo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# eProsima Fast DDS Shapes Demo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with eProsima Fast DDS Shapes Demo. If not, see <https://www.gnu.org/licenses/>.

###############################################################################
# CMake build rules for ShapesDemo
###############################################################################
cmake_minimum_required(VERSION 3.20)


file(READ version.pri SHAPESVERSION)

# Remove EOF new line character
string(REPLACE "\n" "" SHAPESVERSION ${SHAPESVERSION})

set(IS_TOP_LEVEL TRUE)
if(PROJECT_SOURCE_DIR)
    set(IS_TOP_LEVEL FALSE)
endif()

# Set CMAKE_BUILD_TYPE to Release by default.
if(DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        )
else()
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        )
endif()

project("ShapesDemo")
set(PROJECT_NAME_STYLED "ShapesDemo")
set(PROJECT_NAME_LARGE "Shapes Demo")
string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
set(${PROJECT_NAME}_DESCRIPTION_SUMMARY "Shapes Demo for eProsima Fast DDS")
set(${PROJECT_NAME}_DESCRIPTION "eProsima ${PROJECT_NAME_LARGE} library provides publication/subscription communication using RTPS protocol.")

message(STATUS "Configuring ${PROJECT_NAME_LAGE}")

###############################################################################
# Warning level
###############################################################################
if(MSVC OR MSVC_IDE)
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Wno-unknown-pragmas")
endif()

###############################################################################
# GCC colors if using CCache
###############################################################################
if("${CMAKE_CXX_COMPILER_LAUNCHER}" STREQUAL "ccache" AND
        CMAKE_COMPILER_IS_GNUCXX AND
        CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4,8)
    add_compile_options(-fdiagnostics-color=always)
endif()

###############################################################################
# Test system configuration
###############################################################################
include(${PROJECT_SOURCE_DIR}/cmake/common/check_configuration.cmake)
check_stdcxx()
check_compile_feature()
check_endianness()

###############################################################################
# Check MSVC architecture
###############################################################################
if(MSVC OR MSVC_IDE)
    check_msvc_arch()
endif()

###############################################################################
# Load CMake modules
###############################################################################
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)

###############################################################################
# Load external eProsima projects.
###############################################################################
###
# Installation directories
###
set(BIN_INSTALL_DIR bin/ CACHE PATH "Installation directory for binaries")
set(INCLUDE_INSTALL_DIR include/ CACHE PATH "Installation directory for C++ Headers")
set(LIB_INSTALL_DIR lib/ CACHE PATH "Installation directory for libraries")
set(DATA_INSTALL_DIR share/ CACHE PATH "Installation directory for data")
if(WIN32)
    set(DOC_DIR "doc")
else()
    set(DOC_DIR "${DATA_INSTALL_DIR}/doc")
endif()
set(DOC_INSTALL_DIR ${DOC_DIR} CACHE PATH "Installation directory for documentation")
if(WIN32)
    set(LICENSE_INSTALL_DIR . CACHE PATH "Installation directory for licenses")
else()
    set(LICENSE_INSTALL_DIR ${DATA_INSTALL_DIR}/${PROJECT_NAME} CACHE PATH "Installation directory for licenses")
endif()

set(CMAKE_BUILD_TYPE Release CACHE STRING "Build Type")

###############################################################################
# eProsima build options
###############################################################################
option(EPROSIMA_BUILD "Activate internal building" OFF)

###############################################################################
# Load external eProsima projects.
###############################################################################
set(FASTDDS_MIN_VERSION "3.0.0")

find_package(fastcdr REQUIRED)
find_package(fastdds ${FASTDDS_MIN_VERSION} REQUIRED)

# If ROS environment is not set, disable ROS features. If there's no TypeSupport for the ROS 2 type, disable them as well.
if (DEFINED ENV{ROS_VERSION})
    # Required by ament_cmake_core
    cmake_policy(SET CMP0057 NEW)
    find_package(shapes_demo_typesupport QUIET)
    if (shapes_demo_typesupport_FOUND)
        message(STATUS "ROS 2 environment and ShapesDemo TypeSupport found. Enabling ROS 2 integration.")
        set(BUILD_ROS_COMPONENTS ON)
    else()
        message(STATUS "ShapesDemo TypeSupport not found. Disabling ROS 2 integration.")
        set(BUILD_ROS_COMPONENTS OFF)
    endif()
else()
    message(STATUS "ROS environment not found. Disabling ROS 2 integration.")
    set(BUILD_ROS_COMPONENTS OFF)
endif()

###############################################################################
# Compile
###############################################################################
find_package(Qt5Core 5.9 REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set( MOC_HEADERS
    include/eprosimashapesdemo/qt/DrawArea.h
    include/eprosimashapesdemo/qt/UpdateThread.h
    include/eprosimashapesdemo/qt/mainwindow.h
    include/eprosimashapesdemo/qt/optionsdialog.h
    include/eprosimashapesdemo/qt/participantdialog.h
    include/eprosimashapesdemo/qt/publishdialog.h
    include/eprosimashapesdemo/qt/subscribedialog.h
    )

set( UIS
    forms/mainwindow.ui
    forms/optionsdialog.ui
    forms/participantdialog.ui
    forms/publishdialog.ui
    forms/subscribedialog.ui
    )

set( RESOURCES
    images/eprosimalogo.qrc
    )


QT5_WRAP_UI( UI_HEADERS ${UIS} )
QT5_WRAP_CPP( MOC_SRCS ${MOC_HEADERS} )
QT5_ADD_RESOURCES( RSCS ${RESOURCES} )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)

message(STATUS "Configuring ShapesDemo...")
set( SHAPESDEMO_SOURCES
    images/eprosima_icon.rc
    src/main.cpp
    src/qt/ContentFilterSelector.cpp
    src/qt/DrawArea.cpp
    src/qt/mainwindow.cpp
    src/qt/optionsdialog.cpp
    src/qt/participantdialog.cpp
    src/qt/publishdialog.cpp
    src/qt/subscribedialog.cpp
    src/qt/UpdateThread.cpp
    src/shapesdemo/ShapeHistory.cpp
    src/shapesdemo/ShapePublisher.cpp
    src/shapesdemo/ShapesDemo.cpp
    src/shapesdemo/ShapeSubscriber.cpp
    types/ShapePubSubTypes.cxx
    types/ShapeTypeObjectSupport.cxx
    )

if(BUILD_ROS_COMPONENTS)
    list( APPEND SHAPESDEMO_SOURCES
    types/KeylessShapeTypePubSubTypes.cxx
    types/KeylessShapeTypeTypeObjectSupport.cxx
    )
endif()

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SHAPESDEMO_SOURCES} ${MOC_SRCS} ${UI_HEADERS} ${RSCS} )
else()
    add_executable(${PROJECT_NAME} ${SHAPESDEMO_SOURCES} ${MOC_SRCS} ${UI_HEADERS} ${RSCS} )
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE -D${SHAPESVERSION})
target_include_directories(${PROJECT_NAME} PRIVATE include types ${IU_HEADERS})

if(BUILD_ROS_COMPONENTS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DENABLE_ROS_COMPONENTS)
endif()

target_link_libraries(${PROJECT_NAME}
    fastcdr
    fastdds
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui)

###############################################################################
# Install
###############################################################################
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    LIBRARY DESTINATION ${BIN_INSTALL_DIR}
    ARCHIVE DESTINATION ${BIN_INSTALL_DIR}
    COMPONENT binaries
    )
