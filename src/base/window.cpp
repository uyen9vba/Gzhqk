#include "window.h"

#include <QCloseEvent>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMetaObject>
#include <QRect>
#include <QScopedPointer>
#include <QThread>
#include <QTimer>

//--------------------------------------------------
Window::Window(QWidget* parent) : 
QMainWindow(parent) 
{
    m_application
}

//--------------------------------------------------
void Window::PrepareMenus 
{
    #if defined(Q_OS_MAC)
    s_window.m_actionFullscreen->setVisible(false);
    #endif
}

