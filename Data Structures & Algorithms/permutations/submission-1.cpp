class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer = {{}};

        for(auto num: nums){
            vector<vector<int>> newAnswer;
            for(auto partialAnswer: answer){
                for(int i=0; i<=partialAnswer.size(); ++i){
                    auto partialAnswerCopy = partialAnswer;
                    //insert num into partialAnswerCopy at position i 
                    partialAnswerCopy.insert(partialAnswerCopy.begin()+i, num);
                    newAnswer.push_back(partialAnswerCopy);
                }
            }
            answer = newAnswer;
        }
        return answer;
    }
};
