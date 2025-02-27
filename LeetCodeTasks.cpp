
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int max = 0;
        unordered_map<int, unordered_map<int, int>> fib_map;
        fib_map[arr[0] + arr[1]] = { {arr[1], 2} };
        for (int i = 2; i < arr.size()-max; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] + arr[j] > arr.back())
                {
	                continue;
                }
                if (fib_map.contains(arr[i] + arr[j]))
                {
                    fib_map[arr[i] + arr[j]][arr[i]] = 2;
                }
                else
                {
                    fib_map[arr[i] + arr[j]] = { { arr[i],2} };
                }
                
            }
            if (fib_map.contains(arr[i])) {
                auto item_map = fib_map[arr[i]];
                for (auto pair : item_map)
                {
                    if (fib_map.contains(arr[i] + pair.first))
                    {
                        fib_map[arr[i] + pair.first][arr[i]] = pair.second + 1;
                    }
                    else
                    {
                        fib_map[arr[i] + pair.first] = { { arr[i],pair.second + 1 } };
                    }
                    if (max <= pair.second)
                    {
                        max = pair.second + 1;
                    }
				}
                fib_map.erase(arr[i]);
            }
        }
        return max;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[1,2,3,4,5,6,7,8]" };
    std::vector<int> arr = Parser::process_vector(input);
    int res = sol.lenLongestFibSubseq(arr);
}
