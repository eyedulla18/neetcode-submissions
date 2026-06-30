class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        

        vector<pair<int, int>> posSpd;
        for(int i=0; i<position.size(); ++i){
            posSpd.push_back({position[i], speed[i]});
        }
        sort(posSpd.begin(), posSpd.end());
        reverse(posSpd.begin(), posSpd.end());


        stack<double> speedStk;
        for(auto posSpdPair: posSpd){
            int pos = posSpdPair.first;
            int spd = posSpdPair.second;

            double remainingTime = (double)(target-pos)/spd;
            // if((target-pos)%spd){
            //     ++remainingTime;
            // }

            cout<<remainingTime<<" ";


            //is the current going to get there before the current group 
            if(speedStk.empty()){
                speedStk.push(remainingTime);
            }
            else if(remainingTime>speedStk.top()){
                speedStk.push(remainingTime);
            }


        }
        return speedStk.size();

        //takes 3, 5, 10, 3 hours
    }
};
