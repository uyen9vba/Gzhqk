#include "src/cmp/filemetadata.h"

#include <QDir>
#include <QFile>
#include <QInputDialog>
#include <QTextCodec>

//--------------------------------------------------
FileMetadata FileMetadata::GetMetadata(
    const QByteArray& data,
    const QString& filePath,
    const QString& encoding, 
    const QString& filter 
)
{
    if (data.size() >= k_maxTextFile) {
        QMessageBox::critical
    }
}
