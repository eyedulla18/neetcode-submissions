class Solution {
public:

    void helper(vector<int>& nums){
        for(int i=1; i<nums.size(); ++i){
            if(!nums[i-1]==0){
                nums[i] = nums[i-1] * nums[i];
            }
        }
    }

    int maxProduct(vector<int>& nums) {
        vector<int> lr = nums;
        helper(lr);
        
        vector<int> rl = nums;
        reverse(rl.begin(), rl.end());
        helper(rl);
        reverse(rl.begin(), rl.end());

        // for(auto x: lr){
        //     cout<<x<<" ";
        // }
        // cout<<'\n';
        
        // for(auto x: rl){
        //     cout<<x<<" ";
        // }
        // cout<<'\n';

        int answer= max(*max_element(lr.begin(), lr.end()), *max_element(rl.begin(), rl.end()));
        answer = max(*max_element(nums.begin(), nums.end()), answer);
        return answer;
    }
};
