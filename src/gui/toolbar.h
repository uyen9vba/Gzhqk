#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>

class ToolBar :
public QToolBar {
public:
    explicit ToolBar(const QString& title, QWidget* parent = nullptr);
    virtual ~ToolBar() = default;

public:
    QList<QAction*> GetAvailableActions() const;
    QList<QAction*> GetChangeableActions() const;
    
    void SaveChangeableActions(const QStringList& actions);

    QList<QAction*> GetSpecificActions(const QStringList& actions);
    void AddSpecificActions(const QList<QAction*>& actions);

    QStringList GetDefaultActions() const;

    QAction* FindSpecificAction(const QString& action, const QList<QAction*>& actions) const;

    bool IsActive() const;

public slots: 
    void SetIsActive(bool isActive);
    void ResetActiveState();

private:
    bool m_isActive;
};