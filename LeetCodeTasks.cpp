
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
        int max_seq = 0;
        unordered_map<int, int> index;
        for (int i = 0; i < arr.size(); i++)
        {
            index[arr[i]] = i;
        }
        for (int i = 0; i < arr.size(); i++)
        {
	        for (int j = i+1; j < arr.size(); j++)
	        {
                int temp = 2;
                int prev_prev = arr[i];
                int prev = arr[j];
                while (true)
                {
	                if (index.contains(prev_prev+prev))
	                {
                        temp++;
                        prev += prev_prev;
                        prev_prev = prev - prev_prev;
	                }
                    else
                    {
                        max_seq = max(max_seq, temp);
                        break;
                    }
                }
	        }
        }
        return max_seq >= 3 ? max_seq : 0;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[1,2,3,4,5,6,7,8]" };
    std::vector<int> arr = Parser::process_vector(input);
    int res = sol.lenLongestFibSubseq(arr);
}
