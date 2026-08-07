class Solution {
public:
    int countSubstrings(string s) {
        int answer =s.size();
        //odd case
        for(int i=0; i<s.size(); ++i){
            // cout<<i<<'\n';
            int l=i-1;
            int r = i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                // cout<<"while \n";
                ++answer;
                --l;
                ++r;
            }

        }

        //even case
        for(int i=0; i<s.size(); ++i){
            // cout<<i<<'\n';
            int l=i-1;
            int r = i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                // cout<<"while \n";
                ++answer;
                --l;
                ++r;
            }

        }
        return answer;

    }
};
