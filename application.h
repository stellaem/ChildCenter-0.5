#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

#include "settings/appearance.h"
#include "settings/settings.h"
class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);

    Settings getSettings() { return settings; }
    Appearance getAppearance()  { return appearance; }

private:
    Settings settings;
    Appearance appearance;
};

#endif // APPLICATION_H
