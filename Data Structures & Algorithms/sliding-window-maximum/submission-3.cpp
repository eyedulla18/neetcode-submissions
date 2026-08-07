class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> answer;
        int curMax = nums[0];
        for(int i=0; i<k; ++i){
            ++freq[nums[i]];
            curMax = max(curMax, nums[i]);
        }
        answer.push_back(curMax);

        for(int i=k; i<nums.size(); ++i){
            //remove 1 from nums[i-k]
            cout<<nums[i]<<'\n';
            --freq[nums[i-k]];
            ++freq[nums[i]];

            curMax = max(curMax, nums[i]);
            if(freq[curMax]==0){
                // cout<<"max is at 0 freq \n";
                curMax = nums[i];
                for(auto kv: freq){
                    if(kv.second!=0){
                        // cout<<"attempting to set new curMax \n";
                        curMax = max(curMax, kv.first);
                    }
                }
            }
            answer.push_back(curMax);
        }
        return answer;
    }
};
