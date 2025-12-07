/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
       
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        
        while (!q.empty()) {
            auto [node, currentSum] = q.front();
            q.pop();
            
           
            if (node->left == nullptr && node->right == nullptr && currentSum == targetSum) {
                return true;
            }
            
            if (node->left != nullptr) {
                q.push({node->left, currentSum + node->left->val});
            }
            if (node->right != nullptr) {
                q.push({node->right, currentSum + node->right->val});
            }
        }
        
        return false;
    }
};