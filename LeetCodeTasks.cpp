
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

bool recursive(vector<int>& vec, set<int> nums, int ind)
{
    if (ind == vec.size())
    {
        return true;
    }
    if (vec[ind] != 0)
    {
        if (recursive(vec, nums, ind + 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    for (auto x = nums.rbegin();x != nums.rend(); ++x)
    {
        if (*x == 1)
        {
            auto new_vec = vec;
            auto new_nums = nums;
            new_vec[ind] = *x;
            new_nums.erase(*x);
            if (recursive(new_vec, new_nums, ind + 1))
            {
                vec = new_vec;
                return true;
            }
	        continue;
        }
        if (*x+ind >= vec.size())
        {
            return false;
        }
	    if (vec[*x+ind] == 0)
	    {
            auto new_vec = vec;
            auto new_nums = nums;
            new_vec[ind] = *x;
            new_vec[*x + ind] = *x;
            new_nums.erase(*x);
            if (recursive(new_vec,new_nums,ind+1))
            {
                vec = new_vec;
                return true;
            }
	    }
    }
    return false;
}

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
		vector<int> res(n * 2 - 1, 0);
        set<int> nums;
        for (int i = 1; i  <= n; i++)
        {
            nums.insert(i);
        }
		recursive(res, nums, 0);
		return res;
    }
};

int main()
{
    Solution sol;
    int input = 5;
    vector<int> res = sol.constructDistancedSequence(input);
}
