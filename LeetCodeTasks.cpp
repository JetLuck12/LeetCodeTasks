
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int max_ind = 0;
        for (max_ind = 0; max_ind < nums.size() - 1; max_ind++)
        {
            if (nums[max_ind] > nums[max_ind + 1])
            {
                break;
            }
        }
        if (max_ind == nums.size() - 1)
        {
            return true;
        }
        if (nums.front() < nums.back())
        {
            return false;
        }
        int min_ind;
        for (min_ind = nums.size() - 1; min_ind >= max_ind; min_ind--)
        {
            if (nums[min_ind] < nums[min_ind - 1])
            {
                break;
            }
        }
        if (min_ind - max_ind == 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[1,2,3]" };
    std::vector<int> grid = Parser::process_vector(input);
    bool res = sol.check(grid);
}
