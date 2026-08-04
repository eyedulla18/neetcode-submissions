class Solution {
public:

    int helper(vector<int> nums){
        vector<int> dp = nums;
        if(nums.size()==1){
            return nums[0];
        }
        int answer = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); ++i){
            for(int j=0; j<i-1; ++j){
                dp[i] = max(dp[i], nums[i] + dp[j]);
                answer = max(answer, dp[i]);
            }
        }

        for(auto cur: dp){
            cout<<cur<<" ";
        }
        cout<<'\n';
        return answer;

    }

    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> ignoreFirst(nums.begin()+1, nums.begin()+nums.size());
        vector<int> ignoreLast(nums.begin(), nums.begin()+nums.size()-1);

        return max(helper(ignoreFirst), helper(ignoreLast));
    }
};
