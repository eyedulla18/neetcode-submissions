class KthLargest {
public:

    vector<int> strmSorted;
    int kVal;

    KthLargest(int k, vector<int>& nums) {
        strmSorted = nums;
        sort(strmSorted.begin(), strmSorted.end());
        kVal = k;
    }
    
    int add(int val) {
        strmSorted.push_back(val);
        sort(strmSorted.begin(), strmSorted.end());
        cout<<"size="<<strmSorted.size()<<'\n';
        return strmSorted[strmSorted.size() - kVal];
    }
};
