
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

bool colorize(vector<set<int>>& conn, vector<int>& colors, vector<vector<int>>& sets, int prepoint, int point, int set_ind)
{
	if (prepoint != -1 && colors[point] == colors[prepoint])
	{
        return false;
	}
    if (colors[point] == 0)
    {
        colors[point] = prepoint == -1 ? 1 : -colors[prepoint];
        sets[set_ind].push_back(point);
	    for (auto& x: conn[point])
	    {
		    if (!colorize(conn, colors, sets, point, x, set_ind))
		    {
                return false;
		    }
	    }
    }
    return true;
}

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<set<int>> connections(n ,{});
        for (int i = 0; i < edges.size(); i++)
        {
            connections[edges[i][0]-1].insert(edges[i][1]-1);
            connections[edges[i][1]-1].insert(edges[i][0]-1);
        }
        vector<int> colors(n, 0);
        vector<vector<int>> sets;
        int set_ind = -1;
        for (int i = 0; i < connections.size(); i++)
        {
	        if (colors[i] != 0)
	        {
		        continue;
	        }
            sets.emplace_back();
            set_ind++;
            if (!colorize(connections, colors,sets, -1, i, set_ind))
            {
                return -1;
            }
        }
        int res = 0;
        for (int i = 0; i < sets.size(); i++)
        {
            int max_depth = 0;
            for (int j = 0; j < sets[i].size(); j++)
            {
                vector<int> visited(n, 0);
                int depth = 0;
                queue<pair<int, int>> queue;
                queue.emplace(sets[i][j], 1);
                while (!queue.empty())
                {
                    auto point = queue.front();
                    queue.pop();
                    if (visited[point.first])
                    {
	                    continue;
                    }
                	if (depth < point.second)
                    {
                        depth = point.second;
                    }
                    visited[point.first] = 1;
                    for (auto& x: connections[point.first])
                    {
                        queue.emplace(x, point.second+1);
                    }
                }
                if (depth > max_depth)
                {
                    max_depth = depth;
                }
            }
            res += max_depth;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]" };
    int n = 6;
    std::vector<std::vector<int>> grid = Parser::process_vector_vector(input);
    int res = sol.magnificentSets(n, grid);
}
