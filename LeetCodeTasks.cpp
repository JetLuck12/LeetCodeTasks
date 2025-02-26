
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
    int maxAbsoluteSum(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        int res = 0;
        for (auto& x : nums) {
            if (pos < 0) {
                pos = x;
            }
            else {
                pos += x;
            }
            if (neg > 0) {
                neg = x;
            }
            else {
                neg += x;
            }
            if (pos > res) {
                res = pos;
            }
            if (-neg > res) {
                res = -neg;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[1,-3,2,3,-4]" };
    std::vector<int> nums = Parser::process_vector(input);
    int res = sol.maxAbsoluteSum(nums);
}
