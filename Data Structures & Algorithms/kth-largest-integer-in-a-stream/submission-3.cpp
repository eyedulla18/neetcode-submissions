class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int kVal;

    KthLargest(int k, vector<int>& nums) {
        kVal = k;
        for(auto num: nums){
            pq.push(num);
        }
        while(pq.size()>k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        cout<<pq.size()<<'\n';
        if(pq.size()>kVal){
            pq.pop();
        }
        return pq.top();
    }
};

// ["KthLargest", [3, [4, 5, 8, 2]], "add", [3], "add", [5], "add", [10], "add", [9], "add", [4]]

// 4,5,8 <- start
// 4,5,8
// 5,5,8
// 5,8,10
// 8,9,10
// 8,9,10




