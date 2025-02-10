
#include <iostream>
#include <locale>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string res = s;
        for (int i = 0; i < res.size(); i++) {
            if (std::isdigit(res[i]))
            {
	            for (int j = i; j >= 0; j--)
	            {
		            if (!isdigit(res[j]))
		            {
                        res.erase(i,1);
                        res.erase(j,1);
                        i -= 2;
                        break;
		            }
	            }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::string input{ "cb34" };
    string res = sol.clearDigits(input);
}
