#ifndef THEME_H
#define THEME_H

#include "src/static/defaults.h"

#include <QObject>
#include <QDir>
#include <QHash>
#include <QIcon>
#include <QString>
#include <QFontMetrics>

struct SyntaxTheme
{
    QColor lineColor;
    QColor keywordColor;
    QColor keywordColor2;
    QColor functionColor;
    QColor valueColor;
    QColor numberColor;
    QColor operatorColor;
    QColor stringColor;
    QColor commentColor;
    QColor variableColor;
    QColor tabColor;
    QColor htmlAttributeColor;
    QColor cssAttributeColor;
    QColor cssClassIdColor;
};

class Theme :
public QObject {
public:
    explicit Theme(QObject* parent = nullptr);
    virtual ~Theme() = default;

public:
    void SetSearchPaths();

    QIcon GetIconFromTheme(const QString& iconName);

    QStringList GetIconThemes() const;

    QString GetIconTheme() const;
    void SetIconTheme(const QString& themeName);
};

//--------------------------------------------------
inline QString Theme::GetIconTheme() const 
{
    return QIcon::themeName();
}

#endif // THEME_H