// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// This file is part of eProsima Fast DDS Shapes-Demo.
//
// eProsima Fast DDS Shapes-Demo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// eProsima Fast DDS Shapes-Demo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with eProsima Fast DDS Shapes-Demo. If not, see <https://www.gnu.org/licenses/>.

#include <eprosimashapesdemo/qt/mainwindow.h>
#include <fastrtps/log/Log.h>
#include <QApplication>
#include <eprosimashapesdemo/utils/md5.h>
#include <fastrtps/Domain.h>

#ifdef WIN32
int __stdcall WinMain(
    _In_ HINSTANCE   /*hInstance*/,
    _In_ HINSTANCE   /*hPrevInstance*/,
    _In_ char* /*lpCmdLine*/,
    _In_ int         /*nCmdShow*/
)
{
    int argc = 0;
    QApplication a(argc, NULL);
#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#endif
    MainWindow w;
    w.show();

    a.exec();
    return 0;
}
