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

    int depth(TreeNode* root){
        if(!root){
            return 0;
        }

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        return max(leftDepth, rightDepth) + 1;


    }

    void helper(TreeNode* root, int depth, vector<vector<int>>& answer){
        if(!root){
            return;
        }
        answer[depth].push_back(root->val);
        helper(root->left, depth+1, answer);
        helper(root->right, depth+1, answer);

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> empty;
        vector<vector<int>> answer(depth(root), empty);
        helper(root, 0, answer);

        return answer;
    }
};
