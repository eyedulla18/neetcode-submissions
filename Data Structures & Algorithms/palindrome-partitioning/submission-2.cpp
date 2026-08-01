class Solution {
public:

    vector<vector<string>> answer;

    bool isPalindrome(string s){
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        if(s==reversed){
            return true;
        }
        return false;

    }

    void helper(string& s, int i, int j, vector<string> cur){
        if(j==s.size()){
            string word(s.begin()+i, s.begin()+j);
            if(isPalindrome(word)){
                cur.push_back(word);
                answer.push_back(cur);
            }
            return;
        }

        //make the word bigger
        helper(s, i, j+1, cur);

        //add the current word
        string word(s.begin()+i, s.begin()+j);
        if(isPalindrome(word)){
            cur.push_back(word);
            helper(s, j, j+1, cur);
        }
    }

    vector<vector<string>> partition(string s) {
        helper(s, 0,1,{});
        return answer;
    }
};
