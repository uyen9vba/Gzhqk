#ifndef SYNTAXSTYLES_H
#define SYNTAXSTYLES_H

#include <QColor>

struct SyntaxStyles {
public:
    explicit SyntaxStyles() = default;
    explicit SyntaxStyles(
        QColor foregroundColor,
        QColor backgroundColor = QColor(),
        bool bold = false, 
        bool italic = false,
        bool underline = false,
    );

    void ApplyToEditor(TextEditor& editor, int style);

public:
    QColor m_foregroundColor;
    QColor m_backgroundColor;

    bool m_boldFont;
    bool m_italicFont;
    bool m_underlineFont;
};