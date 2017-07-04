// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#include <eprosimashapesdemo/qt/mainwindow.h>
#include <fastrtps/log/Log.h>
#include <fastrtps/utils/eClock.h>
#include <QApplication>
#include <eprosimashapesdemo/utils/md5.h>
#include <fastrtps/Domain.h>

#ifdef WIN32
int CALLBACK WinMain(
    _In_ HINSTANCE /*hInstance*/,
    _In_ HINSTANCE /*hPrevInstance*/,
    _In_ LPSTR     /*lpCmdLine*/,
    _In_ int       /*nCmdShow*/
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
    Domain::stopAll();
    return 0;
}
