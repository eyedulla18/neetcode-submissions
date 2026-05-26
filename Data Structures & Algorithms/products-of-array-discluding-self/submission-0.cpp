class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [01,02,04,06]
        // [01,02,08,48] 
        // [48,48,24,06]

        // [01,02,04,06]
        // [01]


        // [-1,0,1,2,3]
        // [-1,]

        //case where there is 0, 1, 2 zeros
        int zeroCount = 0;
        for(const auto& num: nums){
            if(num==0){
                ++zeroCount;
            }
        }

        vector<int> retVec = {};
        if(zeroCount > 1){
            for(const auto& num: nums){
                retVec.push_back(0);
            }
            return retVec;
        }


        //find mult of everything
        int totalMult = 1;
        for(const auto& num: nums){
            if(num!=0){
                totalMult *= num;
            }
        }

        if(zeroCount==1){
            for(int i=0; i<nums.size(); ++i){
                int curNum = nums[i];
                if(curNum == 0){
                    retVec.push_back(totalMult);
                }
                else{
                    retVec.push_back(0);
                }
            }
            return retVec;
        }
        for(int i=0; i<nums.size(); ++i){
            int curNum = nums[i];
            retVec.push_back(totalMult/curNum);
        }
        return retVec;
        

    }
};
