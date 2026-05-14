class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       //map of goal value, counterpartIdx
       unordered_map<int,int> sumUmp;
       for(int i=0; i<nums.size(); ++i){
        const int num = target - nums[i];
        const int goal = target - num;
        //check if the map already has the goal 
        if(sumUmp.find(num)!=sumUmp.end()){
            return {sumUmp[num], i};
        } 
        sumUmp[goal] = i;
       } 
       return {-1,-1};
    }
};
