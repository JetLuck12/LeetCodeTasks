
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

int recursive(int num, int pred = 0, int next = 0) {
    int temp = next;
    int diver = 10;
    while (temp/diver != 0)
    {
        int rem = temp % diver;
        int div_res = temp / diver;
        if (rem + div_res == num - pred)
        {
            return num * num;
        }
        if (rem+pred > num)
        {
            return 0;
        }
        int res = recursive(num, rem + pred, div_res);
        if (res > 0)
        {
            return res;
        }
        diver *= 10;
    }
    return 0;
}

class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 1;
        for (int i = 2; i <= n; i++)
        {
            int square = i * i;
            if (square / 10 == 0)
            {
                continue;
            }
            sum += recursive(i, 0, square);
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    int number = 10;
    int res = sol.punishmentNumber(number);
}
