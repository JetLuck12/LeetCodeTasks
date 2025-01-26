
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int in_depth_search(vector<vector<int>>& antifavorite, int point)
{
    if (antifavorite[point].empty())
    {
        return 1;
    }
    int max = 0;
	for (int i = 0; i < antifavorite[point].size(); i++)
	{
        int res = in_depth_search(antifavorite, antifavorite[point][i]);
		if (res > max)
		{
            max = res;
		}
	}
    return max+1;
}

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        vector<vector<int>> antifavorite(favorite.size(), vector<int>{});
        int max_bad = 0;
        vector<vector<int>> good_cycles;
        vector<int> visited(favorite.size(), 0);
        for (int i = 0; i < favorite.size(); i++)
        {
	        if (visited[i])
	        {
		        continue;
	        }
            vector<int> path;
            int new_point = i;
            while(visited[new_point] == 0)
            {
                antifavorite[favorite[new_point]].push_back(new_point);
                visited[new_point] = 1;
                path.push_back(new_point);
                new_point = favorite[new_point];
            }
            if (visited[new_point] == 1)
            {
	            if (new_point == favorite[favorite[new_point]])
	            {
                    good_cycles.push_back(vector<int>{new_point, favorite[new_point]});
                    for (int j = 0; j < path.size(); j++)
                    {
                        visited[path[j]] = 2;
                    }
                    antifavorite[new_point].erase(std::remove(antifavorite[new_point].begin(), antifavorite[new_point].end(), favorite[new_point]), antifavorite[new_point].end());
                    antifavorite[favorite[new_point]].erase(std::remove(antifavorite[favorite[new_point]].begin(), antifavorite[favorite[new_point]].end(), new_point), antifavorite[favorite[new_point]].end());
	            }
                else
                {
                    int cycle = 0;
	                for (int j = 0; j < path.size(); j++)
	                {
		                if (path[j] == new_point)
		                {
                            cycle = j;
		                }
                        visited[path[j]] = 3;
	                }
                    path.erase(path.begin(), path.begin() + cycle);
                    if (max_bad < path.size())
                    {
                        max_bad = path.size();
                    }
                }
            }
            else if (visited[new_point] == 2)
            {
	            for (int j = 0; j < path.size(); j++)
	            {
                    visited[path[j]] = 2;
	            }
            }
            else if (visited[new_point] == 3)
            {
                for (int j = 0; j < path.size(); j++)
                {
                    visited[path[j]] = 3;
                }
            }
        }
        if (good_cycles.empty())
        {
            return max_bad;
        }
        int res = 0;
        for (const auto& i : good_cycles)
        {
            for (auto point: i)
            {
                res += in_depth_search(antifavorite, point);
            }
        }
        return res > max_bad ? res : max_bad;
    }
};

std::vector<int> process_input(std::string& input)
{
    std::vector<int> res;
    res.push_back(atoi(&input[1]));
    for (int i = 1; i < input.size() - 1; i++)
    {
        while (i < input.size() - 1 && input[i] != ',')
        {
            i++;
        }
        if (i >= input.size() - 1)
        {
            break;
        }
        res.push_back(atoi(&input[i + 1]));
    }
    return res;
}


int main()
{
    Solution sol;
    std::string input{ "[1,0,0,2,1,4,7,8,9,6,7,10,8]" };
    std::vector<int> grid = process_input(input);
    long long res = sol.maximumInvitations(grid);
    std::cout << res;
}
