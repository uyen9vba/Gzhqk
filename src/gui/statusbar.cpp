#include "src/gui/statusbar.h"

#include "src/base/texteditor.h"
#include "src/static/defaults.h"

//--------------------------------------------------
StatusBar::StatusBar(QWidget* parent) :
QStatusBar(parent), m_labelInfo(QLabel(this)), m_encodingInfo(QString()), 
m_eolInfo(QString()), m_lexerInfo(QString()), m_isActive(false) 
{
    setSizeGripEnabled(false); 
    m_labelInfo->setStyleSheet(QString("QLabel { margin-right: 16px; }"));
    addPermanentWidget(m_labelInfo);
}

//--------------------------------------------------
void StatusBar::SetEol(int eolMode) 
{
    m_eolInfo = TextEditor::GetEolModeAsString(eolMode);
}

//--------------------------------------------------
void StatusBar::SetEncoding(const QString& encoding) 
{
    m_encodingInfo = encoding;
    UpdateInfo();
}

//--------------------------------------------------
void StatusBar::SetFileType(const QString& fileType) 
{
    m_lexerInfo = fileType;
    UpdateInfo();
}

//--------------------------------------------------
bool StatusBar::IsActive() const 
{
    return m_isActive;
}

//--------------------------------------------------
void StatusBar::SetIsActive(bool isActive) 
{
    m_isActive = isActive; 
    setVisible(m_isActive);
}

//--------------------------------------------------
void StatusBar::ResetActiveState() 
{
    SetIsActive(m_isActive);
}

//--------------------------------------------------
void StatusBar::UpdateInfo() 
{
    QStringList lst;
    lst << m_scopeInfo << m_lineInfo << m_columnInfo 
        << m_indentInfo << m_encodingInfo << m_eolInfo 
        << m_lexerInfo << m_osInfo;
    lst.removeAll(QString());

    m_labelInfo->setText(lst.join(QString("   ")));
}