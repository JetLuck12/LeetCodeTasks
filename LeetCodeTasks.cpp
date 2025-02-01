
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++)
        {
	        if (((nums[i]+nums[i+1])&1) == 0)
	        {
                return false;
	        }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[2,1,4]" };
    std::vector<int> grid = Parser::process_vector(input);
    bool res = sol.isArraySpecial(grid);
}
