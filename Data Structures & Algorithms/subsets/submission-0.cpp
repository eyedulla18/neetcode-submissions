class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        answer.push_back({});

        for(auto num: nums){
            vector<vector<int>> partialAnswer;
            for(auto cur: answer){
                cur.push_back(num);
                partialAnswer.push_back(cur);
            }
            answer.insert(answer.end(), partialAnswer.begin(), partialAnswer.end());
        }
        return answer;

    }
};
