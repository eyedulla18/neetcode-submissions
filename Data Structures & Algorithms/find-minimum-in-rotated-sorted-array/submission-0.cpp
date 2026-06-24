class Solution {
public:
    int findMin(vector<int> &nums) {
        //mid greater than right means the pivot is to the right 
        //mid less than right means the pivot is to the left 
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            if(r-l==1){
                return min(nums[r], nums[l]);
            }
            int m = (l+r)/2;
            if(nums[m]>nums[r]){
                l = m + 1;
            }
            else if(nums[m]<nums[r]){
                r = m;
            }

            cout<<"l and r "<<l<<"  "<<r<<'\n';
            for(int i=l; i<r+1; ++i){
                cout<<nums[i]<<" ";
            }
            cout<<'\n';
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



