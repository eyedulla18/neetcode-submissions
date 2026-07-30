class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //always pick the highest frequency character first

        unordered_map<char, int> freqUmp;
        for(char task: tasks){
            if(freqUmp.find(task)==freqUmp.end()){
                freqUmp[task] = 1;
            }
            else{
                freqUmp[task]++;
            }
        }

        //last used time, freq
        priority_queue<pair<int, int>> pq;
        for(auto freqPair: freqUmp){
            char freq = freqPair.second;
            pq.push({freq, -1});
        }

        int curCycle = 0;
        queue<pair<int, int>> waiting;
        while(!pq.empty() || !waiting.empty()){ //there are remaining tasks 
            ++curCycle;
            //check if the front of waiting is ready to be put back in 
            //the pq again 
            if(!waiting.empty() && curCycle - waiting.front().second>n){
                pq.push(waiting.front());
                waiting.pop();
            }


            if(!pq.empty()){
                auto top = pq.top();
                pq.pop();
                int lastUsed = top.second;
                int freq = top.first;

                if(curCycle-lastUsed>n || lastUsed==-1){
                    if(freq-1>0){
                        waiting.push({freq-1, curCycle});
                    }
                }
                else{
                    //i dont know if this state shoudl ever be reaches 
                    cout<<"uncertain state \n";
                }
            }

        }


        return curCycle;



    }
};
