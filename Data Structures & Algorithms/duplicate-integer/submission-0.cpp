class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std:set<int> numSet;
        for(const auto& num: nums){
            if(numSet.find(num)==numSet.end()){
                numSet.insert(num);
            }
            else{
                return true; 
            }
        }
        return false;
    }
};