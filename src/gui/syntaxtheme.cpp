#include "src/gui/syntaxtheme.h"

#include "src/static/defaults.h"
#include "src/base/texteditor.h"

#include <QDebug>
#include <QList>
#include <QMetaEnum>
#include <QSettings>

#include <utility>
//--------------------------------------------------
SyntaxTheme::SyntaxTheme(
    QString name,
    QMap<SyntaxComponents, SyntaxStyles> styles 
) :
m_name(std::move(name)),
m_styles(std::move(styles))
{}

//--------------------------------------------------
QString SyntaxTheme::GetName() const 
{
    return m_name;
}

//--------------------------------------------------
SyntaxStyles SyntaxTheme::GetComponent(SyntaxComponents key) 
{
    return m_styles.value(key);
}

//--------------------------------------------------
QMap<SyntaxComponents, SyntaxStyles> SyntaxTheme::GetStyles() const 
{
    return m_styles;
}

//--------------------------------------------------
bool SyntaxTheme::HasComponent(SyntaxComponents key) const 
{
    return m_styles.contains(key);
}

//--------------------------------------------------
void SyntaxTheme::SetName(const QString& name) 
{
    m_name = name;
}

//--------------------------------------------------
void SyntaxTheme::SetComponent(SyntaxComponents key, const SyntaxStyles& value) 
{
    m_styles[key] = value;
}

//--------------------------------------------------
void SyntaxTheme::ClearStyles() 
{
    m_styles.clear();
}

//--------------------------------------------------
void SyntaxTheme::RemoveComponent(SyntaxComponents key) 
{
    m_styles.remove(key);
}