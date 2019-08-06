#ifndef SYNTAXTHEME_H 
#define SYNTAXTHEME_H

#include "src/static/enums.h"
#include "src/gui/syntaxstyles.h"

#include <QObject>
#include <QColor>
#include <QMap>

class SyntaxTheme :
public QObject {
public:
    explicit SyntaxTheme(
        QString name,
        QMap<SyntaxComponents, SyntaxStyles> styles = QMap<SyntaxComponents, SyntaxStyles>()
    );
    virtual ~SyntaxTheme() = default;

public:
    QString GetName() const;
    SyntaxStyles GetComponent(SyntaxComponents key);
    QMap<SyntaxComponents, SyntaxStyles> GetStyles() const;
    bool HasComponent(SyntaxComponents key) const;

    void SetName(const QString& name);
    void SetComponent(SyntaxComponents key, const SyntaxStyles& value);


    void ClearStyles();
    void RemoveComponent(SyntaxComponents key);

private:
    QMap<SyntaxComponents, SyntaxStyles> m_styles;
    QString m_name;
};

#endif // SYNTAXTHEME_H