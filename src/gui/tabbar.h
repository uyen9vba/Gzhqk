#ifndef TABBAR_H 
#define TABBAR_H 

#include <QTabBar>

class TabBar :
public QTabBar {
public:
    explicit TabBar(QWidget* parent = nullptr);
    virtual ~TabBar() = default;

public:
    void SetTabControls(int index);

private slots:
    void CloseTabViaButton();

private:
    void MouseDoubleClickEvent(QMouseEvent* event);
    void MousePressEvent(QMouseEvent* event);
    void WheelEvent(QWheelEvent* event);

signals:
    void EmptySpaceDoubleClicked();
};

#endif