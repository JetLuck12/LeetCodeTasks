
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0;
        int sum = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            sum += nums[i];
            if (nums[i] >= nums[i+1])
            {
                if (sum > max_sum)
                {
                    max_sum = sum;
                }
                sum = 0;
            }
        }
        sum += nums[nums.size()-1];
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        return max_sum;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[10,20,30,5,10,50]" };
    std::vector<int> grid = Parser::process_vector(input);
    int res = sol.maxAscendingSum(grid);
}
