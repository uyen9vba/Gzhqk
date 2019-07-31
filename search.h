#ifndef SEARCH_H
#define SEARCH_H

#include <algorithm>
#include <string>
#include <string_view>


namespace cmp {
  class Search;
}

class Search
{
public:
  Search();
  ~Search();

private:
  void find_all(std::string term);
  void find_regex(const QString& term);
  void find_case(const QString& term);
  void find_selection(const QString& term);
  void replace(const QString& term);
  void replace_all(const QString& term);

  bool is_ascii_string(std::string s);
  

  // Data
  std::string search_term;
  QVector<int> seacrh_term_pos;
};
