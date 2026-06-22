class Solution {
public:

    pair<int, int> positionToCoord(int num, vector<vector<int>>& matrix){
        int numCols = matrix[0].size();
        //eg. 6(value 12) is 1,2
        //x = 6/4(numCols) = 1.5 = 1
        //y = 6%4 = 2

        return {num/numCols, num%numCols};

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numCols = matrix[0].size();
        int numRows = matrix.size();
        int l = 0;
        int r = numCols * numRows - 1;

        while(l<=r){
            int mid = (l+r)/2;
            auto midCoord = positionToCoord(mid, matrix);
            int midVal = matrix[midCoord.first][midCoord.second];
            if(midVal==target){
                return true;
            }
            else if(midVal<target){
                l = mid + 1;
            }
            else if(midVal>target){
                r = mid -1;
            }
        }
        return false;
    }
};
