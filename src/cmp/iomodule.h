#ifndef IOMODULE_H
#define IOMODULE_H

#include "defaults.h"

#include <QCoreApplication>
#include <QStandardPaths>

namespace src {
    class IOModule;
}

class IOModule {
public:
    IOModule() = delete;
    ~IOModule() = delete;
    
    IOModule& operator=(const IOModule&) = delete;

public:
    static QByteArray ReadFile(const QString& filePath);
    static void WriteFile(const QString& filePath, const QByteArray& data);
    static QString WriteToTempFile(const QByteArray& data);

    static bool IsFolderWritable(const QString& folder);
    static QByteArray ReadFileBlock(const QString& filePath, int length);
};

#endif