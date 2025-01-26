
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        vector<int> visited(favorite.size(), 0);
        vector<int> max_vec;
        for (int i = 0; i < favorite.size(); i++)
        {
            if (visited[i] == 2)
            {
	            continue;
            }
            vector<int> new_vec{i};
            visited[i] = 1;
            int new_point = i;
            while(true)
            {
                new_point = favorite[new_point];
	            if (visited[new_point] == 2)
	            {
                    for (int j : new_vec)
                    {
                        visited[j] = 2;
                    }
                    break;
	            }
                if(visited[new_point] == 1)
                {
                    for (int j = 0; j < new_vec.size(); j++)
                    {
                        if (new_vec[j] == new_point)
                        {
                            new_vec.erase(new_vec.begin(), new_vec.begin() + j);
                            break;
                        }
                        visited[j] = 2;
                    }
                    break;
                }
                new_vec.push_back(new_point);
            }
            if (max_vec.size() < new_vec.size())
            {
                max_vec = new_vec;
            }
        }
        return max_vec.size();
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
