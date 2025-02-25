
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int last_odd_sums = 0;
        int last_even_sums = 0;
        int res = 0;
        for (auto& x : arr) {
            if (x % 2 == 0) {
                last_even_sums++;
            }
            else {
                int temp_even = last_even_sums;
                last_even_sums = last_odd_sums;
                last_odd_sums = temp_even + 1;
            }
            if (1000000007 - last_odd_sums < res) {
                res -= 1000000007;
            }
            res += last_odd_sums;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[1,3,5]" };
    std::vector<int> arr = Parser::process_vector(input);
    int res = sol.numOfSubarrays(arr);
}
