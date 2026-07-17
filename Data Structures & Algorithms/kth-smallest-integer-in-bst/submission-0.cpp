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

    void helper(TreeNode* root, int& k, int& answer){
        if(!root){
            return;
        }
        //left
        helper(root->left, k, answer);
        //current
        k-=1;
        cout<<"k="<<k<<" rootVal="<<root->val<<'\n';
        if(k==0){
            answer = root->val;
        }
        //right
        helper(root->right, k, answer);
        
    }

    int kthSmallest(TreeNode* root, int k) {
        int answer = -999;
        helper(root, k, answer);
        return answer;
    }
};
