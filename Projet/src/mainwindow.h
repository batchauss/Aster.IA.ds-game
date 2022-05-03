#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "init.h"
#include "fonctions/frontiere.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    mainwindow(int argc, char**argv);
    ~mainwindow();
};

#endif