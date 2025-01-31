
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

int get_land_size(vector<vector<int>>& grid, vector<vector<int>>& visited, vector <vector<int>>& point_land, std::pair<int,int> point, int land_ind)
{
    if (point.first < 0 || point.first > grid.size()-1 || point.second < 0 || point.second > grid[0].size()-1)
    {
        return 0;
    }
	if (visited[point.first][point.second])
	{
        return 0;
	}
    if (grid[point.first][point.second] == 0)
    {
        return 0;
    }
    visited[point.first][point.second] = 1;
    point_land[point.first][point.second] = land_ind;
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    int size = 1;
    for (int i = 0; i < 4; i++)
    {
        size += get_land_size(grid, visited, point_land, {point.first+dy[i], point.second+dx[i]}, land_ind);
    }
    return size;
}

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<int> sizes;
        vector<vector<int>> point_land(grid.size(), vector<int>(grid[0].size(), -1));
        vector<std::pair<int, int>> waters;
        int max_size = 0;
        for (int i = 0; i < grid.size(); i++)
        {
	        for (int j = 0; j < grid[0].size(); j++)
	        {
		        if (visited[i][j])
		        {
                    continue;
		        }
                if (grid[i][j] == 0)
                {
                    waters.emplace_back(i, j);
                    continue;
                }
                sizes.push_back(0);
                int size = get_land_size(grid, visited, point_land, { i,j }, sizes.size() - 1);
                sizes[sizes.size() - 1] = size;
                if (max_size < size)
                {
                    max_size = size;
                }

	        }
        }
        int dx[4] = { 1,-1,0,0 };
        int dy[4] = { 0,0,1,-1 };
        for (auto& [y,x]: waters)
        {
            set<int> visited_sets;
            int size = 1;
	        for (int i = 0; i < 4; i++)
	        {
                if (y + dy[i] < 0 || y + dy[i] > grid.size()-1 || x + dx[i] < 0 || x + dx[i] > grid[0].size()-1 || point_land[y + dy[i]][x + dx[i]] == -1)
                {
                    continue;
                }
		        if(!visited_sets.contains(point_land[y+dy[i]][x+dx[i]]))
		        {
                    visited_sets.insert(point_land[y + dy[i]][x + dx[i]]);
                    size += sizes[point_land[y + dy[i]][x + dx[i]]];
		        }
	        }
            if (max_size < size)
            {
                max_size = size;
            }
        }
        return max_size;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[[0,0],[0,0]]" };
    std::vector<std::vector<int>> grid = Parser::process_vector_vector(input);
    int res = sol.largestIsland(grid);
}
