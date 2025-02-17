
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

int backtrack(map<char, int>& repeats)
{
    int res = repeats.size();
	for (auto& [ch, rep] : repeats)
	{
		if (rep == 0)
		{
			continue;
		}
        auto new_reps = repeats;
        new_reps[ch]--;
        if (new_reps[ch] == 0)
        {
            new_reps.erase(ch);
        }
        res += backtrack(new_reps);
	}
    return res;
}

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int size = tiles.size();
        map<char, int> repeats;
        for (auto& x : tiles)
        {
	        if (repeats.contains(x))
	        {
                repeats[x]++;
	        }
            else
            {
                repeats[x] = 1;
            }
        }
        int res = backtrack(repeats);
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "AAABBC" };
    int res = sol.numTilePossibilities(input);
}
