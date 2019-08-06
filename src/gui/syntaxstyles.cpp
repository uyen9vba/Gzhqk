#include "src/gui/syntaxstyles.h"

//--------------------------------------------------
SyntaxStyles::SyntaxStyles(
    QColor foregroundColor,
    QColor backgroundColor,
    bool boldFont,
    bool italicFont,
    bool underlineFont
) :
m_foregroundColor(std::move(foregroundColor)),
m_backgroundColor(std::move(backgroundColor)),
m_boldFont(boldFont),
m_italicFont(italicFont),
m_underlineFont(underlineFont)
{}

//--------------------------------------------------
