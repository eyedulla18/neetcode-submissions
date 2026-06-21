#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        int l=0;
        int r=1;

        int answer = 1;
        unordered_set<char> curChars;
        curChars.insert(s[0]);
        while(l<s.size() && r<s.size()){
            //add the character at the right pointer 
            if(curChars.find(s[r])==curChars.end()){
                curChars.insert(s[r]);
                answer= max(answer, int(curChars.size()));
                cout<<"insert: "<<s[r]<<" answer: "<< answer<<" \n";

            }
            else{
                //move left one past the previous instance of the current character
                while(s[l]!=s[r]){
                    //remove from set
                    curChars.erase(s[l]);
                    cout<<"remove: "<<s[l]<<" setSize: "<< curChars.size()<<" \n";
                    ++l;
                }
                ++l;
            }
            ++r;
        }
        return answer;

    }
};
