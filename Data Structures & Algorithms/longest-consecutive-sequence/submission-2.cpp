class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        set<int> numsSet(nums.begin(), nums.end());
        int answer = 1;
        for(auto x: numsSet){
            bool nextFound = true;
            int cur = x;
            while(nextFound){
                if(numsSet.find(cur+1)==numsSet.end()){
                    nextFound=false;
                }
                else{
                    ++cur;
                    answer = max(answer, cur-x+1);
                }
            }
        }
        return answer;
    }
};
