class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char, int> ump;  
        for(const auto letter: s){
            ++ump[letter];
        }
        for(const auto letter: t){
            --ump[letter];
        }
        for(const auto& umpPair: ump){
            if(umpPair.second!=0){
                return false;
            }
        }
        return true; 

    }
};
