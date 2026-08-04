class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp = nums;
        if(nums.size()==1){
            return nums[0];
        }
        int answer = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); ++i){
            for(int j=0; j<i-1; ++j){
                dp[i] = max(dp[i], nums[i]+dp[j]);
                answer = max(answer, dp[i]);
            }
        }
        return answer;

    }
};
// 9,8,3,20