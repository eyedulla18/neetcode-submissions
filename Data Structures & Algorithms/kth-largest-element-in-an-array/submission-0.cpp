class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto num: nums){
            pq.push(num);
            if(pq.size()>nums.size()-k+1){
                pq.pop();
            }
        }
        return pq.top();
    }
};

// nums=[2,3,1,5,4]
// 5,4,3,2,1
// k=2
