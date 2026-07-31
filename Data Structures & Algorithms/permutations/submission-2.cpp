class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
    vector<vector<int>> answer = {{}};

    for(auto num: nums){
        vector<vector<int>>  tmpAnswer;
        for(vector<int> a: answer){
            for(int i=0; i<=a.size(); ++i){
                auto aCopy = a;
                aCopy.insert(aCopy.begin()+i, num);
                tmpAnswer.push_back(aCopy);
            }
        }
        answer = tmpAnswer;
    }

    return answer;

    }
};
