class Solution {
public:

    vector<vector<string>> answer;
    bool isPalindrome(string& s){
        auto copy = s;
        reverse(copy.begin(), copy.end());
        if(s==copy){
            return true;
        }
        return false;
    }

    void helper(string s, vector<string> curAnswer){
        if(curAnswer.empty()){
            curAnswer = {{s.back()}};
            s.pop_back();
        }
        // cout<<curAnswer.back()<<'\n';
        if(s.empty()){
            if(isPalindrome(curAnswer.back())){
                answer.push_back(curAnswer);
            }
            return;
        }

        //1. push back onto the previous word 
        string lastWordCopy = curAnswer.back();
        if(!curAnswer.back().empty()){
            string sCopy = s;
            lastWordCopy += sCopy.back();
            sCopy.pop_back();
            vector<string> curAnswerCopy = curAnswer;
            curAnswerCopy.back()=lastWordCopy;
            helper(sCopy, curAnswerCopy); 
        }
        //2. start a new word         
        {
            //only start a new word if the previous word is a palindrome 
            if(!isPalindrome(curAnswer.back())){
                return;
            }

            string sCopy = s;
            vector<string> curAnswerCopy = curAnswer;
            string newPalindrome{sCopy.back()};
            curAnswerCopy.push_back(newPalindrome);
            sCopy.pop_back();
            helper(sCopy, curAnswerCopy);
        }
 

    }

    vector<vector<string>> partition(string s) {
        //consider every single grouping of words 
        reverse(s.begin(), s.end());
        helper(s, {});
        return answer;


    }
};
