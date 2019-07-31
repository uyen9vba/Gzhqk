#include "document.h"

#include <algorithm>
#include <bitset>

#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QScrollBar>
#include <QTabWidget>
#include <QDebug>


class src::Document :
public Document 
{
public:
    


private:

    // --------------------------------------------------
    void new_tab() 
    {
        
    }
    // --------------------------------------------------
    void open(QString file) 
    {
        if (file != "") {
            if (file_name != "" || currentEditorWidget->toPlainText() != "") {
                newTab();
            }
            
            file_name = file;
            QString filetype = get_file_type(file);
           
        }
    }

    // --------------------------------------------------
    QString get_file_type(QString file) 
    {
        QStringList period_split = file.split(".");
        
        if (period_split.length() > 1) {
            return period_split.last();
        }
        else {
            return "";
        }
    }



};
