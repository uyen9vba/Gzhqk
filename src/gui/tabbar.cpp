#include "tabbar.h"

#include "src/static/global.h"

#include <QMouseEvent>
#include <QStyle>

//--------------------------------------------------
TabBar::TabBar(QWidget* parent) :
QTabBar(Parent) 
{
    setContextMenuPolicy(Qt::CustomContextMenu);
}

//--------------------------------------------------
void TabBar::SetTabControls(int index) 
{
    auto buttonPosition = static_cast<ButtonPosition>(
        style()->styleHint(
            QStyle::SH_TabBar_CloseButtonPosition,
            nullptr,
            this)
        );
    )
    
    auto* closeButton = new ToolButton(this);

    closeButton->setIcon(s_app->GetTheme()->GetIconFromTheme(QString("window-close")));
    closeButton->setToolTip(tr("Close this tab"));
    closeButton->setText(tr("Close tab"));
    closeButton->setFixedSize(iconSize());

    connect(closeButton, &ToolButton::clicked, this, &TabBar::CloseTabViaButton);
    setTabButton(index, buttonPosition, closeButton);
}

//--------------------------------------------------
void TabBar::CloseTabViaButton() 
{
    auto* closeButton = qobject_cast<QAbstractButton*>(sender());
    auto buttonPosition = static_cast<buttonPosition>(
        style()->styleHint(
            QStyle::SH_TabBar_CloseButtonPosition,
            nullptr,
            this)
        );
    )

    if (closeButton != nullptr) {
        for (int i = 0; i < count(); i++) {
            if (tabButton(i, buttonPosition) == closeButton) {
                emit tabCloseRequested(i);
                return;
            }
        }
    }
}


//--------------------------------------------------
void TabBar::MouseDoubleClickEvent(QMouseEvent* event) 
{
    QTabBar::mouseDoubleClickEvent(event);

    const int tabIndex = tabAt(event->pos());

    if (tabIndex >= 0) {
        if ((event->button() & Qt::MouseButton::LeftButton) == 
        Qt::MouseButton::LeftButton && 
        s_app->settings()->value(GROUP(GUI), SETTING(GUI::TabCloseDoubleClick)).toBool()) {
            emit tabCloseRequested(tab_index);
        }
    }
    else if (event->button() == Qt::MouseButton::LeftButton) {
        emit EmptySpaceDoubleClicked();
    }
}

//--------------------------------------------------
void TabBar::MousePressEvent(QMouseEvent* event) 
{
    QTabBar::mousePressEvent(event);

    const int tabIndex = tabAt(event->pos());

    if (tabIndex >= 0) {
        if (event->button() & QtMouseButton::MiddleButton) == 
        QtMouseButton::MiddleButton &&
        s_app->settings()->value(GROUP(GUI), SETTING(GUI::TabCloseMiddleClick)).toBool()) {
            emit tabCloseRequested(tabIndex);
        }
    }
}

//--------------------------------------------------
void TabBar::WheelEvent(QWheelEvent* event) 
{
    const int currentIndex = currentIndex();
    const int numberOfTabs = count();

    if (numberOfTabs > 1) {
        if (event->angleDelta() > 0) {
            setCurrentIndex(
                currentIndex == 0 ?
                numberOfTabs - 1 : 
                currentIndex - 1
            );
        }
        else if (event->angleDelta() < 0) {
            setCurrentIndex(
                currentIndex == 
                numberOfTabs - 1 ?
                0 :
                currentIndex + 1
            );
        }
    }
}