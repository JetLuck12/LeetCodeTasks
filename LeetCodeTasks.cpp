
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:

};

int main()
{
    Solution sol;
    std::string input{ "[[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]" };
    std::vector<std::vector<int>> grid = Parser::process_vector_vector(input);
    //long long res = sol.findMaxFish(grid);
}
