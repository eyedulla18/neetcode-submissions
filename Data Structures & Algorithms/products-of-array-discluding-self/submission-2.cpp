class Solution {
public:

    vector<int> multLeft(vector<int>& nums){
        //set base
        vector<int> retVec = {1};
        for(int i=1; i<nums.size(); ++i){
            retVec.push_back(retVec[i-1] * nums[i-1]);
        }
        return retVec;
    }

    void printVec(vector<int>& nums){
        for(auto num: nums){
            cout<<num<<" ";
        }
        cout<<"\n";
    }



    vector<int> productExceptSelf(vector<int>& nums) {
        // 01,01,02,08
        // 48,24,06,01
        vector<int> lr = multLeft(nums);
        reverse(nums.begin(), nums.end());
        vector<int> rl = multLeft(nums);
        reverse(rl.begin(), rl.end());
        printVec(lr);
        printVec(rl);

        vector<int> answer;
        for(int i=0; i<nums.size(); ++i){
            answer.push_back(lr[i]*rl[i]);
        }


        return answer;



    }
};
