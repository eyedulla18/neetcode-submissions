class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        unordered_set<int> fixedSet;
        for(int fixedIdx=0; fixedIdx<nums.size(); ++fixedIdx){
            int fixedValue = nums[fixedIdx];
            if(fixedSet.find(fixedValue) != fixedSet.end()){
                continue;
            }
            else{
                fixedSet.insert(fixedValue);
            }
            
            int start = fixedIdx + 1;
            int end = nums.size()-1;

            while(start<end){
                if(nums[start]+nums[end]+fixedValue==0){
                    answer.push_back({fixedValue, nums[start], nums[end]});
                    while(start+1<nums.size() && nums[start]==nums[start+1]){
                        ++start;
                    }
                    ++start;
                    // break;
                }
                else if(nums[start]+nums[end]+fixedValue<0){
                    // while(start+1<nums.size() && nums[start]==nums[start+1]){
                    //     ++start;
                    // }
                    ++start;
                }
                else if(nums[start]+nums[end]+fixedValue>0){
                    // while(end-1>0 && nums[end]==nums[end-1]){
                    //     --end;
                    // }
                    --end;
                }
            }
        }
        return answer;

    }
};
