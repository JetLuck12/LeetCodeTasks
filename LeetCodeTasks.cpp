
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

int get_sum(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, multiset<int>> sums;
        for (auto& x : nums) {
            int y = get_sum(x);
            if (sums.contains(y)) {
                sums[y].insert(x);
            }
            else {
                sums[y] = { x };
            }
        }
        int max = 0;
        for (auto& [first, second] : sums) {
            if (second.size() < 2) {
                continue;
            }
            int pmax = *(second.rbegin()) + *(++second.rbegin());
            if (max < pmax) {
                max = pmax;
            }
        }
        return max;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[18,43,36,13,7]" };
    std::vector<int> grid = Parser::process_vector(input);
    int res = sol.maximumSum(grid);
}
