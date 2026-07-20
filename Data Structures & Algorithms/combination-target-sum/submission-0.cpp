class Solution {
public:

    void helper(vector<int>& nums, int target, vector<int> cur, vector<vector<int>>& answer){
        // cout<<"cur state: \n";
        // cout<<"target= "<<target<<'\n';
        // cout<<"cur values: ";
        // for(auto x: cur){
        //     cout<<x<<" ";
        // }
        // cout<<"\n\n";
        
        if(target==0){
            answer.push_back(cur);
            return;
        }
        if(target<0){
            return;
        }

        for(auto num: nums){
            if(target-num<0){
                return;
            }
            if(!cur.empty()&&num<cur.back()){
                continue;
            }
            vector<int> curCopy(cur);
            curCopy.push_back(num);
            helper(nums, target-num, curCopy, answer);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        helper(nums, target, {}, answer);
        return answer;
    }
};
