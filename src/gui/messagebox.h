#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H 

#include <QDialogButtonBox>
#include <QMessageBox>

class MessageBox :
public QMessageBox {
public:
    explicit MessageBox(QWidget* parent = nullptr);
    virtual ~MessageBox() = default;

public:
    void SetIcon(QMessageBox::Icon icon);
    static void SetCheckBox(QMessageBox* messageBox, const QString& text, bool* data);
    
};