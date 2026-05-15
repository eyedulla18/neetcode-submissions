class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groupedStrings;
        for(string str: strs){
            string sortedString = str;
            sort(sortedString.begin(), sortedString.end());
            groupedStrings[sortedString].push_back(str);
        }
        vector<vector<string>> ret;
        for(const auto& groupedPairs: groupedStrings){
            ret.push_back(groupedPairs.second);
        }
        return ret; 
    }
};
