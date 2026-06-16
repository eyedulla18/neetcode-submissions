class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;

        int answer = 0;
        while(l<r){
            answer = max(answer, min(heights[l], heights[r])*(r-l));
            if(heights[r]<heights[l]){
                --r;
            }
            else{
                ++l;
            }
        }

        return answer;
    }
};
