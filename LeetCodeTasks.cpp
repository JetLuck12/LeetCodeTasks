
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
            };

        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) parent[rootX] = rootY;
            };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= limit) {
                    unite(i, j);
                }
            }
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[find(i)].push_back(i);
        }

        vector<int> result = nums;
        for (auto& [_, indices] : groups) {
            vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }
            sort(values.begin(), values.end());
            sort(indices.begin(), indices.end());
            for (int i = 0; i < indices.size(); ++i) {
                result[indices[i]] = values[i];
            }
        }

        return result;
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
        res.push_back(atoi(&input[i+1]));
    }
    return res;
}


int main()
{
    Solution sol;
    std::string input{ "[1,60,34,84,62,56,39,76,49,38]" };
	std::vector<int> grid = process_input(input);
    int limit = 4;
    std::vector<int> res = sol.lexicographicallySmallestArray(grid, limit);
    for (auto x: res)
    {
        std::cout << x << " ";
    }
}
