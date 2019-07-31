#include "search.h"
#include "string.h"

#include <algorithm>


class cmp::Search :
public Search
{
public:

    // --------------------------------------------------
    // Boyer-Moore algorithm
    void find_all(std::string term)
    {

    }

    // --------------------------------------------------
    bool is_ascii_string(std::string s) 
    {
        for (unsigned i = 0; i < s.length; i++) {
            if (s[i] > 256 || s[i] < 0) {
                return false;
            }
        }
        return true;
    }
};