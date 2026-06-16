class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;

        while(l<r){
            int curTotal = numbers[l] + numbers[r];
            if(curTotal < target){
                ++l;
            }
            else if(curTotal > target){
                --r;
            }
            else if(curTotal==target){
                return {l+1,r+1};
            }
        }
        return {-1,-1};

    }
};
