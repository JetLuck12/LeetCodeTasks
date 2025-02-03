
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_size = 1;
        int dec_size = 1;
        int inc_size = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                dec_size++;
                inc_size = 1;
                max_size = max(dec_size, max_size);
            }
            else if (nums[i] > nums[i - 1]) {
                inc_size++;
                dec_size = 1;
                max_size = max(inc_size, max_size);
            }
            else {
                inc_size = 1;
                dec_size = 1;
            }
        }
        return max_size;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[3,3,3,3]" };
    std::vector<int> grid = Parser::process_vector(input);
    int res = sol.longestMonotonicSubarray(grid);
}
