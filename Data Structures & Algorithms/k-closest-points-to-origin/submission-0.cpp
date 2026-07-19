class Solution {
public:

    double distance(int x, int y){
        return sqrt((x*x)+(y*y));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(auto pointVec: points){
            pq.push({distance(pointVec[0], pointVec[1]), pointVec});
        }

        vector<vector<int>> answer;
        while(pq.size()>k){
            pq.pop();
        }
        while(!pq.empty()){
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};
