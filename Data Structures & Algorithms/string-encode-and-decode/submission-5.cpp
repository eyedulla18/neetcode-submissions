#include <ranges>
class Solution {
public:

    string encode(vector<string>& strs) {
        // auto sizeString = strs | ranges::views::transform([](const std::string& str){
        //     return to_string(str.size());
        // })
        // | ranges::views::join_with(string(","))
        // | ranges::to<std::string>();

        string sizeString = "";
        for(size_t idx = 0; idx<strs.size(); ++idx){
            if(idx != strs.size()-1){
                sizeString += to_string(strs[idx].size()) + ",";
            }
            else{
                sizeString += to_string(strs[idx].size());
            }
        }

        auto concatStrings = strs | ranges::views::join | ranges::to<std::string>();
        const string encoded = sizeString + "#" + concatStrings;
        cout<<encoded<<"\n";
        return encoded;

    }

    vector<string> decode(string s) {
        size_t poundIdx = 0;
        for(; poundIdx<s.size(); ++poundIdx){
            if(s[poundIdx]=='#'){
                break;
            }
        }
        string sizeString = s.substr(0,poundIdx);
        string concatString = s.substr(poundIdx + 1);
        cout<<sizeString<<"   "<<concatString<<'\n';

        vector<string> retVec;
        int curIdx = poundIdx + 1;
        for(auto splitSize: views::split(sizeString, ',')){
            int size = stoi(ranges::to<string>(splitSize));
            cout<<size<<'\n';
            retVec.push_back(s.substr(curIdx, size));
            curIdx += size;
        }


        return retVec;
    }
};
