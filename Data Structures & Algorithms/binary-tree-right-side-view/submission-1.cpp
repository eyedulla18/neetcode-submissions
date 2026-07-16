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
        return max(depth(root->right), depth(root->left)) + 1;
    }

    vector<int> rightSideView(TreeNode* root) {
        //do level order traversal and store the values for each row 
        //only take the last element from each level 
        auto treeDepth = depth(root);
        cout<<"treeDepth: "<<treeDepth<<'\n';

        vector<int> empty;
        vector<vector<int>> tree(treeDepth, empty);
        stack<pair<int, TreeNode*>> stk;
        stk.push({0, root});

        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            auto topNode = top.second;
            auto topDepth = top.first;
            if(!topNode){
                continue;
            }
            tree[topDepth].push_back(topNode->val);
            stk.push({topDepth+1, topNode->right});
            stk.push({topDepth+1, topNode->left});
        }
        vector<int> answer;
        for(auto level: tree){
            answer.push_back(level.back());
        }
        return answer;
        return {};


    }
};
