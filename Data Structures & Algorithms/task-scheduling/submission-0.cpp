class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto task: tasks){
            freq[task-'A']++;
        }

        priority_queue<int> pq;
        for(auto count: freq){
            if(count){
                pq.push(count);
            }
        }

        int time = 0;
        //count, time when released
        queue<pair<int, int>> waiting;
        while(!pq.empty() || !waiting.empty()){
            ++time;

            if(pq.empty()){
                //everything is in the waiting state 
                time = waiting.front().second;
            }
            else{
                //there are available tasks 
                auto count = pq.top();
                pq.pop();
                if(count-1>0){
                    waiting.push({count-1, time+n});
                }
            }

            if(!waiting.empty() && waiting.front().second==time){
                pq.push(waiting.front().first);
                waiting.pop();
            }
        }

        return time;

    }
};
