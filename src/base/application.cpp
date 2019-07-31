#include "application.h"

#include "src/base/window.h"

#include <QProcess>
#include <QSessionManager>


// --------------------------------------------------
Application::Application(const QString& id, int& argc, char** argv) :
QtSingleApplication(id, argc, argv), 
m_settings(nullptr),
m_should_restart(false),
m_isQuitting(false) 
{
    
}

//--------------------------------------------------
QList<QAction*> Application::GetActions() const 
{
    return m_actions;
}

//--------------------------------------------------
void Application::SetActions() 
{
    m_actions << s_window.m_actionSettings;
    m_actions << s_window.m_actionRestart;
    m_actions << s_window.m_actionQuit;

    m_actions << s_window.m_actionFileNew;
    m_actions << s_window.m_actionFileOpen;
    m_actions << s_window.m_actionFileSave;
    m_actions << s_window.m_actionFileSaveAs;
    m_actions << s_window.m_actionFileSaveAll;
    m_actions << s_window.m_actionFileReload;

    m_actions << s_window.m_actionEolUnix;
    m_actions << s_window.m_actionEolWindows;
    m_actions << s_window.m_actionEolMac;
    m_actions << s_window.m_actionEolConvertUnix;
    m_actions << s_window.m_actionEolConvertWindows;
    m_actions << s_window.m_actionEolConvertMac;
    
    m_actions << s_window.m_actionFindReplace;
    m_actions << s_window.m_actionEditBack;
    m_actions << s_window.m_actionEditForward;
    m_actions << s_window.m_actionCodeFolding;
    m_actions << s_window.m_actionLineNumbers;
    m_actions << s_window.m_actionWordWrap;
    m_actions << s_window.m_actionStayOnTop;
    m_actions << s_window.m_actionViewEols;
    m_actions << s_window.m_actionViewWhitespaces;
    m_actions << s_window.m_actionContextAwareHighlighting;
    m_actions << s_window.m_actionAutoIndentEnabled;

    m_actions << s_window.m_actionAboutGuard;
    m_actions << s_window.m_actionSwitchMainWindow;
    m_actions << s_window.m_actionSwitchStatusBar;
    m_actions << s_window.m_actionTabsNext;
    m_actions << s_window.m_actionTabsPrevious;
    m_actions << s_window.m_actionTabsCloseAll;
    m_actions << s_window.m_actionTabsCloseCurrent;
    m_actions << s_window.m_actionTabsCloseAllExceptCurrent;
    m_actions << s_window.m_actionTabsCloseAllUnmodified;
}

// --------------------------------------------------
QList<QMenu*> Application::GetMenus() const 
{
    return m_menus;
}

// --------------------------------------------------
void Application::SetMenus() 
{
    m_menus << QMenu* m_menuDockWidgets;

    m_menus << QMenu* m_menuFileSaveWithEncoding;
    m_menus << QMenu* m_menuFileOpenWithEncoding;
    m_menus << QMenu* m_menuFileReopenWithEncoding;

    m_menus << QMenu* m_menuEolMode;
    m_menus << QMenu* m_menuEolConversion;

    m_menus << QMenu* m_menuEdit;
    m_menus << QMenu* m_menuView;
    m_menus << QMenu* m_menuViewInvisibles;
    m_menus << QMenu* m_menuTools;
    m_menus << QMenu* m_menuRecentFiles;
    m_menus << QMenu* m_menuLanguage;
    m_menus << QMenu* m_menuEncoding;
}

// --------------------------------------------------
QString Application::GetHomeFolder() 
{
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
}

// --------------------------------------------------
QString Application::GetConfigFolder() 
{
    return QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
}

//--------------------------------------------------
QString Application::GetUserDataFolder() 
{
    if (GetSettings()->GetSettingsType() == SettingsType::Portable) {
        return GetUserDataAppFolder();
    }
    else {
        return GetUserDataHomeFolder();
    }
}

// --------------------------------------------------
Settings* Application::GetSettings() const 
{
    return m_settings;
}

// --------------------------------------------------
Window* Application::GetWindow() const
{
    return m_window;
}

// --------------------------------------------------
void Application::SetWindow(Window* window) 
{
    m_window = window;
}

// --------------------------------------------------
Theme* Application::GetTheme() const 
{
    return m_theme;
}

// --------------------------------------------------
QWidget* Application::GetWindowWidget() 
{
    return m_window;
}

// --------------------------------------------------
QCommandLineParser* Application::GetCmdParser() 
{
    return &m_cmdParser;
}

// --------------------------------------------------
bool Application::IsSavePending() const 
{
    return m_savePending;
}

// --------------------------------------------------
void Application::QuitApplication() 
{
    if (m_window != nullptr) {
        m_isQuitting - true;
        bool closed = m_window->close();

        if (closed) {
            quit();
        }
        else {
            m_isQuitting = false;
            m_shouldRestart = false;
        }
    }
}
// --------------------------------------------------
void Application::Restart() 
{
    m_shouldRestart = true;
    QuitApplication();
}

// --------------------------------------------------
bool Application::IsQuitting() const
{
    return m_isQuitting;
}

// --------------------------------------------------
QString Application::GetUserDataAppFolder() 
{
    return applicationDirPath() + QDir::separator() + QString("data");
}

// --------------------------------------------------
QString Application::GetUserDataHomeFolder() 
{
    return configFolder();
}

// --------------------------------------------------
QString Application::GetUserDataForcedFolder() 
{
    // pending
}