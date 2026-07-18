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

    void destPath(TreeNode* root, TreeNode* destination, vector<TreeNode*>& path){
        if(!root){
            return;
        }
        int curVal = root->val;
        cout<<curVal<<" ";
        path.push_back(root);
        if(destination->val==curVal){
            return;
        }
        else if(destination->val>curVal){
            destPath(root->right, destination, path);
        }
        else{
            destPath(root->left, destination, path);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //find the paths to p and q 
        //return the smallest number in both paths 

        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;
        cout<<"pPath: \n";
        destPath(root, p, pPath);
        cout<<"\nqPath: \n";
        destPath(root, q, qPath);

        cout<<'\n'<<pPath.size()<<" "<<qPath.size()<<"\n";
        auto lastCommon = root;
        for(auto node: pPath){
            cout<<" "<<node->val<<'\n';
            if(find(qPath.begin(), qPath.end(), node)!= qPath.end()){
                lastCommon = node;
            }
        }

        return lastCommon; 

    }
};
