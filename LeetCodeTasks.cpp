
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
		        if (grid[i][j] == 0)
		        {
                    visited[i][j] = 1;
			        continue;
		        }
                if (visited[i][j] == 1)
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
                    visited[point.first][point.second] = 1;
                    for (int k = 0; k < 4; k++)
                    {
	                    if (point.first + dy[k] > grid.size()-1 || point.first + dy[k] < 0 || point.second + dx[k] > grid[0].size() - 1 || point.second + dx[k] < 0)
	                    {
		                    continue;
	                    }
                        if (grid[point.first + dy[k]][point.second + dx[k]] == 0)
                        {
                            visited[point.first + dy[k]][point.second + dx[k]] = 1;
                            continue;
                        }
                        if (visited[point.first+dy[k]][point.second+dx[k]])
                        {
	                        continue;
                        }
                        queue.emplace(point.first + dy[k], point.second + dx[k]);
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
    std::vector<std::vector<int>> grid = Parser::process_vector_vector(input);
    long long res = sol.findMaxFish(grid);
}
