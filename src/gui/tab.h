#ifndef TAB_H
#define TAB_H

#include <QWidget>
#include <QIcon>
#include <QList>
#include <QMenu>

class TextEditor;
class TabWidget;

class Tab :
public QWidget {
public:
    explicit Tab(TabWidget* tabWidget);

public:
    TextEditor* GetEditor() const;

    TabType GetTabType() const;
    QIcon GetIcon() const;
    QString GetTitle() const;
    QString GetToolTip() const;

    int Index() const;

public slots:
    void RequestVisibility();

private:
    void CloseEvent(QCloseEvent* event);

private:
    TabWidget* m_tabWidget;
    TextEditor* m_editor;
    TabType m_tabType;

    QIcon m_icon; 
    QString m_title; 
    QString m_toolTip; 
};