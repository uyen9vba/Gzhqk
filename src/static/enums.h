#ifndef ENUMS_H
#define ENUMS_H

enum class SettingsType {
    k_portable,
    k_nonPortable,
    k_forced
};
Q_ENUM(SettingsType)

enum class TabType {
    k_textEditor = 1,
    k_other = 2
};
Q_ENUM(TabType)

enum class StyleComponents {
    k_default = 0,
    k_comment = 1,
    k_number = 2,
    k_string = 3,
    k_operator = 4,
    k_identifier = 5,
    k_keyword = 6,
    k_keyword2 = 7,
    k_preprocessor = 8,
    k_regex = 9,
    k_script = 10,
    k_plainData = 11,
    k_error = 12,

    // Scintilla 
    k_scintillaDefault = 1000,
    k_scintillaMargin = 1001,
    k_scintillaBraceLight = 1002,
    k_scintillaBraceBad = 1003,
    k_scintillaControlChar = 1004,
    k_scintillaIndentGuide = 1005,
    k_scintillaUrlHighlight = 1006,
    k_scintillaOccurencesHighlight = 1007,
    
};
Q_ENUM(StyleComponents)

#endif // ENUMS_H