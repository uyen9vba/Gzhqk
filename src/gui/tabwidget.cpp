#include "src/gui/tabwidget.h"

#include "src/gui/toolbutton.h"
#include "src/gui/theme.h"
#include "src/base/settings.h"
#include "src/static/defaults.h"
#include "src/base/window.h"

#include <QWidget>

class QMenu;
class ToolButton;
class TextEditor;
class Tab;

//--------------------------------------------------
TabWidget::TabWidget(QWidget* parent) :
QTabWidget(parent) 
{
    setTabBar(new TabBar(this));
    setUsesScrollButtons(true);
    setMovable(true);
    setIconSize(QSize(12, 12));
    setDocumentMode(true);
    
    CreateConnections();
}

//--------------------------------------------------
int TabWidget::AddTab(Tab* tab, const QString& label)
{
    const int index = QTabWidget::addTab(tab, label);
    
    GetTabBar()->SetTabControls(index);

    return index;
}

//--------------------------------------------------
int TabWidget::AddTab(Tab* tab, const QIcon& icon, const QString& label)
{
    const int index = QTabWidget::addTab(tab, icon, label);

    GetTabBar()->SetTabControls(index);

    return index;
}

//--------------------------------------------------
int TabWidget::InsertTab(int index, Tab* tab, const QString& label)
{
    const int index = QTabWidget::insertTab(index, tab, label);

    GetTabBar()->SetTabControls(index);

    return index;
}

//--------------------------------------------------
int TabWidget::InsertTab(int index, Tab* tab, const QIcon&, const QString& label)
{
    const int index = QTabWidget::insertTab(index, tab, icon, label);

    GetTabBar()->SetTabControls(index);

    return index;
}

//--------------------------------------------------
bool TabWidget::RemoveTab(int index, bool clearFromMemory) 
{
    auto widget = widget(index);
    bool widgetClosed = widget != nullptr && widget->close();

    if (widgetClosed) {
        if (clearFromMemory) {
            widget->deleteLater();
        }

        QTabWidget::removeTab(index);
    }

    return widgetClosed;
}

//--------------------------------------------------
Tab* TabWidget::GetTab() const 
{
    return GetTabAt(currentIndex());
}

//--------------------------------------------------
TextEditor* TabWidget::GetEditor() const 
{
    return GetTextEditorAt(currentIndex());
}

//--------------------------------------------------
Tab* TabWidget::GetTabAt(int index) const 
{
    if (index < 0 || index >= count()) {
        return nullptr;
    }
    else {
        return qobject_cast<Tab*>(widget(index));
    }
}

//--------------------------------------------------
TextEditor* TabWidget::GetEditorAt(int index) const 
{
    Tab* tab = GetTabAt(index);

    if (tab != nullptr) {
        return tab->GetEditor();
    }
    else {
        return nullptr;
    }
}

//--------------------------------------------------
int TabWidget::GetIndexOfEditor(TextEditor* editor) const 
{
    int i = 0;

    for (Tab* tab : GetTabs()) {
        if (tab->GetEditor() == editor) {
            return i;
        }
        else {
            i++;
        }
    }

    return -1;
}

//--------------------------------------------------
QList<Tab*> TabWidget::GetTabs() const 
{
    QList<Tab*> tabs;

    for (int i = 0; i < count(); i++) {
        Tab* tab = GetTabAt(i);

        if (tab != nullptr) {
            tabs.append(tab);
        }
    }

    return tabs;
}

//--------------------------------------------------
QList<TextEditor*> TabWidget::GetEditors() const 
{
    QList<TextEditor*> editors;

    for (int i = 0; i < count(); i++) {
        TextEditor* editor = GetTextEditorAt(i);

        if (editor != nullptr) {
            editors.append(editor);
        }
    }

    return editors;
}

//--------------------------------------------------
void TabWidget::CreateConnections() 
{
    connect(GetTabBar(), &TabBar::tabCloseRequested, this, &TabWidget::CloseTab);
}

//--------------------------------------------------
bool TabWidget::CloseTab(int index)
{
    return RemoveTab(index, true);
}

//--------------------------------------------------
void TabWidget::CloseAllTabsExceptCurrent() 
{
    int currentIndex = currentIndex();

    for (int i = count() - 1; i >= 0; i--) {
        if (i != currentIndex) {
            if (i < currentIndex) {
                currentIndex--;
            }

            CloseTab(i);
        }
    }
}

//--------------------------------------------------
void TabWidget::CloseAllTabs() 
{
    for (int i = count() - 1; i >= 0; i--) {
        CloseTab(i);
    }
}

//--------------------------------------------------
void TabWidget::CloseCurrentTab() 
{
    if (currentIndex() >= 0) {
        CloseTab(currentIndex());
    }
}

//--------------------------------------------------
void TabWidget::GoToNextTab() 
{
    if (currentIndex() == count() - 1) {
        setCurrentIndex(0);
    }
    else {
        setCurrentIndex(currentIndex() + 1);
    }
}

//--------------------------------------------------
void TabWidget::GoToPreviousTab() 
{
    if (currentIndex() == 0) {
        setCurrentIndex(count() - 1);
    }
    else {
        setCurrentIndex(currentIndex() - 1);
    }
}

//--------------------------------------------------
void TabWidget::ChangeTitle(int index, const QString& title) 
{
    setTabText(index, title);
    setTabToolTip(index, title);
}

//--------------------------------------------------
void TabWidget::ChangeIcon(int index, const QIcon& icon) 
{
    setTabIcon(index, icon);
}