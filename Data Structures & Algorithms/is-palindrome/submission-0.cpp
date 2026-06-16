class Solution {
public:
    bool isPalindrome(string s) {
        //odd value case
        //abc 

        //even value case
        //abcd

        int startIdx=0;
        int endIdx = s.size()-1;

        while(startIdx<=endIdx){
            if(!isalnum(s[startIdx])){
                ++startIdx;
                continue;
            }
            if(!isalnum(s[endIdx])){
                --endIdx;
                continue;
            }
            if(tolower(s[startIdx])!=tolower(s[endIdx])){
                cout<<"start: "<<startIdx<<"end: "<<endIdx;
                return false;
            }
            ++startIdx;
            --endIdx;
        }
        return true;
        
    }
};
