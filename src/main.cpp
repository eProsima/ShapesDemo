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
