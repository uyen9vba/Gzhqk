#ifndef DEFAULTS_H
#define DEFAULTS_H

#include <QtGlobal>

// Path defaults 
constexpr auto k_appThemePath = ":/graphics";
constexpr auto k_appInfoPath = ":/text";
constexpr auto k_appIconPath = ":/graphics/noc.png";

// Indicator defaults
constexpr auto k_indicatorUrl = 0;
constexpr auto k_indicatorFind = 1;

// Margin defaults
constexpr auto k_marginLineNumbersMinWidth = 10;
constexpr auto k_marginLineNumbers = 0;
constexpr auto k_marginSymbols = 1;
constexpr auto k_marginFolding = 2;
constexpr auto k_marginLineNumbersRightSpace = SC_MAX_MARGIN + 1;
constexpr auto k_marginPaddingLineNumbers = 7;
constexpr auto k_marginWidthFolding = 18;

// Line defaults
constexpr auto k_lineSpacingMin = 10;
constexpr auto k_lineSpacingMax = 50;

// Other defaults
constexpr auto k_changeEventDelay = 250;
constexpr auto k_formatDatetimeOutput = "yyyy-MM-dd HH:mm:ss";
constexpr auto k_fileDataLengthForEolDetection = 1024;
constexpr auto k_fileDataLengthForEncodingDetection = 2048;
constexpr auto k_defaultTextFileEncoding = "UTF-8";
constexpr auto k_bigTextFileSize = qint64(15000000);
constexpr auto k_maxTextFileSize = qint64(std::numeric_limits<int>::max());
constexpr auto k_argumentsListSeparator = "\n";
constexpr auto k_releasesList = "https://api.github.com/repos/salsv/noc/releases";
constexpr auto k_defaultLocale = "en";
constexpr auto k_iconSizeSettings = 16;
constexpr auto k_downloadTimeout = 20000;
constexpr auto k_ellipsisLength = 3;
constexpr auto k_flagIconSubFolder = "flags";
constexpr auto k_spacerActionName = "spacer";
constexpr auto k_separatorActionName = "separator";
constexpr auto k_maxRecentFiles = 25;

// Application defaults 
constexpr auto k_appCfgFile = "config.ini";
constexpr auto k_appDefaultStyle = "Fusion";
constexpr auto k_appDefaultTheme = "Papirus";
constexpr auto k_appNoTheme = "";
constexpr auto k_appThemeSuffix = ".png";
constexpr auto k_appQuitInstanceShort = "q";
constexpr auto k_appQuitInstance = "quitapp";
constexpr auto k_appNoSingleInstanceShort = "n";
constexpr auto k_appNoSingleInstance = "no-single-instance";
constexpr auto k_appOptConfigShort = "c";
constexpr auto k_appOptConfig = "config";
constexpr auto k_appIsRunningShort = "r";
constexpr auto k_appIsRunning = "app-is-running";

//--------------------------------------------------
// Settings
constexpr auto k_defaultLogTimestampFormat = "yyyy-MM--dd HH:mm:ss";
constexpr auto k_defaultTabSize = 2;
constexpr auto k_defaultEdgeLongLine = false;
constexpr auto k_defaultEdgeLongLineColumn = 60;
constexpr auto k_defaultIndentSize = 2;
constexpr auto k_defaultIndentWithTabs = false;
constexpr auto k_defaultLineSpacing = 0;
constexpr auto k_defaultReloadModified = false;
constexpr auto k_defaultWordWrap = true;
constexpr auto k_defaultLineNumbers = false;
constexpr auto k_defaultContextAwareHighlights = false;
constexpr auto k_defaultCodeFolding = false;
constexpr auto k_defaultAutoIndent = true;
constexpr auto k_defaultViewEols = false;
constexpr auto k_defaultViewWhiteSpace = false;
const QString k_defaultLoadSaveDirectory = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

// GUI
constexpr auto k_defaultStatusBarVisible = true;
constexpr auto k_defaultStayOnTop = false;
constexpr auto k_defaultTabCloseMiddleClick = true;
constexpr auto k_defaultTabCloseDoubleclick = true;
constexpr auto k_defaultTabNewDoubleClick = true;
constexpr auto k_defaultToolbarsVisible = true;
constexpr auto k_defaultToolbarStyle = Qt::ToolButtonIconOnly;
constexpr auto k_defaultToolbarActions = 
    "m_actionFileNew, m_actionFileOpen, m_actionFileSave, separator,"
    "m_actionEditBack, m_actionEditForward, spacer, m_actionTabsCloseAllUnmodified";

constexpr auto k_defaultIsMainWindowMaximizedBeforeFullscreen = false;
constexpr auto k_defaultHideMainWindowWhenMinimized = true;
constexpr auto k_defaultHideMainWindowWhenClosed = true;
constexpr auto k_defaultUseTrayIcon = false;
constexpr auto k_defaultEnableNotifications = true;
constexpr auto k_defaultRestoreSession = true; 
constexpr auto k_defaultRestoreSessionIndex = -1;
const QStringList k_defaultRestoreSessionFiles = QStringList();
const auto k_defaultLanguage = QLocale::system().name();

#endif // DEFAULTS_H
