
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

bool backtrack(string& pattern, string& nums, set<char>& lefts, int ind)
{
    if (ind == pattern.size()+1)
    {
        return true;
    }
    for (auto& num : lefts)
    {
        if (!(ind == 0 || (pattern[ind-1] == 'I' && nums[ind - 1] < num) || (pattern[ind-1] == 'D' && nums[ind - 1] > num)))
        {
            continue;
        }
        auto new_lefts = lefts;
        auto new_nums = nums;
        new_lefts.erase(num);
        new_nums[ind] = num;
        if (backtrack(pattern, new_nums, new_lefts, ind + 1))
        {
            nums = new_nums;
            return true;
        }
	}
    return false;
}

class Solution {
public:
    string smallestNumber(string pattern) {
        string nums(pattern.size() + 1, 0);
        set<char> lefts;
        for (int i = 1; i <= pattern.size()+1; i++)
        {
            lefts.insert(static_cast<char>(i)+'0');
        }
        backtrack(pattern, nums, lefts, 0);
        return nums;
    }
};

int main()
{
    Solution sol;
    std::string input{ "IIIDIDDD" };
    string res = sol.smallestNumber(input);
}
