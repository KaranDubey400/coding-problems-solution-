class Solution {
public:
    pair<int, TreeNode*> helper(TreeNode* root) {
        if (!root) return {0, nullptr}; // Base case: null node -> depth 0, no LCA

        // Recur for left and right subtrees
        auto [left_depth, left_LCA] = helper(root->left);
        auto [right_depth, right_LCA] = helper(root->right);

        if (left_depth == right_depth) return {left_depth + 1, root}; // Current node is LCA
        if (left_depth > right_depth) return {left_depth + 1, left_LCA}; // Left subtree is deeper
        return {right_depth + 1, right_LCA}; // Right subtree is deeper
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).second;
    }
};
