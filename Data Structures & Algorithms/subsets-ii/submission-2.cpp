class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> answer = {{}};
        vector<vector<int>> previousRound;
        for(int i=0; i<nums.size(); ++i){
            int num = nums[i];

            //if nums[i]==nums[i-1]
            //only add the current number to the previous round 
            if(i!=0 && nums[i]==nums[i-1]){
                auto tmpPrevious = previousRound;
                previousRound.clear();
                for(auto prev: tmpPrevious){
                    prev.push_back(num);
                    previousRound.push_back(prev);
                    answer.push_back(prev);
                }
                continue;
            }

            auto updatedAnswer = answer;
            previousRound.clear();
            for(vector<int> a: answer){
                a.push_back(num);
                updatedAnswer.push_back(a);
                previousRound.push_back(a);
            }
            answer = updatedAnswer;

        }
        return answer;


    }
};
