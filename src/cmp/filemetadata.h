#ifndef FILEMETADATA_H
#define FILEMETADATA_H

#include <QString>

struct FileMetadata {
public:
    static FileMetadata GetMetadata(
        const QByteArray& data,
        const QString& filePath,
        const QString& encoding = QString(),
        const QString& filter = QString()
    );
    
public:
    QString m_filePath; 
    QString m_encoding; 
    Lexer m_lexer; // pending
    int m_eolMode; 
};

#endif 