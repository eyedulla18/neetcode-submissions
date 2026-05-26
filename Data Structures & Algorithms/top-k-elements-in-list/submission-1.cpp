class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      //construct a map of value to frequency 
      // sort the pairs 

    unordered_map<int, int> freqUmp;
    for(const auto& num: nums){
        if(freqUmp.find(num)!=freqUmp.end()){
            freqUmp[num]+=1;
        }
        else{
            freqUmp[num]=1;
        }
    }

    vector<pair<int, int>> freqPairVector;
    for(auto freqPair: freqUmp){
        freqPairVector.push_back(freqPair);
    }
    sort(freqPairVector.begin(), freqPairVector.end(), [](const pair<int, int>& fpa, const pair<int, int>& fpb){
        if(fpa.second > fpb.second){
            return true;
        }
        return false;
    });
    
    vector<int> returnVec;
    for(int i=0; i<k; ++i){
        returnVec.push_back(freqPairVector[i].first);
    }

    return returnVec;

    }
};
