#include <ranges>
class Solution {
public:

    const std::string delim = "eashan";

    string encode(vector<string>& strs) {
        // string encoded = "";
        // for(const auto& str: strs){
        //     encoded += str;
        //     encoded += delim;
        // }
        // return encoded;
        strs.push_back("");
        std::string encoded = strs | std::ranges::views::join_with(delim) | std::ranges::to<std::string>();;
        return encoded;

    }

    vector<string> decode(string s) {
        auto decodedRange = s | std::ranges::views::split(delim);
        vector<string> decoded;
        for(auto split: decodedRange){
            std::string converted = std::ranges::to<std::string>(split);
            decoded.push_back(converted);
        }
        if(!decoded.empty()){
            decoded.pop_back();            
        }
        return decoded;

    }
};
