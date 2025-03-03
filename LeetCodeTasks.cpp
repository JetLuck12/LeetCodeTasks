
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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> eq;
        vector<int> more;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                less.push_back(nums[i]);
            }
            else if (nums[i] > pivot) {
                more.push_back(nums[i]);
            }
            else {
                eq.push_back(nums[i]);
            }
        }
        less.insert(less.end(), eq.begin(), eq.end());
        less.insert(less.end(), more.begin(), more.end());
        return less;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[-3,4,3,2]" };
    std::vector<int> nums = Parser::process_vector(input);
    int pivot = 2;
    vector<int> res = sol.pivotArray(nums, 2);
}
