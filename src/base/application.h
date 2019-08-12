#ifndef APPLICATION_H
#define APPLICATION_H 

#include "src/gui/theme.h"
#include "src/base/settings.h"
#include "src/base/texteditor.h"

#include <functional>

#include <QCommandLineParser>
#include <QList>
#include <QMessageBox>
#include <QObject>
#include <QIcon>

class Application :
public QApplication,
public QObject {
public:
    explicit Application(int& argc, char** argv);
    virtual ~Application() = default;

public:
    QList<QAction*> GetActions() const;
    void SetActions();

    QList<QMenu*> GetMenus() const;
    void SetMenus();

    QString GetHomeFolder();
    QString GetConfigFolder();
    QString GetUserDataFolder();

    Settings* GetSettings() const;

    Window* GetWindow() const;
    void SetWindow(Window* window);

    Theme* GetTheme() const;
    QWidget* GetWindowWidget();
    QCommandLineParser* GetCmdParser();

    bool IsSavePending() const;

public slots: 
    void Undo();
    void Redo();

    void ProcessCommandLineArguments();

    void NewFile();
    void OpenTextFile(QAction* action = nullptr);
    void ReopenTextFile(QAction* action);
    void LoadFilesFromArgs(const QList<QString>& files);
    void LoadTextEditorFromString(const QString& contents);
    TextEditor* LoadTextEditorFromFile(
        const QString& filePath,
        const QString& encoding = QString(),
        const QString& fileFilter = QString(),
        bool restoreSession = false
    );


    void QuitApplication();
    void Restart();

    bool IsQuitting() const;

    QString GetUserDataAppFolder();
    QString GetUserDataHomeFolder();
    QString GetUserDataForcedFolder();

private:
    QCommandLineParser m_cmdParser;
    Settings* m_settings;
    Window* m_window; 
    Theme* m_theme;

    QList<QAction*> m_actions;
    QList<QMenu*> m_menus;

    bool m_restartPending;
    bool m_savePending;
    bool m_isQuitting;
};

#endif
