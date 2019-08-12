#include "src/gui/messagebox.h"

#include "src/base/application.h"
#include "src/static/global.h"
#include "src/gui/theme.h"

#include <QCheckbox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QFileDialog>
#include <QStyle>
#include <QtGlobal>

//--------------------------------------------------
void MessageBox::SetIcon(QMessageBox::Icon icon) 
{
    const int iconSize = s_app->style()->pixelMetric(QStyle::PM_MessageBoxIconSize, nullptr, this);

    setIconPixmap(iconForStatus(icon).pixmap(iconSize, iconSize));
}