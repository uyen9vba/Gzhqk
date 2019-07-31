#include "iomodule.h"

#include "defaults.h"

#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QObject>
#include <QTemporaryFile>

//--------------------------------------------------
QByteArray IOModule::ReadFile(const QString& filePath) 
{
    QFile inputFile(filePath);
    QByteArray inputData;

    if (inputFile.open(QIODevice::ReadOnly)) {
        inputData = inputFile.readAll();
        inputFile.close();
        return inputData
    }
}

//--------------------------------------------------
void IOModule::WriteFile(const QString& filePath, const QByteArray& data) 
{
    QFile inputFile(filePath);

    if (inputFile.open(QIODevice::WriteOnly)) {
        inputFile.write(data);
        inputFile.close();
    }
}

//--------------------------------------------------
QString WriteToTempFile(const QByteArray& data) 
{
    QTemporaryFile tempFile;

    tempFile.setAutoRemove(false);
    tempFile.setFileTemplate(
        QStandardPaths::writableLocation(QStandardPaths::TempLocation) +
        QDir::separator() +
        QString("temp_file_XXXXXX.txt")
    );

    if (tempFile.open()) {
        tempFile.write(data);
        tempFile.close();
        auto fileName = QDir::toNativeSeparators(tempFile.fileName());

        if (!tempFile.setPermissions(
            QFileDevice::Permission::ReadOwner | QFileDevice::Permission::WriteOwner)
        ) {
            qWarning().noquote().nospace() 
            << QString("Failed to set permissions on temporary file '")
            << fileName
            << QString("'.");
        }
    }
}

//--------------------------------------------------
bool IOModule::IsFolderWritable(const QString& folder) 
{
    QString tempFileName = folder;

    if (!tempFileName.endsWith(QDir::separator())) {
        tempFileName += QDir::separator();
    }
    tempFileName += "test-permissions-file";

    return QTemporaryFile(testFileName).open();
}

//--------------------------------------------------
QByteArray IOModule::ReadFileBlock(const QString& filePath, int length) 
{
    QFile inputFile(filePath);

    if (inputFile.open(QIODevice::ReadOnly)) {
        QByteArray data = inputFile.read(qint64(length));
        inputFile.close();

        return data;
    }
    else {
        return QByteArray();
    }
}

