#ifndef WINDOW_H
#define WINDOW_H 

#include <QMainWindow>

#include "defaults.h"

class Window :
public QMainWindow 
{
public:
    explicit Window(QWidget* parent = nullptr);
    virtual ~Window() = default;

public:
    

private:
    void PrepareMenus();

private:
    QList<QAction*> m_actions;
};