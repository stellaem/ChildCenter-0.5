#include "application.h"


Application::Application(int &argc, char **argv) :
    QApplication(argc, argv)
{
    settings = Settings();
    appearance = Appearance();
}




