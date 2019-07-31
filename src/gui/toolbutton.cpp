#include "src/cmp/toolbutton.h"
#include "src/static/defaults.h"

#include <QAction>
#include <QPainter>
#include <QPaintEvent>
#include <QStyle>
#include <QStyleOption>
#include <QToolButton>

//--------------------------------------------------
ToolButton::ToolButton(QWidget* parent) :
QToolButton(parent)
{}

//--------------------------------------------------
QColor ToolButton::GetColor() const 
{
    return m_color;
}

//--------------------------------------------------
void ToolButton::SetColor(const QColor& color) const 
{
    m_color = color;
    repaint();
}

//--------------------------------------------------
bool ToolButton::GetPaintPlaceholder() 
{
    return m_paintPlaceholder;
}

//--------------------------------------------------
void ToolButton::SetPaintPlaceholder(bool paintPlaceholder) 
{
    m_paintPlaceholder = paintPlaceholder;
}

//--------------------------------------------------
void ToolButton::PaintEvent(QPaintEvent* e) 
{
    QPainter painter(this);
    QRect rect(
        m_paddingLeft, m_paddingTop,
        size().width() - m_paddingLeft - m_paddingRight,
        size().height() - m_paddingTop - m_paddingBottom
    );

    if (isEnabled())
    {
        if (underMouse() || isChecked()) 
        {
            painter.setOpacity(0.75);
        }
    }
    else 
    {
        p.setOpacity(0.25);
    }
}

//--------------------------------------------------
void ToolButton::SetPadding(int left, int top, int right, int bottom) 
{
    m_paddingLeft = left;
    m_paddingTop = top;
    m_paddingRight = right;
    m_paddingBottom = bottom;
    repaint();
}

//--------------------------------------------------
void SetChecked(bool checked) 
{
    QToolButton::setChecked(checked);
    repaint();
}

//--------------------------------------------------
void OnActionChange(QAction* action) 
{
    if (action != nullptr) 
    {
        setEnabled(action->isEnabled());
        setCheckable(action->isCheckable());
        setChecked(action->isChecked());
        setIcon(action->icon());
        setToolTip(action->toolTip());
    }
}

//--------------------------------------------------
void OnSenderActionChange() 
{
    OnActionChange(qobject_cast<QAction*>(sender()));
}




