
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "parser.h"
#include "parser.h"

using namespace std;

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> chain;
        int dash_count = 0;
        int temp_val = 0;
        for (int i = 0; i < traversal.size(); i++) {
            if (traversal[i] == '-') {
                dash_count++;
            }
            else {
                if (i != traversal.size() - 1 && traversal[i + 1] != '-') {
                    temp_val = temp_val * 10 + int(traversal[i] - '0');
                    continue;
                }
                if (chain.size() <= dash_count)
                {
                    chain.push_back(new TreeNode(temp_val * 10 + int(traversal[i] - '0')));
                }
                else
                {
                    chain[dash_count] = new TreeNode(temp_val * 10 + int(traversal[i] - '0'));
                }
                temp_val = 0;
                if (dash_count == 0)
                {
                    continue;
                }
                if (chain[dash_count - 1]->left) {
                    chain[dash_count - 1]->right = chain[dash_count];
                }
                else {
                    chain[dash_count - 1]->left = chain[dash_count];
                }
                dash_count = 0;
            }
        }
        return chain[0];
    }
};

int main()
{
    Solution sol;
    std::string input{ "1-2--3--4-5--6--7" };
    TreeNode* res = sol.recoverFromPreorder(input);
}
