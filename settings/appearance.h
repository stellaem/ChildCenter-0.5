#ifndef APPEARANCE_H
#define APPEARANCE_H
#include <QObject>
#include <QColor>
#include <QDebug>


class Appearance: public QObject
{
    Q_OBJECT
public:
    Appearance(QObject *parent = nullptr)
    {
        colorBack.setNamedColor("#F3F5F8");
        colorBackground.setNamedColor("#FFFFFF");
        colorMain.setNamedColor("#617388");
        colorBorder.setNamedColor("#CFCACA");
    };
    // colorBack
    Q_INVOKABLE QColor getColorBack() { return colorBack; }
    void setColorBack(QColor &newColorBack) { colorBack = newColorBack; }
    // colorBackground
    Q_INVOKABLE QColor getColorBackground() { return colorBackground; }
    void setColorBackground(QColor &newColorBackground) { colorBack = newColorBackground; }
    // colorMain
    Q_INVOKABLE QColor getColorMain() { return colorMain; }
    void setColorMain( QColor &newColorMain) { colorMain = newColorMain; }
    // colorCompl
    Q_INVOKABLE QColor getColorBorder()  { return colorBorder; }
    void setColorBorder(QColor &newColorBorder) { colorBorder = newColorBorder; }
    ~Appearance() {};

private:
    QColor colorBack = QColor();
    QColor colorBackground = QColor();
    QColor colorMain = QColor();
    QColor colorBorder = QColor();
};

#endif // APPEARANCE_H
