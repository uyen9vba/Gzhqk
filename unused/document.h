#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <string_view>
#include <algorithm>

#include <QApplication>
#include <QMainWindow>
#include <QSettings>

namespace src {
  class Document;
}

class Document
{
public:
  explicit Document(QWidget* parent = nullptr);
  virtual ~Document() = default;

private:
  // Operators
  bool operator==(const doc_id& id) const;
  bool operator!=(const doc_id& id) const;

  // Control functions
  bool check() const;
  bool is_empty() const;
  bool is_draft() const;
  bool is_document() const;
  bool is_frozen() const;
  bool clear();
  bool close();
  bool commit();
  bool commit(const QString& label, const QString& desc);
  

  // File control
  void save();
  void open(QString file_name);
  QString get_file_type(QString file_name);
  void set_file_path(const QString& file_path);

  // Document identification and metadata
  void create_new(const QSettings& settings);
  void set_document(const doc_id& id);
  doc_id get_document() const;
  doc_id get_parent() const;
  doc_id get_draft_parent() const;
  doc_id get_draft_parent(int version_id) const;
  bool is_draft_attached() const;
  int get_document_id() const;
  int get_version_id() const;
  int get_version_count() const;
  int get_version_length(const doc_id& id) const;

  // Text processing
  QString get_text() const;
  QString get_text_part(int start_pos, int end_pos);
  unsigned get_line(unsigned start_pos, std::vector<char>& buffer) const;

  // Text control
  unsigned get_length() const;
  unsigned get_char_pos(unsigned offset, int chat_count) const;
  unsigned get_char_pos(const doc_id& version, unsigned offset, int char_count) const;
  unsigned get_char_length(unsigned pos) const;
  unsigned get_next_char_pos(unsigned pos) const;
  unsigned get_prev_char_pos(unsigned pos) const;
  unsigned get_valid_char_pos(unsigned pos) const;
  unsigned get_line_start(unsigned pos) const;
  unsigned get_line_end(unsigned pos) const;

  // Indentation 
  bool is_auto_indentation_enabled() const;
  void set_auto_indentation_enabled(bool auto_indentation_enabled);

  // 
  std::string content;
  QString file_name;
  QString file_type;
  QString current_directory;

};

#endif // DOCUMENT_H
