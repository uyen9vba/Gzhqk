#ifndef SETTINGS_H
#define SETTINGS_H 

#include "src/static/defaults.h"
#include "src/static/enums.h"

#include <QSettings>
#include <QByteArray>
#include <QDateTime>
#include <QLocale>
#include <QStandardPaths>
#include <QStringList>
#include <QString>

class Settings :
public QSettings {
public:
    explicit Settings(const QString& fileName, Format format, QObject* parent = nullptr);
    virtual ~Settings() = default;

public:
    SettingsType GetSettingsType() const;
    
    QString GetBaseFolder() const;
    
private:
    SettingsType m_settingsType;
    QString m_baseDirectory;
    QString m_settingsSuffix;
    QString m_absoluteSettingsFileName;
};

#endif // SETTINGS_H