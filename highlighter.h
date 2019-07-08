#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

namespace cmp {
  class Highlighter;
}

class Highlighter
{
public:
  Highlighter(QString filetype, QString theme);
  ~Highlighter();

private:
  // Syntax loading
  void setup_highlighter(QString file_type, QString theme);
  void set_color_values(QString theme);
  void set_compiled_language_rules();
  void set_scripting_language_rules();
  void set_markup_language_rules();
  void set_asm_rules();
  void set_css_rules();
  void set_sql_rules();
  void highlight_block(const QString& text);


  // Data
  struct Highlighter_rule
  {
    QRegExp pattern;
    QTextCharFormat format;
  };

  QVector<Highlighter_rule> highlighting_rules

  // Expression
  QRegExp exp_start;
  QRegExp exp_end;

  // Uniform rules
  QTextCharFormat keyword;
  QTextCharFormat number;
  QTextCharFormat single_line_comment;
  QTextCharFormat multi_line_comment;
  QTextCharFormat quotation;
  QTextCharFormat function;
  QTextCharFormat string;
  QTextCharFormat operator;

  // HTML rules
  QTextCharFormat tag;
  QTextCharFormat value;
  QTextCharFormat attribute;
  QTextCharFormat id;
  QTextCharFormat class;

  // Special rules
  QTextCharFormat php_variable;
  QTextCharFormat ruby_variable;

  // Language support
  QStringList compiled_languages;
  QStringList scripting_languages;
  QStringList markup_languages;

  // Highlighter
  QColor keyword_color;
  QColor keyword_color2;
  QColor functions_color;
  QColor value_color;
  QColor number_color;
  QColor operator_color;
  QColor string_color;
  QColor comment_color;
  QColor variable_color;
  QColor tab_color;
  QColor html_attribute_color;
  QColor css_classes_ids_color;
  QColor css_attribute_color;
};
