class Solution {
public:
    int climbStairs(int n) {
       vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int stair=2; stair<n+1; ++stair){
            dp[stair] = dp[stair-2] + dp[stair-1];
        }

        return dp.back();

    }
};
