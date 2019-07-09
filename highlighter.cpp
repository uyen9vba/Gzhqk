#include "highlighter.h"

class cmp::Highlighter :
public Highlighter
{
public:
  Highlighter(QString file_type, QString theme)
  {
    exp_start = QRegExp("");
    exp_end = QRegExp("");
    setup_highlighter(file_type, theme);
  }

  // --------------------------------------------------
  void setup_highlighter(QString file_type, QString theme)
  {
    compiled_languages = QString(c cpp cs dart go java rs).split(" ");
    scripting_languages = QString(coffee js lua php py rb).split(" ");
    markup_languages = QString(htm html json xml).split(" ");

    set_color_values(theme);

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
  void set_theme(QString file_type, QString theme)
  {
    setup_highlighter(file_type, theme);
    rehighlight();
  }

  // --------------------------------------------------
  void set_compiled_language_rules()
  {
    Highlighter_rule rule;


  }

  // --------------------------------------------------
  void set_asm_rules()
  {
    // Instance the rule struct
    Highlighter_rule rule;

    // Function formatting
    function.setForeground(functions_color);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_<>-@]+:");
    rule.format = function;
    
  }

};
