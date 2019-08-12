#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H 

#include <QFile>
#include <QMessageBox>

class Application;
class QFileSystemWatcher;

class TextEditor : 
public ScintillaEdit {
public:
    explicit TextEditor(Application* application, QWidget* parent = nullptr);
    virtual ~TextEditor() = default;

public:
    QString GetFilePath() const;
    void SetFilePath(const QString& filePath);

    QByteArray GetEncoding() const;
    void SetEncoding(const QByteArray& encoding);

    static QByteArray DetectEncoding(const QString& filePath);
    static QString GetEolModeAsString(int eolMode);

    // Returns Scintilla EOL enumeration
    static int DetectEol(const QString& filePath); 

    bool GetSettings() const;
    void SetSettings(bool settings);

    bool IsLog() const;
    void SetIsLog(bool isLog);

    bool IsAutoIndentOn() const;
    void SetAutoIndentOn(bool autoIndentOn);

    QMessageBox::StandardButton IsSavePending() const;

public slots:
    void SaveAs(bool& ok, const QString& encoding = QString()); // pending
    void Save();

    void CloseEditor(bool& ok);

private slots:
    QString RequestSaveFileName(QString* filter = nullptr) const; 
    
    QString GetSessionFile();

private:
    Application* m_app;
    Lexer m_lexer;

    QMessageBox::StandardButton m_savePending;
    QFileSystemWatcher* m_fileWatcher;
    QString m_filePath;
    QString m_filePathOnEditorQuit;
    QByteArray m_encoding;

    bool m_autoIndentOn;
    bool m_isLog;
    bool m_settings;
};



