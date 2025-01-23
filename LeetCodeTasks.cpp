
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
                vector<pair<int, int>> connection{ {y,x} };
                for (auto point : connection) {
                    for (int i = point.first + 1; i < grid.size(); i++)
                    {

                        if (grid[i][point.second] == 1)
                        {
                            grid[i][point.second] = 0;
                            connection.emplace_back(i, point.second);
                        }
                    }

                    for (int j = point.second + 1; j < grid[0].size(); j++)
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
int main()
{
    Solution sol;
    std::vector<std::vector<int>> grid{ {1, 0},{0, 1} };
    long long res = sol.countServers(grid);
    std::cout << res;
}
