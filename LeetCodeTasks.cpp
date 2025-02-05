
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> not_matching;
        for (int i = 0; i < s1.size(); i++)
        {
	        if (s1[i] != s2[i])
	        {
                not_matching.push_back(i);
                if (not_matching.size() > 2)
                {
                    return false;
                }
	        }
        }
        if (not_matching.size() == 1)
        {
            return false;
        }
        if (not_matching.size() == 2)
        {
	        if (s1[not_matching[0]] == s2[not_matching[1]] && s1[not_matching[1]] == s2[not_matching[0]])
	        {
                return true;
	        }
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::string input1{ "bank" };
    std::string input2{ "kanb" };
    bool res = sol.areAlmostEqual(input1, input2);
}
