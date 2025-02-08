
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

class NumberContainers {
public:
    NumberContainers() {}

    void change(int index, int number) {
        if (inds.contains(index)) {
            nums[inds[index]].erase(index);
            inds[index] = number;
            nums[number].insert(index);
        }
        else {
            inds[index] = number;
            nums[number].insert(index);
        }
    }

    int find(int number) {
        if (nums.contains(number)) {
            if (nums[number].size() > 0) {
                return *nums[number].begin();
            }
            else {
                -1;
            }
        }
        return -1;
    }
private:
    map<int, set<int>> nums{};
    map<int, int> inds{};
};


int main()
{
    return 0;
}
