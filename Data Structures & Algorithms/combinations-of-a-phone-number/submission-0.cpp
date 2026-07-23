class Solution {
public:
    unordered_map<char, vector<char>> ump = {
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}},
    };

    vector<string> answer;

    void helper(string& digit, int idx, string cur){

        if(idx>=digit.size()){
            if(cur!=""){
                answer.push_back(cur);
            }
            return;
        }

        auto& characters = ump[digit[idx]];
        for(const auto& character: characters){
            helper(digit, idx+1, cur+character);
        }
    }

    vector<string> letterCombinations(string digits) {
        helper(digits, 0, "");
        return answer;
    }
};
