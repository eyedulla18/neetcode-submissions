class Solution {
public:

    int curMaxFreq(unordered_map<char, int>& ump){
        int maxFreq= 0;
        cout<<"state of map: \n";
        for(auto kvp: ump){
            maxFreq = max(maxFreq, kvp.second);
            cout<<kvp.first<<"  "<<kvp.second<<'\n';
        }
        return maxFreq;
    }

    int characterReplacement(string s, int k) {
        int l=0;
        int r=1;
        unordered_map<char, int> ump;
        ump[s[0]]++;
        int answer=1;
        while(l<s.size() && r<s.size()){
            cout<<l<<"  "<<r <<'\n';
            ump[s[r]]++;
            int curTotal = r-l+1; 
            int curLargestCharTotal = curMaxFreq(ump);
            cout<<"curLargestCharTotal="<<curLargestCharTotal<<'\n';
            int curTotalSubs = curTotal - curLargestCharTotal;
            cout<<"number subs="<<curTotalSubs<<'\n';

            while(curTotalSubs>k && l+1<s.size() && l<r){
                cout<<"rebalance by removing "<<s[l] <<'\n';
                // ++l;
                ump[s[l]]--;
                ++l;
                curTotal = r-l;
                curLargestCharTotal = curMaxFreq(ump);
                curTotalSubs = curLargestCharTotal - curTotal;
            }
            answer = max(answer, r-l+1); 
            ++r;

        }

        return answer;
    }
};
