class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        //temp, idx
        stack<pair<int, int>> tempStack;
        tempStack.push({temperatures[0], 0});

        for(int i=1; i<temperatures.size(); ++i){
            int curTemperature = temperatures[i];
            //check if the cur temperature is greater than anything on the stack right now 
            while(!tempStack.empty() && tempStack.top().first<curTemperature){
                answer[tempStack.top().second] = i - tempStack.top().second;
                tempStack.pop();
            }
            tempStack.push({temperatures[i], i});
        }
        return answer;

    }
};
