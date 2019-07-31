#ifndef PLATFORM_H
#define PLATFORM_H 

#include "src/static/defaults.h"

// Platform ids
#if defined(Q_OS_LINUX) 
constexpr auto k_osId = "Linux";
constexpr auto k_osIdLow = "linux";
#elif defined(Q_OS_MACOS)
constexpr auto k_osId = "Mac OS X";
constexpr auto k_osIdLow = "maxosx";
#elif defined(Q_OS_WIN) 
constexpr auto k_osId = "Windows";
constexpr auto k_osIdLow = "windows";
#else 
constexpr auto k_osId = "";
constexpr auto k_osIdLow = "";
#endif 

// Linux desktop entry
#if defined(Q_OS_LINUX) 
constexpr auto k_appDesktopEntryFile = "io.github.salsv.noc.desktop";
constexpr auto k_appDesktopEntryPath = ":/desktop";
#endif 

// Platform eol modes
#if defined(Q_OS_WIN) 
constexpr auto k_eolModeDefault = SC_EOL_CRLF;
#elif defined(Q_OS_MACOS) 
constexpr auto k_eolModeDefault = SC_EOL_CR;
#else
constexpr auto k_eolModeDefault = SC_EOL_LF;
#endif

// Icon theme
#if define(Q_OS_LINUX) 
constexpr auto k_defaultIconTheme = k_appNoTheme;
#else 
constexpr auto k_defaultIconTheme = k_appDefaultTheme;
#endif

#endif // PLATFORM_H