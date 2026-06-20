class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;
        for(int i=0; i<temperatures.size(); ++i){
            bool found = false;
            for(int j=i; j<temperatures.size(); ++j){
                if(temperatures[j] > temperatures[i]){
                    cout<<temperatures[j]<<" bigger than " <<temperatures[i]<<"\n";
                    answer.push_back(j-i);
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"nothing found \n";
                answer.push_back(0);                
            }
        }
        // answer.push_back(0);                
        return answer;


    }
};
