
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int, int> subs;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sub = i - nums[i];
	        if (subs.contains(sub))
	        {
                subs[sub]++;
	        }
            else
            {
                subs[sub] = 1;
            }
        }
        int left = nums.size();
        for (auto& [sub, count] : subs)
        {
            left -= count;
            res += count * left;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[4,1,3,3]" };
    std::vector<int> grid = Parser::process_vector(input);
    long long res = sol.countBadPairs(grid);
}
