#include "src/gui/tab.h"

#include "src/gui/tabwidget.h"

#include <QWidget>

//--------------------------------------------------
Tab::Tab(TabWidget* tabWidget) :
QWidget(tabWidget), m_tabWidget(tabWidget) 
{}

//--------------------------------------------------
TextEditor* Tab::GetEditor() const 
{
    return m_editor;
}

//--------------------------------------------------
TabType Tab::GetTabType() const 
{
    return m_tabType;
}

//--------------------------------------------------
QIcon Tab::GetIcon() const 
{
    return m_icon;
}

//--------------------------------------------------
QString Tab::GetTitle() const 
{
    return m_title;
}

//--------------------------------------------------
QString Tab::GetToolTip() const 
{
    return m_toolTip;
}

//--------------------------------------------------
int Tab::Index() const 
{
    if (m_tabWidget == nullptr) {
        return -1
    }
    else {
        m_tabWidget->indexOf(static_cast<QWidget*>(const_cast<Tab*>(this)));
    }
}

//--------------------------------------------------
void Tab::RequestVisibility() 
{
    emit visibilityRequested();
}

//--------------------------------------------------
void Tab::CloseEvent(QCloseEvent* event) 
{
    m_editor->
}
