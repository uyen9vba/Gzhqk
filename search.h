#ifndef SEARCH_H
#define SEARCH_H

namespace cmp {
  class Search;
}

class Search
{
public:
  Search();
  ~Search();

private:
  // Search functions
  void find(const QString& term);
  void find_regex(const QString& term);
  void find_case(const QString& term);
  void find_selection(const QString& term);

  // Data
  QString search_term;
  QStringList term_positions;
};
