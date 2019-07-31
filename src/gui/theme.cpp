#include "src/gui/theme.h"

#include <QBuffer>

//--------------------------------------------------
Theme::Theme(QObject* parent) :
QObject(parent) 
{}

//--------------------------------------------------
void Theme::SetSearchPaths() 
{
    QIcon::setThemeSearchPaths(QIcon::themeSearchPaths() << k_appThemePath);
}

//--------------------------------------------------
QStringList Theme::GetIconThemes() const 
{
    QStringList iconThemes;
    iconThemes << k_appNoTheme;

    QStringList iconThemesPaths = QIcon::themeSearchPaths();
    iconThemesPaths.removeDuplicates();

    QString themeIndex = "index.theme";
    
    for (const QString& iconPath : iconThemesPaths) {
        const QDir iconDir(iconPath);

        for (const QFileInfo& iconThemePath : iconDir.entryInfoList(
            QDir::Dirs | QDir::NoDotsAndDotDot | QDir::Readable |
            QDir::CaseSensitive | QDir::NoSymLinks | QDir::Time
            )) {
            QDir iconThemeDir(iconThemePath.absoluteFilePath());

            if (iconThemeDir.exists(themeIndex.at(0))) {
                iconThemes << iconThemeDir.dirName();
            }
        }
    }

    iconThemes.removeDuplicates();
    return iconThemes;
}

//--------------------------------------------------
void Theme::SetIconTheme(const QString& themeName) 
{
    const QStringList iconThemes = GetIconThemes();

    if (GetIconTheme() == themeName) {
        qDebug("Icon theme '%s' already loaded.", qPrintable(themeName));
        return;
    }

    if (iconThemes.contains(themeName)) {
        QIcon::setThemeName(themeName);
    }
    else {
        QIcon::setThemeName(k_appNoTheme);
    }
}