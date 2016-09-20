# Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

###############################################################################
# CMake build rules for ShapesDemo
###############################################################################
cmake_minimum_required(VERSION 2.8.12)

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

project("shapesdemo")
set(PROJECT_NAME_STYLED "ShapesDemo")
set(PROJECT_NAME_LARGE "Shapes Demo")
string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
set(${PROJECT_NAME}_DESCRIPTION_SUMMARY "Shapes Demo for eProsima Fast RTPS")
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
include(${PROJECT_SOURCE_DIR}/cmake/dev/check_configuration.cmake)
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
# Check libraries
###############################################################################
include(${PROJECT_SOURCE_DIR}/cmake/dev/boost_libraries.cmake)
set(BOOST_LIBRARIES_DEFAULT thread system date_time chrono regex atomic)
check_boost(${BOOST_LIBRARIES_DEFAULT})

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



include(${PROJECT_SOURCE_DIR}/cmake/dev/eprosima_libraries.cmake)
option(THIRDPARTY "Activate the build of thirdparties" OFF)
find_eprosima_package(fastcdr)
find_eprosima_package(fastrtps)


###############################################################################
# Compile 
###############################################################################
include(${PROJECT_SOURCE_DIR}/cmake/dev/set_sources.cmake)

# Find requirements
find_package(Boost REQUIRED COMPONENTS thread system chrono regex)
find_package(fastrtps REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
add_compile_options(--std=c++0x)

message(STATUS "Configuring ShapesDemo...")
set( SHAPESDEMO_SOURCES
    src/qt/DrawArea.cpp 
    src/qt/mainwindow.cpp 
    src/qt/publishdialog.cpp 
    src/qt/subscribedialog.cpp 
    src/shapesdemo/ShapesDemo.cpp
    src/shapesdemo/ShapeTopicDataType.cpp
#   src/utils/md5.cpp
    src/main.cpp 
    src/shapesdemo/ShapePublisher.cpp
    src/qt/UpdateThread.cpp 
    src/shapesdemo/ShapeSubscriber.cpp
    src/qt/optionsdialog.cpp
    src/qt/ContentFilterSelector.cpp
    src/shapesdemo/ShapeHistory.cpp
    forms/ui/moc_DrawArea.cpp
    forms/ui/moc_mainwindow.cpp
    forms/ui/moc_optionsdialog.cpp
    forms/ui/moc_publishdialog.cpp
    forms/ui/moc_subscribedialog.cpp
    forms/ui/moc_UpdateThread.cpp
    )

if(THIRDPARTY)
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${LIB_INSTALL_DIR}")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

add_executable(ShapesDemo ${SHAPESDEMO_SOURCES})
target_include_directories(ShapesDemo PRIVATE include forms/ui ${Boost_INCLUDE_DIR})
target_link_libraries(ShapesDemo fastrtps fastcdr ${Boost_LIBRARIES} Qt5::Widgets Qt5::Core Qt5::Gui)
file(INSTALL ${PROJECT_SOURCE_DIR}/images/eProsimaLogo.png DESTINATION ${CMAKE_BINARY_DIR})
###############################################################################
# Install
###############################################################################
    if(THIRDPARTY)
            # Install includes
            install(DIRECTORY ${PROJECT_BINARY_DIR}/external/install/${INCLUDE_INSTALL_DIR}/
                DESTINATION ${INCLUDE_INSTALL_DIR}
                COMPONENT headers
                OPTIONAL
                )

            # Install libraries
            install(DIRECTORY ${PROJECT_BINARY_DIR}/external/install/${LIB_INSTALL_DIR}/
                DESTINATION ${LIB_INSTALL_DIR}
                USE_SOURCE_PERMISSIONS
                COMPONENT libraries
                )

            # Install licenses
            install(DIRECTORY ${PROJECT_BINARY_DIR}/external/install/licenses/
                DESTINATION ${LICENSE_INSTALL_DIR}
                COMPONENT licenses
                OPTIONAL
                )
    endif()
    install(FILES ${PROJECT_SOURCE_DIR}/images/eProsimaLogo.png DESTINATION ${BIN_INSTALL_DIR})
    install(TARGETS ShapesDemo
        RUNTIME DESTINATION ${BIN_INSTALL_DIR}
        COMPONENT ShapesDemo_bin
        )
