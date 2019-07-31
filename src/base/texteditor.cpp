#include "texteditor.h"

#include "src/base/application.h"
#include "src/static/global.h"
#include "src/static/platform.h"

#include <QDir>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QFontdatabase>
#include <QMenu>
#include <QMouseEvent>
#include <QRegularExpression>
#include <QTextCodec>
#include <QTextStream>
#include <QTimer>


//--------------------------------------------------
QString TextEditor::GetFilePath() const 
{
    return m_filePath;
}

//--------------------------------------------------
void TextEditor::SetFilePath(const QString& filePath) const 
{
    m_filePath = filePath;
}

//--------------------------------------------------
QByteArray TextEditor::GetEncoding() const 
{
    return m_encoding;
}

//--------------------------------------------------
void TextEditor::SetEncoding(const QByteArray& encoding) 
{
    m_encoding = encoding;
}

//--------------------------------------------------
QByteArray TextEditor::DetectEncoding(const QString& filePath) 
{
    QByteArray fileBlock = IOModule::ReadFileBlock(filePath, k_fileDataLengthForEncodingDetection);
    
    uchardet_t charSet = uchardet_new();
    uchardet_handle_data(charSet, fileBlock.data(), fileBlock.length());
    uchardet_data_end(charSet);

    const char* charSetEncodingName = uchardet_get_charset(charSet);
    QByteArray encodingName(charSetEncodingName);
    uchardet_delete(charSet);

    if (encodingName == QString("ASCII")) {
        return k_defaultTextFileEncoding;
    }
    else {
        return encodingName;
    }
}

//--------------------------------------------------
QString TextEditor::GetEolModeAsString(int eolMode) 
{
    switch (eolMode) {
        case SC_EOL_CRLF:
        return QString("CRLF");

        case SC_EOL_CR:
        return QString("CR");

        case SC_EOL_LF:
        return QString("LF");

        default:
        return QString();
    }
}

//--------------------------------------------------
int TextEditor::DetectEol(const QString& filePath) 
{
    QByteArray fileBlock = IOModule::ReadFileBlock(filePath, k_fileDataLengthForEolDetection);

    if (fileBlock.contains(QString("\r\n").toLocal8Bit().constData())) {
        return SC_EOL_CRLF;
    }
    else if (fileBlock.contains(QString("\n").toLocal8Bit().constData())) {
        return SC_EOL_LF;
    }
    else if (fileBlock.contains(QString("\r").toLocal8Bit().constData())) {
        return SC_EOL_CR;
    }
    else {
        return -1;
    }
}

//--------------------------------------------------
bool TextEditor::GetSettings() const 
{
    return m_settings;
}

//--------------------------------------------------
void TextEditor::SetSettings(bool settings) 
{
    m_settings = settings;
}

//--------------------------------------------------
bool TextEditor::IsLog() const 
{
    return m_isLog;
}

//--------------------------------------------------
void TextEditor::SetIsLog(bool isLog) 
{
    m_isLog = isLog;

    if (m_isLog) {
        gotoPos(length());
        newLine();
        const QString dateString = QDateTime::currentDateTime().toString(m_application->settings()->logTimestampFormat());
        insertText(currentPos(), dateString.toUtf8().constData());
        gotoPos(length());
        newLine();
        setSavePoint();
    }
}

//--------------------------------------------------
bool TextEditor::IsAutoIndentOn() const
{
    return m_autoIndentOn;
}

//--------------------------------------------------
void TextEditor::SetAutoIndentOn(bool autoIndentOn) 
{
    m_autoIndentOn = autoIndentOn;
}

//--------------------------------------------------
QMessageBox::StandardButton TextEditor::IsSavePending() const 
{
    return m_savePending;
}

//--------------------------------------------------
void TextEditor::SaveAs(bool& ok, const QString& encoding) 
{
    QString filePath;
    QString filter;

    if (m_filePathOnEditorQuit.isEmpty()) {

    }
}

//--------------------------------------------------
void TextEditor::Save(bool& ok, const QString& encoding)
{
    // pending
}

//--------------------------------------------------
void TextEditor::CloseEditor(bool& ok) 
{
    if (m_app->IsSavePending() && GetFilePath().isEmpty()) {
        QString sessionFile = GetSessionFile();


    }
}

//--------------------------------------------------
QString TextEditor::RequestSaveFileName(QString& filter = nullptr) const 
{
    
}

//--------------------------------------------------
QString TextEditor::GetSessionFile() 
{
    QDir dirData(s_app->GetUserDataFolder());
    QString fileName;
    int i = 1;
    
    do {
        fileName = QString("tab_%2_%1.session").arg(k_osIdLow, QString::number(i++));
    }
    while (dirData.exists(fileName));

    return fileName;
}