class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> answer;

        for(int i=0; i<nums.size(); ++i){
            //purge all of the indexes that are outside of the window
            while(!window.empty() && window.front()<=i-k){
                window.pop_front();
            } 

            //loop through everything that came before
            //if its less than the current then pop it off
            while(!window.empty() && nums[window.back()]<=nums[i]){
                window.pop_back();
            }

            //the window is always decreasing now 
            //the window starts with the smallest idx and only increases
            window.push_back(i);
            if(i>=k-1){
                answer.push_back(nums[window.front()]);
            }
            // cout<<"window size: "<<window.size()<<'\n';
        }
        return answer;

    }
};
