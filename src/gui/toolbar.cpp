#include "src/gui/toolbar.h"

#include "src/gui/theme.h"
#include "src/base/settings.h"
#include "src/base/application.h"
#include "src/static/global.h"

#include <QWidgetAction>

//--------------------------------------------------
ToolBar::ToolBar(const QString& title, QWidget* parent) :
QToolBar(title, parent) 
{
    setIconSize(QSize(20, 20));
    setFloatable(false);
    setMovable(false);
    refreshVisualProperties();
}

//--------------------------------------------------
QList<QAction*> ToolBar::GetAvailableActions() const 
{
    return s_app->GetActions();
}

//--------------------------------------------------
QList<QAction*> ToolBar::GetChangeableActions() const 
{
    return actions();
}

//--------------------------------------------------
void ToolBar::SaveChangeableActions(const QStringList& actions) 
{
    AddSpecificActions(GetSpecificActions(actions));
}

//--------------------------------------------------
QList<QAction*> ToolBar::GetSpecificActions(const QStringList& actions) 
{
    QList<QAction*> availableActions = GetAvailableActions();
    QList<QAction*> specificActions;

    for (const QString& actionName : actions) {
        QAction* specificAction = FindSpecificAction(actionName, availableActions);

        if (specificAction != nullptr) {
            specificActions.append(specificAction);
        }
        else if (actionName == k_separatorActionName) {
            QAction* action = new QAction(this);

            action->setSeparator(true);
            specificActions.append(action);
        }
        else if (actionName == k_spacerActionName) {
            QWidget* spacer = new QWidget(this);
            spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            
            QWidgetAction* widgetAction = new QWidgetAction(this);
            widgetAction->setDefaultWidget(spacer);
            widgetAction->setIcon(s_app->m_theme->GetIconFromTheme(QString("go-jump")));
            widgetAction->setProperty("type", k_spacerActionName);
            widgetAction->setProperty("name", tr("Toolbar spacer"));
            
            specificActions.append(widgetAction);
        }
    }

    return specificActions;
}

//--------------------------------------------------
void ToolBar::AddSpecificActions(const QList<QAction*>& actions) 
{
    clear();

    for (QAction* i : actions) {
        addAction(i);
    }
}

//--------------------------------------------------
QStringList ToolBar::GetDefaultActions() const 
{
    return QString(k_defaultToolbarActions).split((','), QString::SkipEmptyParts);
}

//--------------------------------------------------
QAction* ToolBar::FindSpecificAction(const QString& action, const QList<QAction*>& actions) const 
{
    for (QAction* i : actions) {
        if (i->objectName() == action) {
            return i;
        }
    }

    return nullptr;
}

//--------------------------------------------------
bool ToolBar::IsActive() const 
{
    return m_isActive;
}

//--------------------------------------------------
void ToolBar::SetIsActive(bool isActive) 
{
    m_isActive = isActive;
    setVisible(m_isActive);
}

//--------------------------------------------------
void ToolBar::ResetActiveState() 
{
    SetIsActive(m_isActive);
}