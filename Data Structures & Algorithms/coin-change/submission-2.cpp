class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount+1, 10001);

        dp[0] = 0;

        //add a coin to each reachable state 
        bool go = true;
        while(go){
            go = false;
            for(int amt=0; amt<dp.size(); ++amt){
                if(dp[amt]==10001){
                    continue;
                }
                for(auto coin: coins){
                    if(amt>amount-coin){
                        continue;
                    }
                    int newAmt = amt + coin;
                    if(dp[amt]+1<dp[newAmt]){
                        dp[newAmt]=dp[amt]+1;
                        go=true;
                    }
                }

            }
        }
        for(auto x: dp){
            cout<<x<<" ";
        }
        if(dp.back()==10001){
            return -1;
        }
        return dp.back();



    }
};
