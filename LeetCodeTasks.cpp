
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

#include "parser.h"

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colors;
        unordered_map<int, int> balls;
        vector<int> res(queries.size(), 0);
        int ind = 0;
        for (auto& query: queries)
        {
	        if (balls.contains(query[0]))
	        {
		        if (colors[balls[query[0]]] > 1)
		        {
                    colors[balls[query[0]]]--;
		        }
                else
                {
                    colors.erase(balls[query[0]]);
                }
	        }
            if (colors.contains(query[1]))
            {
                colors[query[1]]++;
            }
            else
            {
                colors[query[1]] = 1;
            }
            balls[query[0]] = query[1];
            res[ind] = colors.size();
            ind++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[[1,4],[2,5],[1,3],[3,4]]" };
    int limit = 4;
    std::vector<std::vector<int>> grid = Parser::process_vector_vector(input);
    vector<int> res = sol.queryResults(limit, grid);
}
