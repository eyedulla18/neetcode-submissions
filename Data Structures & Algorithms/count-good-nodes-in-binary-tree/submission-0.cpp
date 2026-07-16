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

    void helper(TreeNode* root, int ceiling, int& answer){
        if(!root){
            return;
        }
        if(root->val>=ceiling){
            cout<<"good node: "<<root->val<<'\n';
            answer+=1;
        }
        else{
            cout<<"bad node: "<<root->val<<" ceiling: "<<ceiling <<'\n';
 
        }
        helper(root->left, max(ceiling, root->val), answer);
        helper(root->right, max(ceiling, root->val), answer);


    }

    int goodNodes(TreeNode* root) {
        int answer = 0;
        helper(root, root->val, answer);
        return answer;
    }
};

// [3,3,null,4,2] 
//         3
//     3
// 4       2


