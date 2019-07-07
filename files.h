#ifndef FILES_H
#define FILES_H

#include "QString.h"

namespace cmp {
  class Files;
}

class Files {
public:
  Files();
  QString read(QString filename);
  void write(QString filename, QString content);
  QString get_home_directory();
  void open_file_manager(QString dir);
  QString get_directory(QString filepath);

};

#endif
