
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 0)
                {
                    continue;
                }
                grid[y][x] = 0;
                vector<pair<int, int>> connection{ {y,x} };
                for (auto index = 0; index < connection.size(); index++) {
                    std::pair<int, int> point{ connection[index] };
                    for (int i = 0; i < grid.size(); i++)
                    {
                        if (grid[i][point.second] == 1)
                        {
                            grid[i][point.second] = 0;
                            connection.emplace_back(i, point.second);
                        }
                    }

                    for (int j = 0; j < grid[0].size(); j++)
                    {
                        if (grid[point.first][j] == 1)
                        {
                            grid[point.first][j] = 0;
                            connection.emplace_back(point.first, j);
                        }
                    }
                }
                if (connection.size() > 1)
                {
                    count += connection.size();
                }
            }

        }
        return count;
    }
};

std::vector<std::vector<int>> process_input(std::string& input)
{
    std::vector<std::vector<int>> res;
    std::vector<int> line;
    for (int i = 1; i < input.size() - 1; i++)
    {
        if (input[i] == '[' || input[i] == ',')
        {
            continue;
        }
        if (input[i] == ']')
        {
            res.push_back(line);
            line.clear();
        }
        else
        {
            line.push_back(atoi(&input[i]));
        }
    }
    return res;
}


int main()
{
    Solution sol;
    std::string input{ "[[1,0],[1,1]]" };
    std::vector<std::vector<int>> grid = process_input(input);
    long long res = sol.countServers(grid);
    std::cout << res;
}
