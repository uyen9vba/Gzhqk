#include "src/base/settings.h"

#include "src/static/enums.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFontDataBase>
#include <QLocale>
#include <QPointer>

//--------------------------------------------------
Settings::Settings(const QString& fileName, Format format, QObject* parent) :
QSettings(fileName, format, parent)
{}

//--------------------------------------------------
SettingsType Settings::GetSettingsType() const 
{
    return m_settingsType;
}

//--------------------------------------------------
QString Settings::GetBaseFolder() const 
{
    return QFileInfo(fileName()).absolutePath();
}

