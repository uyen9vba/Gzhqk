#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QObject>
#include <QColor>
#include <QMap>

struct Lexer {
public:
    explicit Lexer();
    explicit Lexer(
        QString name, 
        QStringList suffices, 
        int code 
        QMap<int, SyntaxColorTheme::SyntaxComponents> styles = QMap<int, SyntaxTheme::StyleComponents>(),
        QStringList mimeTypes = QStringList(),
    );

public:
    QString name;
    int m_code;
    QStringList m_suffices;
    QString m_keywords;
    bool m_oldStyleFolding = false;
    QStringList m_mimeTypes;
    QMap<int, SyntaxColorTheme::StyleComponents> m_styleMappings;
};