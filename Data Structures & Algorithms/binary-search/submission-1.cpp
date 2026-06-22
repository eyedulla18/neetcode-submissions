class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l= 0;
        int r= nums.size()-1;
        if(nums.size()==1 && nums[0]==target){
            return 0;
        }

        while(l<r){
            cout <<l<<"  "<<r<<'\n'; 
            //check the base case where there are only two left in the search 
            if(r-l==1){
                if(nums[l]==target){
                    return l;
                }
                else if(nums[r]==target){
                    return r;
                }
                return -1;
            }

            int midIdx = (l + r)/2;
            if(nums[midIdx]==target){
                return midIdx;
            }
            else if(nums[midIdx]>target){
                r = midIdx;
                continue;
            } 
            else if(nums[midIdx]<target){
                l = midIdx;
                continue;
            }
        }
        return -1;

    }
};
