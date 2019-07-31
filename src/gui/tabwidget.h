#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "src/static/defaults.h"
#include "src/gui/tabbar.h" 

#include <QTabWidget>

class QMenu;
class ToolButton;
class TextEditor;
class Tab;

class TabWidget :
public QTabWidget {
public:
    explicit TabWidget(QWidget* parent = nullptr);
    virtual ~TabWidget() = default;

public:
    int AddTab(Tab* tab, const QString& label);
    int AddTab(Tab* tab, const QIcon& icon, const QString& label);
    int InsertTab(int index, Tab* tab, const QString& label);
    int InsertTab(int index, Tab* tab, const QIcon& icon, const QString& label);
    bool RemoveTab(int index, bool clearFromMemory);

    Tab* GetTab() const;
    TextEditor* GetEditor() const;
    
    Tab* GetTabAt(int index) const;
    TextEditor* GetEditorAt(int index) const;
    int GetIndexOfEditor(TextEditor* editor) const;

    QList<Tab*> GetTabs() const;
    QList<TextEditor*> GetEditors() const;

    void CreateConnections();

    TabBar* GetTabBar() const;

public slots:
    bool CloseTab(int index);
    void CloseAllTabsExceptCurrent();
    void CloseAllTabs();
    void CloseCurrentTab();

    void GoToNextTab();
    void GoToPreviousTab();

private slots: 
    void ChangeTitle(int index, const QString& title);
    void ChangeIcon(int index, const QIcon& icon);
};

//--------------------------------------------------
inline TabBar* TabWidget::GetTabBar() const 
{
    return static_cast<TabBar*>(QTabWidget::tabBar());
}

#endif // TABWIDGET_H