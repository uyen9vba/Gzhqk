#include "highlighter.h"

class cmp::Highlighter :
public Highlighter
{
public:
  Highlighter()
  {
    exp_start = QRegExp("");
    exp_end = QRegExp("");
  }

  // --------------------------------------------------
  void derive_language(QString file_type)
  {
    compiled_languages = QString(c cpp cs dart go java rs).split(" ");
    scripting_languages = QString(coffee js lua php py rb).split(" ");
    markup_languages = QString(htm html json xml).split(" ");

    if (compiled_languages.contains(file_type)) {
      set_compiled_language_rules();
    }
    else if (scripting_languages.contains(file_type)) {
      set_scripting_language_rules();
    }
    else if (markup_languages.contains(file_type)) {
      set_markup_language_rules();
    }
    else if (file_type == "asm") {
      set_asm_rules();
    }
    else if (file_type == "css") {
      set_css_rules();
    }
    else if (file_type == "sql") {
      set_sql_rules();
    }
  }

  // --------------------------------------------------
  void set_compiled_language_rules()
  {


  }

  // --------------------------------------------------
  void set_asm_rules()
  {
    // Functions
    function.setForeground(functions_color);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_<>-@]+:");
    rule.format = function;
    highlighting_rules.append(rule);

    // Numbers
    number.setForeground(number_color);
    rule.pattern = QRegExp("\\b[0-9a-fx\\.]+\\b");
    rule.format = number;
    highlighting_rules.append(rule);

    // Keywords
    keyword.setForeground(keyword_color2);
    keyword.setFontWeight(QFont::Bold);
    QStringList keyword_patterns;
    keyword_patterns << "\\bcall\\b"

  }

  // --------------------------------------------------
  void set_theme(Theme import)
  {
    theme.line_color = import.line_color;
    theme.keyword_color = import.keyword_color;
    theme.keyword_color2 = import.keyword_color2;
    theme.functions_color = import.functions.color;
    theme.value_color = import.value_color;
    theme.number_color = import.number_color;
    theme.operator_color = import.operator_color;
    theme.string_color = import.string_color;
    theme.comment_color = import.comment_color;
    theme.variable_color = import.variable_color;
    theme.tab_color = import.tab_color;
    theme.html_attribute_color = import.html_attribute_color;
    theme.css_classes_ids_color = import.css_classes_ids_color;
    theme.css_attribute_color = import.css_attribute_color;
  }

  // --------------------------------------------------
  void highlight_block(const QString& text)
  {
    for (const Highlighting_rule& rule : highlighting_rules) {
      QRegExp expression(rule.pattern);
      int index = expression.indexIn(text);

      while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, rule.format);
        index = expression.indexIn(text, index + length);
      }
    }
    setCurrentBlockState(0);

    if (exp_start != QRegExp("") && exp_end != QRegExp("")) {
      int start_index = 0;
      if (previousBlockState() != 1) {
        start_index = exp_start.indexIn(text);
      }
      while (start_index >= 0) {
        int end_index = exp_end.indexIn()
      }
    }
  }


};
