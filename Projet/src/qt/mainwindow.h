#pragma once

#include <QMainWindow>
#include <QtWidgets>
#include <iostream>

#include "../objets/vaisseau.h"
#include "../init.h"
#include "../touches/actions.h"
#include "../rendu/renduPause.h"
#include "../rendu/hud.h"
#include "../fonctions/finJeu.h"

#include "../../includes/config.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT;
    
public:
    mainwindow(int argc, char**argv);
    ~mainwindow() = default;

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
