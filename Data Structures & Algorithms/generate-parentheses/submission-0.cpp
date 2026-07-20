class Solution {
public:

    vector<string> answer;

    void helper(int left, int right, string cur){
        //left always has to be less than or equal right
        if(left>right){
            return;
        }
        if(left<0 || right<0){
            return;
        }
        if(left==0 && right==0){
            answer.push_back(cur);
            return;
        }

        auto curLeft = cur;
        curLeft+="(";
        helper(left-1, right, curLeft);

        auto curRight = cur;
        curRight+=")";
        helper(left, right-1, curRight);
    }

    vector<string> generateParenthesis(int n) {
        helper(n,n,"");
        return answer;
    }
};
