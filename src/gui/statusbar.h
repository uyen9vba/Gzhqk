#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QLabel>

class StatusBar :
public QStatusBar {
public:
    explicit StatusBar(QWidget* parent = nullptr);
    virtual ~StatusBar() = default;

public:
    void SetEol(int eolMode);
    void SetEncoding(const QString& encoding);
    void SetFileType(const QString& fileType);

    bool IsActive() const;

public slots: 
    void SetIsActive(bool isActive);
    void ResetActiveState();

private:
    void UpdateInfo();

private:
    QLabel* m_labelInfo;
    QString m_scopeInfo;
    QString m_lineInfo;
    QString m_columnInfo;
    QString m_indentInfo;
    QString m_encodingInfo;
    QString m_eolInfo;
    QString m_lexerInfo; 
    QString m_osInfo;
    bool m_isActive;
};

#endif // STATUSBAR_H