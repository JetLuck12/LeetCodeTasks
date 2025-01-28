
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector <vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int max_fishes = 0;
        int dx[4] = { 1,-1,0,0 };
        int dy[4] = { 0,0,1,-1 };
        for (int i = 0; i < grid.size(); i++)
        {
	        for (int j = 0; j < grid[0].size(); j++)
	        {
		        if (grid[i][j] == 0 || visited[i][j] == 1)
		        {
			        continue;
		        }
                queue<pair<int,int>> queue;
                queue.emplace(i, j);
                int fishes = 0;
                while (!queue.empty())
                {
                    auto point = queue.front();
                    queue.pop();
                    if (visited[point.first][point.second])
                    {
	                    continue;
                    }
                    fishes += grid[point.first][point.second];
                    for (int k = 0; k < 4; k++)
                    {
	                    if (point.first + dy[i] > grid.size()-1 || point.first + dy[i] < 0 || point.second + dx[i] > grid[0].size() - 1 || point.second + dx[i] < 0)
	                    {
		                    continue;
	                    }
                        if (visited[point.first+dy[i]][point.second+dx[i]])
                        {
	                        continue;
                        }
                        queue.emplace(point.first + dy[i], point.second + dx[i]);
                    }
                }
                if (fishes > max_fishes)
                {
                    max_fishes = fishes;
                }
	        }
        }
        return max_fishes;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]" };
    std::vector<int> grid = Parser::process_vector(input);
    long long res = sol.countServers(grid);
    std::cout << res;
}
