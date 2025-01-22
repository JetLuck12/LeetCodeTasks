
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long up_sum = 0;
        for (int i = 1; i < grid[0].size(); i++)
        {
            up_sum += grid[0][i];
        }
        long long bot_sum = 0;
        long long last_up_sum = up_sum;
        for (int i = 1; i < grid[0].size()-1;i++)
        {
            last_up_sum = up_sum;
            bot_sum += grid[1][i - 1];
            up_sum -= grid[0][i];
	        if (bot_sum > up_sum)
	        {
                return min(last_up_sum, bot_sum);
	        }
            
        }
        bot_sum += grid[1][grid[0].size() - 2];
        return min(up_sum, bot_sum);
    }
};
int main()
{
    Solution sol;
    std::vector<std::vector<int>> grid{ {2, 5, 4},{1, 5, 1} };
    long long res = sol.gridGame(grid);
    std::cout << res;
}
