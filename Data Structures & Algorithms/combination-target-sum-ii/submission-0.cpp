class Solution {
public:

    vector<vector<int>> answer;
    void helper(vector<int>& candidates, vector<int> cur, int target, int idx){
        // if(cur.size()==1){
        //     return;
        // }
        if(target==0){
            answer.push_back(cur);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=idx; i<candidates.size(); ++i){
            if(target-candidates[i]<0){
                return;
            }
            if(i>idx && candidates[i]== candidates[i-1]){
                continue;
            }
            vector<int> curCopy(cur);
            curCopy.push_back(candidates[i]);
            helper(candidates, curCopy, target-candidates[i], i+1);
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, {}, target, 0);
        return answer;

    }
};
