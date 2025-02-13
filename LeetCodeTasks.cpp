
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> set_nums(nums.begin(), nums.end());
        int i = 0;
        while (set_nums.size() > 1)
        {
            long long a = *set_nums.begin();
            set_nums.erase(set_nums.begin());
            if (a >= k)
            {
                return i;
            }
            long long b = *set_nums.begin();
            set_nums.erase(set_nums.begin());
            set_nums.insert(a * 2 + b);
            i++;
        }
        return i;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[1,1,2,4,9]" };
    int k = 20;
    std::vector<int> grid = Parser::process_vector(input);
    int res = sol.minOperations(grid, k);
	}
