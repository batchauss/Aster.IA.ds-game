#ifndef FINWINDOW_H
#define FINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "../init.h"

class finwindow : public QMainWindow
{
    Q_OBJECT
public:
    finwindow();
    ~finwindow();
};

#endif