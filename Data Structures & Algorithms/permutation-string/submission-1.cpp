class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()> s2.size()){
            return false;
        }

        int subStringSize= s1.size(); //this serves as the searching window size through s2
        int l=0;
        int r=0;
        vector<int> s1State(26, 0);
        for(char c: s1){
            s1State[c-'a']++;
        }


        vector<int> curState(26, 0);
        curState[s2[0]- 'a']++;

        while(l<s2.size() && r<s2.size()){
            if(r-l+1<subStringSize){
                ++r;
                curState[s2[r] - 'a']++;
                continue;
            }
            cout<<l<<"  "<<r<<'\n';

            //check if curState is good;
            if(curState==s1State){
                return true;
            }

            //remove l from map
            curState[s2[l]- 'a']--; 
            ++l;
            ++r;
            //add r to map
            if(r<s2.size()){
                curState[s2[r]- 'a']++; 
            }
        }
    return false;

    }
};
