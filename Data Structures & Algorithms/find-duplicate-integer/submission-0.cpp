class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> tracker(nums.size(), false);

        for(auto num: nums){
            if(tracker[num-1]){
                return num;
            }
            tracker[num-1] = true;
        }
        return -1;
    }
};
