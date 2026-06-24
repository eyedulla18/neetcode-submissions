class Solution {
public:
    int findMin(vector<int> &nums) {
        //mid greater than right means the pivot is to the right 
        //mid less than right means the pivot is to the left 
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>nums[r]){
                l = m + 1;
            }
            else if(nums[m]<nums[r]){
                r = m;
            }
        }
        return nums[l];

    }
};

//[4,5,0,1,2,3] m=0
//[4,5,0] m=5
//[0] m=5



//[3,4,5,6,1,2] m=5
//[6,1,2] m=1
//[1,2] m=1



