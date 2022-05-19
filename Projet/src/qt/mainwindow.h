#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <iostream>

#include "../objets/vaisseau.h"
#include "../init.h"
#include "../touches/actions.h"
#include "../rendu/renduPause.h"
#include "../rendu/hud.h"

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