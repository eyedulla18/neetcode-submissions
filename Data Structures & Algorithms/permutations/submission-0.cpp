class Solution {
public:

    vector<vector<int>> answer;

    void helper(set<int> nums, vector<int> curPerm){
        if(nums.size()==0){
            answer.push_back(curPerm);
            return;
        }
        for(auto num: nums){
            auto numsCopy = nums;
            auto curPermCopy = curPerm;
            numsCopy.erase(num);
            curPermCopy.push_back(num);
            helper(numsCopy, curPermCopy);
        }


    }

    vector<vector<int>> permute(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        helper(numSet, {});
        return answer;
    }
};
