class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //idx, temperature
        vector<int> answer(temperatures.size(),0);
        stack<pair<int, int>> stk;

        int idx = 0;
        for(auto temp: temperatures){
            while(!stk.empty() && temp>stk.top().second){
                //remove anything less than the current temperature value
                answer[stk.top().first] = idx - stk.top().first;
                stk.pop();
            }
            stk.push({idx, temp});
            ++idx;
        }

        return answer;

    }
};
