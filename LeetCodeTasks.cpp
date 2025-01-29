
#include <iostream>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "parser.h"

using namespace std;

std::pair<int, std::vector<int>> get_cycle(map<int, vector<int>>& conn, set<int>& visited, int prepoint, int point)
{
    if (visited.contains(point))
    {
        return { 1,vector<int>{point} };
    }
    visited.insert(point);
    for (int i = 0; i < conn[point].size(); i++)
    {
	    if (conn[point][i] == prepoint)
	    {
		    continue;
	    }
        auto vec = get_cycle(conn, visited, point, conn[point][i]);
        if (vec.first == 0)
        {
	        continue;
        }
        if (vec.first == 1)
        {
            if (point == vec.second[0])
            {
                vec.second.push_back(point);
                return { 2, vec.second };
            }
            vec.second.push_back(point);
            return vec;
        }
        if (vec.first == 2)
        {
            return { 2, vec.second };
        }
    }
    return {0, {}};
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> connections;
        map<pair<int, int>, int> sorted;
        for (int i = 0; i < edges.size(); i++)
        {
            sorted[{edges[i][0], edges[i][1]}] = i;
	        if (connections.contains(edges[i][0]))
	        {
                connections[edges[i][0]].push_back(edges[i][1]);
	        }
            else
            {
                connections[edges[i][0]] = { edges[i][1] };
            }
            if (connections.contains(edges[i][1]))
            {
                connections[edges[i][1]].push_back(edges[i][0]);
            }
            else
            {
                connections[edges[i][1]] = { edges[i][0] };
            }
        }
        set<int> visited;
        int point = connections.begin()->first;
        auto vec = get_cycle(connections, visited, -1, point);
        int max_ind = 0;
        for (int i = vec.second.size()-1; i > 0; i--)
        {
            if (sorted.contains({ vec.second[i], vec.second[i - 1] }))
            {
	            if (max_ind < sorted[{ vec.second[i], vec.second[i - 1] }])
	            {
                    max_ind = sorted[{ vec.second[i], vec.second[i - 1] }];
	            }
            }
            else if (sorted.contains({ vec.second[i-1], vec.second[i] }))
            {
                if (max_ind < sorted[{ vec.second[i-1], vec.second[i] }])
                {
                    max_ind = sorted[{ vec.second[i-1], vec.second[i] }];
                }
            }
        }
        return edges[max_ind];
    }
};

int main()
{
    Solution sol;
    std::string input{ "[[1,2],[1,3],[2,3]]" };
    std::vector<std::vector<int>> grid = Parser::process_vector_vector(input);
    vector<int> res = sol.findRedundantConnection(grid);
}
