
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos = s.find(part);
        while (pos != s.npos)
        {
            s.erase(pos, part.size());
            pos = s.find(part);
        }
        return s;
    }
};

int main()
{
    Solution sol;
    std::string input1{ "daabcbaabcbc" };
    std::string input2{ "abc" };
    std::string res = sol.removeOccurrences(input1, input2);
}
