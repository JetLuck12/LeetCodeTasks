
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int non_zero_ind = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                continue;
            }
            if (nums[i] == nums[i + 1])
            {
                res[non_zero_ind] = nums[i] * 2;
                nums[i + 1] = 0;
                i++;
            }
            else
            {
                res[non_zero_ind] = nums[i];
            }
            non_zero_ind++;
        }
        if (nums.back() != 0) {
            res[non_zero_ind] = nums.back();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[1,2,2,1,1,0]" };
    vector<int> nums = Parser::process_vector(input);
    vector<int> res = sol.applyOperations(nums);
}
