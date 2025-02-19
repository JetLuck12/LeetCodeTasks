
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

namespace chars
{
    string ch{ "abc" };
}

int backtrack(std::string& ch, std::string& word, int n, int k, int index)
{
	if (word.size() == n)
	{
        return 1;
	}
    int res = index;
    for (auto& x : ch)
    {
	    if (!word.empty() && word[word.size()-1] == x)
	    {
		    continue;
	    }
        auto new_word = word;
        new_word.insert(new_word.end(), x);
        res += backtrack(ch, new_word, n, k, res);
        if (res >= k)
        {
            word = new_word;
            return res - index;
        }
    }
    return res - index;
}

class Solution {
public:
    string getHappyString(int n, int k) {
        std::string word;
        backtrack(chars::ch, word, n, k, 0);
    	return word;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    int k = 9;
    string res = sol.getHappyString(n, k);
}
