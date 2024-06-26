#-------------------------------------------------
#
# Project created by QtCreator 2014-06-26T09:08:43
#
#-------------------------------------------------

RTPSVERSION = 1.8.0
VERSION = $$RTPSVERION

include(version.pri)

DEFINES += SHAPESVERSION=\"\\\"$${SHAPESVERSION}\\\"\"

QT += core
QT += gui
QT += widgets

unix:QMAKE_CXXFLAGS_DEBUG += -c -Wall -D__LITTLE_ENDIAN__ -m64 -fpic -g -std=c++11 -D__DEBUG
unix:QMAKE_CXXFLAGS_RELEASE += -c -Wall -D__LITTLE_ENDIAN__ -m64 -fpic -O2 -std=c++11

win32:QMAKE_CXXFLAGS_DEBUG += -D_MBCS -D__DEBUG -DBOOST_ALL_DYN_LINK -D__LITTLE_ENDIAN__ -D_WIN32
win32:QMAKE_CXXFLAGS_RELEASE += -D_MBCS -DBOOST_ALL_DYN_LINK -D__LITTLE_ENDIAN__ -D_WIN32

win32:QMAKE_LFLAGS_WINDOWS +=/FORCE:MULTIPLE
win32:QMAKE_LFLAGS_WINDOWS_DLL +=/FORCE:MULTIPLE


#CONFIG += console


unix:CONFIG(debug, debug|release): TARGET = $$_PRO_FILE_PWD_/bin/ShapesDemod
unix:CONFIG(release, debug|release):TARGET = $$_PRO_FILE_PWD_/bin/ShapesDemo

win32:CONFIG(debug, debug|release): TARGET = ShapesDemod
win32:CONFIG(release, debug|release):TARGET = ShapesDemo


TEMPLATE = app

INCLUDEPATH += include/
               forms/ui/

FORMS    +=   forms/mainwindow.ui \
              forms/participantdialog.ui \
              forms/publishdialog.ui \
              forms/subscribedialog.ui \
              forms/optionsdialog.ui

unix: CONFIG(release, debug|release):LIBS += -Lusr/lib/ -lfastdds
else:unix: CONFIG(debug, debug|release):LIBS += -Lusr/lib/ -lfastddsd

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/thirdparty/eprosima-common-code
#DEPENDPATH += $$PWD/include
#DEPENDPATH += $$PWD/thirdparty/eprosima-common-code

#unix: CONFIG(debug, debug|release): PRE_TARGETDEPS += usr/lib/libfastddsd.a
#else:unix: CONFIG(release, debug|release): PRE_TARGETDEPS += usr/lib/libfastdds.a



# unix: LIBS +=
# win32:INCLUDEPATH += $(LIB_BOOST_PATH)/
# win32:LIBS +=


HEADERS += \
    include/eprosimashapesdemo/qt/DrawArea.h \
    include/eprosimashapesdemo/qt/mainwindow.h \
    include/eprosimashapesdemo/qt/participantdialog.h \
    include/eprosimashapesdemo/qt/publishdialog.h \
    include/eprosimashapesdemo/qt/subscribedialog.h \
    include/eprosimashapesdemo/shapesdemo/Shape.h \
    include/eprosimashapesdemo/shapesdemo/ShapesDemo.h \
    include/eprosimashapesdemo/utils/md5.h \
    include/eprosimashapesdemo/shapesdemo/ShapePublisher.h \
    include/eprosimashapesdemo/qt/UpdateThread.h \
    include/eprosimashapesdemo/shapesdemo/ShapeSubscriber.h \
    include/eprosimashapesdemo/qt/optionsdialog.h \
    include/eprosimashapesdemo/qt/ContentFilterSelector.h \
    include/eprosimashapesdemo/shapesdemo/ShapeDefinitions.h \
    include/eprosimashapesdemo/shapesdemo/ShapeHistory.h


SOURCES += \
    src/qt/DrawArea.cpp \
    src/qt/mainwindow.cpp \
    src/qt/participantdialog.cpp \
    src/qt/publishdialog.cpp \
    src/qt/subscribedialog.cpp \
    src/shapesdemo/ShapesDemo.cpp \
    src/utils/md5.cpp \
    src/main.cpp \
    src/shapesdemo/ShapePublisher.cpp \
    src/qt/UpdateThread.cpp \
    src/shapesdemo/ShapeSubscriber.cpp \
    src/qt/optionsdialog.cpp \
    src/qt/ContentFilterSelector.cpp \
    src/shapesdemo/ShapeHistory.cpp \
    src/shapesdemo/Shape.cxx \
    src/shapesdemo/Shapev1.cxx \
    src/shapesdemo/ShapePubSubTypes.cxx




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/i86Win32VS2010 -llibfastdds-1.0.0 -L"C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib" -lShlwapi -lIphlpapi
win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/i86Win32VS2010 -llibfastddsd-1.0.0 -L"C:\Program Files (x86)\Microsoft SDKs\Windows\v7.0A\Lib" -lShlwapi -lIphlpapi




#win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/i86Win32VS2010/libfastdds-1.0.0.lib
#win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/i86Win32VS2010/libfastddsd-1.0.0.lib



#win32:INCLUDEPATH += $$PWD/../../include
#win32:DEPENDPATH += $$PWD/../../lib/i86Win32VS2010 C:\Windows\System32


#win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/i86Win32VS2010/libfastdds-0.5.1.lib Shlwapi.lib Iphlpapi.lib
#win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/i86Win32VS2010/libfastddsd-0.5.1.lib Shlwapi.lib Iphlpapi.lib

RESOURCES += \
    images/eprosimalogo.qrc

RC_FILE = images/eprosima_icon.rc
