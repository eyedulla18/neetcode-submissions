class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer; 
        for(int i=0; i<nums.size(); ++i){
            int setValue = nums[i];
            if(i!=0 && setValue==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=nums.size()-1;
            while(l<r && l<nums.size() && r>=0){
                if(setValue + nums[l] + nums[r] == 0){
                    answer.push_back({setValue, nums[l], nums[r]});
                    //increment l until its unique 
                    while(l+1<nums.size() && nums[l]==nums[l+1]){
                        ++l;
                    }
                    ++l;
                }
                else if(setValue + nums[l] + nums[r] > 0){
                    --r;
                }
                else if(setValue + nums[l] + nums[r] < 0){
                    ++l;
                }
            }
        }
        return answer;
    }
};
