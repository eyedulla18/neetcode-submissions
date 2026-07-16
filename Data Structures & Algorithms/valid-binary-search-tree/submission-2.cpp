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

    bool helper(TreeNode* root, int floor, int limit){
        if(!root){
            return true;
        }
        if(root->val<=floor || root->val>=limit){
            cout<<"fails when val="<<root->val<<" floor="<<floor<<" limit="<<limit<<'\n';
            return false;
        }

        return helper(root->left, floor, root->val) && helper(root->right,root->val, limit);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, std::numeric_limits<int>::min(), numeric_limits<int>::max());
    }
};
