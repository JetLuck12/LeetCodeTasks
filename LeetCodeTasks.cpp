
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

void reachebles(vector<vector<bool>>& isReacheble, queue<int>& queue, vector<int>& visited)
{
    int point = queue.front();
    queue.pop();
    if (visited[point])
    {
	    return;
    }
	for (int i = 0; i < isReacheble.size(); i++)
	{
		if (isReacheble[i][point])
		{
            queue.push(i);
            for (int j = 0; j < isReacheble.size(); j++)
            {
                isReacheble[i][j] = isReacheble[point][j] || isReacheble[i][j];
            }
		}
	}
    visited[point] = true;
}

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isReacheble(numCourses, vector<bool>(numCourses, false));
        vector<int> visited(numCourses, false);
        set<int> leafs;
        for (int i = 0; i < numCourses; i++)
        {
            leafs.insert(i);
        }
        for (auto& x: prerequisites)
        {
            isReacheble[x[0]][x[1]] = true;
            if (leafs.contains(x[0]))
            {
                leafs.erase(x[0]);
            }
        }
        queue<int> queue;
        for (auto& x: leafs)
        {
            queue.push(x);
        }
        while (!queue.empty())
        {
            reachebles(isReacheble, queue, visited);
        }
        vector<bool> res(queries.size(), false);
        for (int x = 0; x < queries.size(); x++)
        {
	        if (isReacheble[queries[x][0]][queries[x][1]])
	        {
                res[x] = true;
	        }
        }
        return res;
    }
};

std::vector<std::vector<int>> process_input(std::string& input)
{
    std::vector<std::vector<int>> res;
    std::vector<int> line;
    int i = 2;
    line.push_back(atoi(&input[2]));
    while (i < input.size()-1)
    {
	    while (input[i] != ',' && input[i] != ']' && input[i] != '[')
	    {
            i++;
	    }
        if (input[i] == '[')
        {
            line.push_back(atoi(&input[i + 1]));
        }
        else if (input[i] == ',')
        {
            if (input[i + 1] == '[')
            {
                i++;
                continue;
            }
            line.push_back(atoi(&input[i+1]));
        }
        else
        {
            res.push_back(line);
            line.clear();
            
        }
        i++;
    }
    return res;
}


int main()
{
    Solution sol;
    std::string input1{ "[[0,1],[1,2],[2,3],[3,4]]" };
    std::string input2{ "[[0,4],[4,0],[1,3],[3,0]]" };
	int num = 5;
    vector<vector<int>> prereq = process_input(input1);
    vector<vector<int>> queries = process_input(input2);
    //std::vector<std::vector<int>> grid = process_input(input);
    auto res = sol.checkIfPrerequisite(num, prereq,queries);
    //std::cout << res;
}
