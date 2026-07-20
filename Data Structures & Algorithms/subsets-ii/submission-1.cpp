class Solution {
public:
    //[1,1,2]
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer = {{}};

        int newAnswersSize = 0;
        for(int i=0; i<nums.size(); ++i){
            vector<vector<int>> newAnswers;

            int start = 0;
            if(i!=0 && nums[i]==nums[i-1]){
                start = answer.size()-newAnswersSize;
            }

            for(int aIdx=start; aIdx<answer.size(); ++aIdx){

                vector<int> curAnswer = answer[aIdx];
                curAnswer.push_back(nums[i]);
                newAnswers.push_back(curAnswer);

            }
            answer.insert(answer.end(), newAnswers.begin(), newAnswers.end());
            newAnswersSize = newAnswers.size();
        }
        return answer;


    }
};
