
#include <chrono>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

bool get_point_safe(std::vector<std::vector<int>>& graph, std::vector<int>& visited, int point)
{
    if (graph[point].empty())
    {
        visited[point] = -1;
        return true;
    }
    if (visited[point] == 2)
    {
        return false;
    }
    visited[point] = 1;
    for (int i = 0; i < graph[point].size(); i++)
    {
        if (visited[graph[point][i]] == 1 || visited[graph[point][i]] == 2)
        {
            visited[point] = 2;
            return false;
        }
        else if (visited[graph[point][i]] == -1) {
            continue;
        }
        if (!get_point_safe(graph, visited, graph[point][i]))
        {
            visited[point] = 2;
            return false;
        }
    }
    visited[point] = -1;
    return true;
}

class Solution {
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {
        std::vector<int> visited(graph.size(), 0);
        std::vector<int> res;
        for (int i = 0; i < graph.size(); i++)
        {
            if (get_point_safe(graph, visited, i))
            {
                res.push_back(i);
            }
        }
        return res;
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
    std::string input{ "[[1,2],[2,3],[5],[0],[5],[],[]]" };
	std::vector<std::vector<int>> grid = process_input(input);
    auto start_time = std::chrono::steady_clock::now();
    std::vector<int> res = sol.eventualSafeNodes(grid);
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    for (auto x: res)
    {
        std::cout << x << " ";
    }
    std::cout << "\n" << elapsed_ns.count() << " ns\n";
}
