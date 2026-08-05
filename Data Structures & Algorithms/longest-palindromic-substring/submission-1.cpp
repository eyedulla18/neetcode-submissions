class Solution {
public:
    string longestPalindrome(string s) {
        string answer{s[0]};
        for(int i=0; i<s.size(); ++i){
            //i is the index of the center
            int l=i-1;
            int r =i+1;
            string cur{s[i]};
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    cur = s[l]+cur+s[r];
                    --l;
                    ++r;
                }
                else{
                    break;
                }
            }
            if(answer.size()<cur.size()){
                answer = cur;
            }
        }

        for(int i=0; i<s.size()-1; ++i){
            //i is the index of the center
            int l=i;
            int r =i+1;
            if(s[l]!=s[r]){
                continue;
            }
            string cur;
            while(l>=0 && r<s.size()){
                if(s[l]==s[r]){
                    cur = s[l]+cur+s[r];
                    --l;
                    ++r;
                }
                else{
                    break;
                }
            }
            if(answer.size()<cur.size()){
                answer = cur;
            }
        }
        return answer;
    }
};
