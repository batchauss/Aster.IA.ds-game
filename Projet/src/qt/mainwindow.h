#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "../init.h"
#include "../fonctions/frontiere.h"
#include "../touches/actions.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    mainwindow(int argc, char**argv);
    ~mainwindow();

    void createWidgetMenuPrincipal(int argc, char**argv);
    void createWidgetMenuOption();

    void alignCenterWindow();

    void switchMenuPrincipal(){
        this->widgets->setCurrentIndex(0);
    }
    void switchMenuOption(){
        this->widgets->setCurrentIndex(1);
    }

    //void Timer()

    QStackedWidget * widgets;
};

#endif