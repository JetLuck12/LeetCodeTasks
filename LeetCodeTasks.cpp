
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
 TreeNode* recursive(TreeNode* root, vector<int>& preorder, vector<int>& postorder) {
     if (preorder.empty()) {
         return root;
     }
     int val_left = preorder[0];
     int val_right = postorder.back();
     if (val_left == val_right) {
         vector<int> pre(preorder.begin() + 1, preorder.end());
         vector<int> post(postorder.begin(), postorder.end() - 1);
         TreeNode* child = recursive(new TreeNode(preorder[0]), pre, post);
         root->left = child;
     }
     else {
         int pre_in_post;
         int post_in_pre;
         for (int i = 1; i < preorder.size(); i++) {
             if (preorder[i] == val_right) {
                 post_in_pre = i;
                 break;
             }
         }
         for (int i = 0; i < postorder.size()-1; i++) {
             if (postorder[i] == val_left) {
                 pre_in_post = i;
                 break;
             }
         }
         vector<int> pre(preorder.begin() + 1, preorder.begin() + post_in_pre);
         vector<int> post(postorder.begin(), postorder.begin() + pre_in_post);
         TreeNode* left = recursive(new TreeNode(val_left), pre, post);
         root->left = left;
         pre = vector<int>(preorder.begin() + post_in_pre + 1, preorder.end());
         post = vector<int>(postorder.begin() + pre_in_post + 1, postorder.end() - 1);
         TreeNode* right = recursive(new TreeNode(val_right), pre, post);
         root->right = right;
     }
     return root;
 }

 class Solution {
 public:
     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         vector<int> pre(preorder.begin() + 1, preorder.end());
         vector<int> post(postorder.begin(), postorder.end() - 1);
         TreeNode* root = recursive(new TreeNode(preorder[0]), pre, post);
         return root;
     }
 };

int main()
{
    Solution sol;
    std::string input{ "[2,1,3]" };
    std::string input2{ "[3,1,2]" };
    std::vector<int> preorder = Parser::process_vector(input);
    std::vector<int> postorder = Parser::process_vector(input2);
    TreeNode* res = sol.constructFromPrePost(preorder, postorder);
}
