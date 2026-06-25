class Solution {
public:

    int findMinIdx(vector<int>& nums, int target){
        int l=0;
        int r=nums.size()-1;

        while(l<r){
            int m = (l+r)/2;

            if(nums[m]>nums[r]){
                l = m+1;
            }
            else{
                r=m;
            }
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        int minIdx = findMinIdx(nums, target);
        cout<<"minIdx: "<<minIdx<<'\n';

        int l = -1;
        int r = -1;

        if(target > nums.back()){
            l=0;
            r=minIdx-1;
        }
        else{
            l=minIdx;
            r=nums.size()-1;
        }

        while(l<r){
            int m = (l+r)/2;
            if(nums[m]==target){
                return m;
            }

            else if(nums[m]>target){
                r = m -1;
            }
            else{
                l = m+1;
            }
            cout<<l<<" "<<r<<'\n';

        }
        if(nums[l]==target){
            return l;
        }
        return -1;

    }
};
