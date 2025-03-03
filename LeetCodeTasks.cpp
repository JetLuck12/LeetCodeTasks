
#include <iostream>
#include <map>
#include <queue>
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

class FindElements {
public:
    TreeNode* root_;
    FindElements(TreeNode* root) {
        root_ = root;
        root_->val = 0;
        queue<TreeNode*> queue;
        queue.push(root_);
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            if (cur->left != NULL) {
                cur->left->val = cur->val * 2 + 1;
                queue.push(cur->left);
            }
            if (cur->right != NULL) {
                cur->right->val = cur->val * 2 + 2;
                queue.push(cur->right);
            }
        }
    }

    bool find(int target) {
        vector<bool> directs;
        int temp = target;
        while (temp != 0) {
            directs.push_back(temp % 2);
            temp = (temp - 1) / 2;
        }
        auto cur = root_;
        for (auto x = directs.rbegin(); x != directs.rend(); x++) {
            if (*x) {
                if (cur->left == NULL) {
                    return false;
                }
                cur = cur->left;
            }
            else {
                if (cur->right == NULL) {
                    return false;
                }
                cur = cur->right;
            }
        }
        if (cur->val == target) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    std::string input{ "[[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]" };
    std::vector<std::vector<int>> grid = Parser::process_vector_vector(input);
    //long long res = sol.findMaxFish(grid);
}
