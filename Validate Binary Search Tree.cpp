class Solution {
public:
 long long ans=LONG_MIN;
  void calculate(TreeNode* root,bool& istrue)
    {
        if(root==NULL)
        return;

        calculate(root->left,istrue);
        if(ans>=root->val)
        istrue=false;
        ans=root->val;
        calculate(root->right,istrue);
    }
    bool isValidBST(TreeNode* root) {
        bool istrue=true;
        calculate(root,istrue);
        return istrue;   
    }
};
