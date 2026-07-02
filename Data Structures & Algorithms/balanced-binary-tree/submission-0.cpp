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

    int helper(TreeNode* root, bool& balanced) {
        if(!root){
            return 0;
        }
        int leftDepth = helper(root->left, balanced);
        int rightDepth = helper(root->right, balanced);

        if(abs(leftDepth-rightDepth)>1){
            balanced = false;
        }

        return max(leftDepth,rightDepth) + 1;

    }

    bool isBalanced(TreeNode* root) {
        bool answer = true;
        helper(root, answer);
        return answer;

    }
};
