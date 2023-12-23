class Solution {
public:
    void recursive(TreeNode* root, int level, vector<vector<int>>& result) {
        if (root == NULL) return;
        if (result.size() <= level) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        if (root->left != NULL) {
            recursive(root->left, level + 1, result);
        }
        if (root->right != NULL) {
            recursive(root->right, level + 1, result);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> re;
        recursive(root, 0, re);
        return re;
    }
};