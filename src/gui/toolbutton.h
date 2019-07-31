#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H 

#include <QToolButton>

class ToolButton :
public QToolButton {
public:
    explicit ToolButton(QWidget* parent = nullptr);
    virtual ~ToolButton = default;

public:
    QColor GetColor() const;
    void SetColor(const QColor& color);

    bool GetPaintPlaceholder() const;
    void SetPaintPlaceholder(bool paintPlaceholder);

    void PaintEvent(QPaintEvent* e);

public slots: 
    void SetPadding(int left, int top, int right, int bottom);
    void SetChecked(bool checked);

    void OnActionChange(QAction* action);
    void OnSenderActionChange();

private:
    QColor m_color;
    int m_paddingLeft = 0;
    int m_paddingTop = 0;
    int m_paddingRight = 0;
    int m_paddingBottom = 0;
    bool m_paintPlaceholder = true;
};

#endif // TOOLBUTTON_H